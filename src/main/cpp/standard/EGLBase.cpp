//
// Created on 2024/12/29.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#include "EGLBase.h"
#include "EGLDisplay.h"
#include "EGLConfig.h"
#include "EGLImage.h"
#include "EGLImageKHR.h"
#include "EGLSurface.h"
#include "EGLContext.h"
#include "EGLSync.h"
#include "EGLSyncKHR.h"
#include "Ptr.h"
#include "utils.h"
#include <EGL/egl.h>
#include <EGL/eglext.h>
#include <multimedia/image_framework/image/pixelmap_native.h>

namespace EGLBase {

napi_value JSEGLGetDisplay(napi_env env, napi_value display_id) {
    void *id = Ptr::NapiGetPtr(env, display_id);
    EGLDisplay display = eglGetDisplay(static_cast<EGLNativeDisplayType>(id));
    return StandardEGLDisplay::CreateEGLDisplay(env, display);
}
napi_value JSEGLInitialize(napi_env env, napi_value dpy) {
    EGLDisplay display = StandardEGLDisplay::GetEGLDisplay(env, dpy);
    EGLint major = 0, minor = 0;
    if (eglInitialize(display, &major, &minor)) {
        napi_value result = nullptr;
        napi_create_object(env, &result);
        napi_set_named_property(env, result, "major", NapiCreateInt32(env, major));
        napi_set_named_property(env, result, "minor", NapiCreateInt32(env, minor));
        return result;
    } else {
        return nullptr;
    }
}
napi_value JSEGLChooseConfig(napi_env env, napi_value dpy, napi_value attrib_list, napi_value config_size) {
    EGLDisplay display = StandardEGLDisplay::GetEGLDisplay(env, dpy);
    EGLint *attrib_list_ = getEGLintList(env, attrib_list);
    napi_valuetype type;
    napi_typeof(env, config_size, &type);
    uint32_t count = 1;
    if (type == napi_number) {
        napi_get_value_uint32(env, config_size, &count);
    }

    EGLConfig *configs = nullptr;
    EGLint num_config = 0;
    if (!eglChooseConfig(display, attrib_list_, configs, count, &num_config)) {
        freeEGLIntList(&attrib_list_);
        return nullptr;
    }
    freeEGLIntList(&attrib_list_);
    return StandardEGLConfig::CreateEGLConfigList(env, configs, num_config);
}
napi_value JSEGLGetError(napi_env env) { return NapiCreateInt32(env, eglGetError()); }
napi_value JSEGLCreateWindowSurface(napi_env env, napi_value dpy, napi_value config, napi_value surfaceId,
                                    napi_value attrib_list) {

    EGLDisplay display = StandardEGLDisplay::GetEGLDisplay(env, dpy);
    EGLConfig config_ = StandardEGLConfig::GetEGLConfig(env, config);
    void *win = getNativeWindow(env, surfaceId);
    EGLint *attrib_list_ = getEGLintList(env, attrib_list);
    EGLSurface surface = eglCreateWindowSurface(display, config_, static_cast<EGLNativeWindowType>(win), attrib_list_);
    freeEGLIntList(&attrib_list_);
    return StandardEGLSurface::CreateEGLSurface(env, surface);
}
napi_value JSEGLMakeCurrent(napi_env env, napi_value dpy, napi_value surface_draw, napi_value surface_read,
                            napi_value ctx) {
    EGLDisplay display = StandardEGLDisplay::GetEGLDisplay(env, dpy);
    EGLSurface draw = StandardEGLSurface::GetEGLSurface(env, surface_draw);
    EGLSurface read = StandardEGLSurface::GetEGLSurface(env, surface_read);
    EGLContext context = StandardEGLContext::GetEGLContext(env, ctx);
    return NapiCreateBoolean(env, eglMakeCurrent(dpy, draw, read, context));
}
napi_value JSEGLCreatePbufferSurface(napi_env env, napi_value dpy, napi_value config, napi_value attrib_list) {
    EGLDisplay display = StandardEGLDisplay::GetEGLDisplay(env, dpy);
    EGLConfig config_ = StandardEGLConfig::GetEGLConfig(env, config);
    EGLint *attrib_list_ = getEGLintList(env, attrib_list);
    EGLSurface surface = eglCreatePbufferSurface(display, config_, attrib_list_);
    freeEGLIntList(&attrib_list_);
    return StandardEGLSurface::CreateEGLSurface(env, surface);
}
napi_value JSEGLDestroyContext(napi_env env, napi_value dpy, napi_value context) {
    EGLDisplay display = StandardEGLDisplay::GetEGLDisplay(env, dpy);
    EGLContext ctx = StandardEGLContext::GetEGLContext(env, context);
    return NapiCreateBoolean(env, eglDestroyContext(display, ctx));
}
napi_value JSEGLDestroySurface(napi_env env, napi_value dpy, napi_value surface) {
    EGLDisplay display = StandardEGLDisplay::GetEGLDisplay(env, dpy);
    EGLSurface surface_ = StandardEGLSurface::GetEGLSurface(env, surface);
    return NapiCreateBoolean(env, eglDestroySurface(display, surface_));
}
napi_value JSEGLGetConfigAttrib(napi_env env, napi_value dpy, napi_value config, napi_value attribute) {
    EGLDisplay display = StandardEGLDisplay::GetEGLDisplay(env, dpy);
    EGLConfig config_ = StandardEGLConfig::GetEGLConfig(env, config);
    EGLint attribute_ = 0, value = 0;
    napi_get_value_int32(env, attribute, &attribute_);
    if (!eglGetConfigAttrib(display, config_, attribute_, &value)) {
        return nullptr;
    }
    return NapiCreateInt32(env, value);
}
napi_value JSEGLGetConfigs(napi_env env, napi_value dpy, napi_value config_size) {
    EGLDisplay display = StandardEGLDisplay::GetEGLDisplay(env, dpy);
    EGLConfig *configs = nullptr;
    EGLint num_config = 0;
    EGLint config_size_ = 0;
    napi_get_value_int32(env, config_size, &config_size_);
    if (!eglGetConfigs(display, configs, config_size_, &num_config))
        return nullptr;

    return StandardEGLConfig::CreateEGLConfigList(env, configs, num_config);
}
napi_value JSEGLGetCurrentDisplay(napi_env env) {
    EGLDisplay display = eglGetCurrentDisplay();
    return StandardEGLDisplay::CreateEGLDisplay(env, display);
}
napi_value JSEGLGetCurrentSurface(napi_env env, napi_value readdraw) {
    EGLint readdraw_ = 0;
    napi_get_value_int32(env, readdraw, &readdraw_);
    EGLSurface surface = eglGetCurrentSurface(readdraw_);
    return StandardEGLSurface::CreateEGLSurface(env, surface);
}
napi_value JSEGLGetProcAddress(napi_env env, napi_value procName) {
    size_t size = 0;
    napi_get_value_string_utf8(env, procName, nullptr, 0, &size);
    char *name = new char[size + 1]{'\0'};
    napi_get_value_string_utf8(env, procName, name, size + 1, nullptr);
    void (*proc)() = eglGetProcAddress(name);
    delete[] name;
    return Ptr::NapiCreatePtr(env, static_cast<void *>(&proc));
}
napi_value JSEGLQueryContext(napi_env env, napi_value dpy, napi_value context, napi_value attribute) {
    EGLDisplay display = StandardEGLDisplay::GetEGLDisplay(env, dpy);
    EGLContext context_ = StandardEGLContext::GetEGLContext(env, context);
    EGLint attribute_ = 0, value = 0;
    napi_get_value_int32(env, attribute, &attribute_);

    if (!eglQueryContext(display, context_, attribute_, &value)) {
        return nullptr;
    }
    return NapiCreateInt32(env, value);
}
napi_value JSEGLQueryString(napi_env env, napi_value dpy, napi_value name) {
    EGLDisplay display = StandardEGLDisplay::GetEGLDisplay(env, dpy);
    EGLint name_ = 0;
    napi_get_value_int32(env, name, &name_);
    const char *str = eglQueryString(display, name_);
    napi_value result = nullptr;
    napi_create_string_utf8(env, str, NAPI_AUTO_LENGTH, &result);
    return result;
}
napi_value JSEGLQuerySurface(napi_env env, napi_value dpy, napi_value surface, napi_value attribute) {
    EGLDisplay display = StandardEGLDisplay::GetEGLDisplay(env, dpy);
    EGLSurface surface_ = StandardEGLSurface::GetEGLSurface(env, surface);
    EGLint attribute_ = 0, value = 0;
    napi_get_value_int32(env, attribute, &attribute_);
    if (!eglQuerySurface(display, surface_, attribute_, &value))
        return nullptr;
    return NapiCreateInt32(env, value);
}
napi_value JSEGLSwapBuffers(napi_env env, napi_value dpy, napi_value surface) {
    EGLDisplay display = StandardEGLDisplay::GetEGLDisplay(env, dpy);
    EGLSurface surface_ = StandardEGLSurface::GetEGLSurface(env, surface);
    return NapiCreateBoolean(env, eglSwapBuffers(display, surface_));
}
napi_value JSEGLTerminate(napi_env env, napi_value dpy) {
    EGLDisplay display = StandardEGLDisplay::GetEGLDisplay(env, dpy);
    return NapiCreateBoolean(env, eglTerminate(display));
}
napi_value JSEGLWaitGL(napi_env env) { return NapiCreateBoolean(env, eglWaitGL()); }
napi_value JSEGLWaitNative(napi_env env, napi_value engine) {
    EGLint engine_ = 0;
    napi_get_value_int32(env, engine, &engine_);
    return NapiCreateBoolean(env, eglWaitNative(engine_));
}
napi_value JSEGLBindTexImage(napi_env env, napi_value dpy, napi_value surface, napi_value buffer) {
    EGLDisplay display = StandardEGLDisplay::GetEGLDisplay(env, dpy);
    EGLSurface surface_ = StandardEGLSurface::GetEGLSurface(env, surface);
    EGLint buffer_ = 0;
    napi_get_value_int32(env, buffer, &buffer_);
    return NapiCreateBoolean(env, eglBindTexImage(display, surface_, buffer_));
}
napi_value JSEGLReleaseTexImage(napi_env env, napi_value dpy, napi_value surface, napi_value buffer) {
    EGLDisplay display = StandardEGLDisplay::GetEGLDisplay(env, dpy);
    EGLSurface surface_ = StandardEGLSurface::GetEGLSurface(env, surface);
    EGLint buffer_ = 0;
    napi_get_value_int32(env, buffer, &buffer_);
    return NapiCreateBoolean(env, eglReleaseTexImage(display, surface_, buffer_));
}
napi_value JSEGLSurfaceAttrib(napi_env env, napi_value dpy, napi_value surface, napi_value attribute,
                              napi_value value) {
    EGLDisplay display = StandardEGLDisplay::GetEGLDisplay(env, dpy);
    EGLSurface surface_ = StandardEGLSurface::GetEGLSurface(env, surface);
    EGLint attribute_ = 0, value_ = 0;
    napi_get_value_int32(env, attribute, &attribute_);
    napi_get_value_int32(env, value, &value_);
    return NapiCreateBoolean(env, eglSurfaceAttrib(display, surface_, attribute_, value_));
}
napi_value JSEGLSwapInterval(napi_env env, napi_value dpy, napi_value interval) {
    EGLDisplay display = StandardEGLDisplay::GetEGLDisplay(env, dpy);
    EGLint interval_ = getEGLInt(env, interval);
    return NapiCreateBoolean(env, eglSwapInterval(display, interval_));
}
napi_value JSEGLBindAPI(napi_env env, napi_value api) {
    EGLenum api_ = getEGLenum(env, api);
    return NapiCreateBoolean(env, eglBindAPI(api_));
}
napi_value JSEGLQueryAPI(napi_env env) { return NapiCreateEGLenum(env, eglQueryAPI()); }
napi_value JSEGLReleaseThread(napi_env env) { return NapiCreateBoolean(env, eglReleaseThread()); }
napi_value JSEGLWaitClient(napi_env env) { return NapiCreateBoolean(env, eglWaitClient()); }
napi_value JSEGLGetCurrentContext(napi_env env) {
    EGLContext context = eglGetCurrentContext();
    return StandardEGLContext::CreateEGLContext(env, context);
}
napi_value JSEGLCreateSync(napi_env env, napi_value dpy, napi_value type, napi_value attrib_list) {
    EGLDisplay display = StandardEGLDisplay::GetEGLDisplay(env, dpy);
    EGLenum type_ = getEGLenum(env, type);
    EGLAttrib *attrib_list_ = getEGLAttribList(env, attrib_list);
    EGLSync sync = eglCreateSync(display, type_, attrib_list_);
    freeEGLAttribList(&attrib_list_);
    return StandardEGLSync::CreateEGLSync(env, sync);
}
napi_value JSEGLDestroySync(napi_env env, napi_value dpy, napi_value sync) {
    EGLDisplay display = StandardEGLDisplay::GetEGLDisplay(env, dpy);
    EGLSync sync_ = StandardEGLSync::GetEGLSync(env, sync);
    return NapiCreateBoolean(env, eglDestroySync(display, sync_));
}
napi_value JSEGLClientWaitSync(napi_env env, napi_value dpy, napi_value sync, napi_value flags, napi_value timeout) {
    EGLDisplay display = StandardEGLDisplay::GetEGLDisplay(env, dpy);
    EGLSync sync_ = StandardEGLSync::GetEGLSync(env, sync);
    EGLint flags_ = getEGLInt(env, flags);
    EGLTime timeout_ = getEGLTime(env, timeout);
    return NapiCreateInt32(env, eglClientWaitSync(display, sync_, flags_, timeout_));
}
napi_value JSEGLGetSyncAttrib(napi_env env, napi_value dpy, napi_value sync, napi_value attribute) {
    EGLDisplay display = GetSendable<EGLDisplay>(env, dpy);
    EGLSync sync_ = GetSendable<EGLSync>(env, sync);
    EGLint attribute_ = getEGLInt(env, attribute);
    EGLAttrib value = 0;
    if (!eglGetSyncAttrib(display, sync_, attribute_, &value)) {
        return nullptr;
    }
    return NapiCreateEGLAttrib(env, value);
}
napi_value JSEGLDestroyImage(napi_env env, napi_value dpy, napi_value image) {
    EGLDisplay display = GetSendable<EGLDisplay>(env, dpy);
    EGLImage image_ = GetSendable<EGLImage>(env, image);
    return NapiCreateBoolean(env, eglDestroyImage(display, image_));
}
napi_value JSEGLGetPlatformDisplay(napi_env env, napi_value platform, napi_value native_display,
                                   napi_value attrib_list) {
    EGLenum platform_ = getEGLenum(env, platform);
    void *native_display_ = Ptr::NapiGetPtr(env, native_display);
    EGLAttrib *attrib_list_ = getEGLAttribList(env, attrib_list);
    EGLDisplay display = eglGetPlatformDisplay(platform_, native_display_, attrib_list_);
    freeEGLAttribList(&attrib_list_);
    return StandardEGLDisplay::CreateEGLDisplay(env, display);
}
napi_value JSEGLCreatePlatformWindowSurface(napi_env env, napi_value dpy, napi_value config, napi_value native_window,
                                            napi_value attrib_list) {
    EGLDisplay display = GetSendable<EGLDisplay>(env, dpy);
    EGLConfig config_ = GetSendable<EGLConfig>(env, config);
    void *native_window_ = Ptr::NapiGetPtr(env, native_window);
    EGLAttrib *attrib_list_ = getEGLAttribList(env, attrib_list);
    EGLSurface surface = eglCreatePlatformWindowSurface(display, config_, native_window_, attrib_list_);
    freeEGLAttribList(&attrib_list_);
    return StandardEGLSurface::CreateEGLSurface(env, surface);
}
napi_value JSEGLCreatePlatformPixmapSurface(napi_env env, napi_value dpy, napi_value config, napi_value native_pixmap,
                                            napi_value attrib_list) {
    EGLDisplay display = GetSendable<EGLDisplay>(env, dpy);
    EGLConfig config_ = GetSendable<EGLConfig>(env, config);
    void *native_pixmap_ = Ptr::NapiGetPtr(env, native_pixmap);
    EGLAttrib *attrib_list_ = getEGLAttribList(env, attrib_list);
    EGLSurface surface = eglCreatePlatformPixmapSurface(display, config_, native_pixmap_, attrib_list_);
    freeEGLAttribList(&attrib_list_);
    return StandardEGLSurface::CreateEGLSurface(env, surface);
}
napi_value JSEGLWaitSync(napi_env env, napi_value dpy, napi_value sync, napi_value flags) {
    EGLDisplay display = GetSendable<EGLDisplay>(env, dpy);
    EGLSync sync_ = GetSendable<EGLSync>(env, sync);
    EGLint flags_ = getEGLInt(env, flags);
    return NapiCreateBoolean(env, eglWaitSync(display, sync_, flags_));
}
napi_value JSEGLCreatePixmapSurface(napi_env env, napi_value dpy, napi_value config, napi_value pixmap,
                                    napi_value attrib_list) {
    EGLDisplay display = GetSendable<EGLDisplay>(env, dpy);
    EGLConfig config_ = GetSendable<EGLConfig>(env, config);
    OH_PixelmapNative *pixelMap = nullptr;
    EGLint *attrib_list_ = getEGLintList(env, attrib_list);
    OH_PixelmapNative_ConvertPixelmapNativeFromNapi(env, pixmap, &pixelMap);
    EGLSurface surface = eglCreatePixmapSurface(display, config_, pixelMap, attrib_list_);
    freeEGLIntList(&attrib_list_);
    return StandardEGLSurface::CreateEGLSurface(env, surface);
}
napi_value JSEGLCreateImageKHR(napi_env env, napi_value dpy, napi_value context, napi_value target, napi_value buffer,
                               napi_value attrib_list) {
    PFNEGLCREATEIMAGEKHRPROC eglCreateImageKHR_ =
        reinterpret_cast<PFNEGLCREATEIMAGEKHRPROC>(eglGetProcAddress("eglCreteImageKHR"));
    if (eglCreateImageKHR_ == nullptr)
        return nullptr;
    EGLDisplay display = GetSendable<EGLDisplay>(env, dpy);
    EGLContext ctx = GetSendable<EGLConfig>(env, context);
    EGLenum target_ = getEGLenum(env, target);
    OHNativeWindowBuffer *buffer_ = GetSendable<OHNativeWindowBuffer *>(env, buffer);
    EGLint *attrib_list_ = getEGLintList(env, attrib_list);
    EGLImageKHR image = eglCreateImageKHR_(display, ctx, target_, static_cast<EGLClientBuffer>(buffer_), attrib_list_);
    freeEGLIntList(&attrib_list_);
    return StandardEGLImageKHR::CreateEGLImageKHR(env, image);
}
napi_value JSEGLCreateImage(napi_env env, napi_value dpy, napi_value context, napi_value target, napi_value buffer,
                            napi_value attrib_list) {
    EGLDisplay display = GetSendable<EGLDisplay>(env, dpy);
    EGLContext ctx = GetSendable<EGLConfig>(env, context);
    EGLenum target_ = getEGLenum(env, target);
    OHNativeWindowBuffer *buffer_ = GetSendable<OHNativeWindowBuffer *>(env, buffer);
    EGLAttrib *attrib_list_ = getEGLAttribList(env, attrib_list);
    EGLImage image = eglCreateImage(display, ctx, target_, static_cast<EGLClientBuffer>(buffer_), attrib_list_);
    freeEGLAttribList(&attrib_list_);
    return StandardEGLImage::CreateEGLImage(env, image);
}
napi_value JSEGLCreatePbufferFromClientBuffer(napi_env env, napi_value dpy, napi_value buftype, napi_value buffer,
                                              napi_value config, napi_value attrib_list) {
    EGLDisplay display = GetSendable<EGLDisplay>(env, dpy);
    EGLenum buftype_ = getEGLenum(env, buftype);
    OHNativeWindowBuffer *buffer_ = GetSendable<OHNativeWindowBuffer *>(env, buffer);
    EGLConfig config_ = GetSendable<EGLConfig>(env, config);
    EGLint *attrib_list_ = getEGLintList(env, attrib_list);
    EGLSurface surface = eglCreatePbufferFromClientBuffer(display, buftype_, buffer_, config_, attrib_list_);
    return StandardEGLSurface::CreateEGLSurface(env, surface);
}
napi_value JSEGLCopyBuffers(napi_env env, napi_value dpy, napi_value surface, napi_value target) {
    EGLDisplay display = GetSendable<EGLDisplay>(env, dpy);
    EGLSurface surface_ = GetSendable<EGLSurface>(env, surface);
    OH_PixelmapNative *pixelMap = nullptr;
    OH_PixelmapNative_ConvertPixelmapNativeFromNapi(env, target, &pixelMap);
    return NapiCreateBoolean(env, eglCopyBuffers(display, surface_, static_cast<EGLNativePixmapType>(pixelMap)));
}
napi_value JSEGLDestroyImageKHR(napi_env env, napi_value dpy, napi_value image) {
    PFNEGLDESTROYIMAGEKHRPROC eglDestroyImageKHR_ =
        reinterpret_cast<PFNEGLDESTROYIMAGEKHRPROC>(eglGetProcAddress("eglDestroyImageKHR"));
    if (eglDestroyImageKHR_ == nullptr)
        return NapiCreateBoolean(env, false);
    EGLDisplay display = GetSendable<EGLDisplay>(env, dpy);
    EGLImageKHR image_ = GetSendable<EGLImageKHR>(env, image);
    return NapiCreateBoolean(env, eglDestroyImageKHR_(display, image_));
}

napi_value JSEGLCreateSyncKHR(napi_env env, napi_value dpy, napi_value type, napi_value attrib_list) {
    PFNEGLCREATESYNCKHRPROC eglCreateSyncKHR_ =
        reinterpret_cast<PFNEGLCREATESYNCKHRPROC>(eglGetProcAddress("eglCreateSyncKHR"));
    if (eglCreateSyncKHR_ == nullptr)
        return nullptr;
    EGLDisplay display = GetSendable<EGLDisplay>(env, dpy);
    EGLenum type_ = getEGLenum(env, type);
    EGLint *attrib_list_ = getEGLintList(env, attrib_list);
    EGLSyncKHR sync = eglCreateSyncKHR_(display, type_, attrib_list_);
    return StandardEGLSyncKHR::CreateEGLSyncKHR(env, sync);
}

napi_value JSEGLDestroySyncKHR(napi_env env, napi_value dpy, napi_value sync) {
    PFNEGLDESTROYIMAGEKHRPROC eglDestroySyncKHR_ =
        reinterpret_cast<PFNEGLDESTROYIMAGEKHRPROC>(eglGetProcAddress("eglDestroySyncKHR"));
    if (eglDestroySyncKHR_ == nullptr)
        return NapiCreateBoolean(env, false);
    EGLDisplay display = GetSendable<EGLDisplay>(env, dpy);
    EGLSyncKHR sync_ = GetSendable<EGLSyncKHR>(env, sync);
    return NapiCreateBoolean(env, eglDestroySyncKHR_(display, sync_));
}
}