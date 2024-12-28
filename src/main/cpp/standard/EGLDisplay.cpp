//
// Created on 2024/12/28.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#include "EGLDisplay.h"
#include "EGLConfig.h"
#include "EGLContext.h"
#include "EGLSurface.h"
#include "Ptr.h"
#include "utils.h"
#include <EGL/egl.h>
napi_ref StandardEGLDisplay::cons = nullptr;
napi_value StandardEGLDisplay::JSConstructor(napi_env env, napi_callback_info info) {
    napi_value _this = nullptr;
    napi_get_cb_info(env, info, nullptr, nullptr, &_this, nullptr);
    return _this;
}
napi_value StandardEGLDisplay::JSGetDisplay(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value argv[1]{nullptr};
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    EGLNativeDisplayType display_id = EGL_DEFAULT_DISPLAY;
    if (argc == 1) {
        display_id = static_cast<EGLNativeDisplayType>(Ptr::NapiGetPtr(env, argv[0]));
    }

    EGLDisplay display = eglGetDisplay(display_id);
    if (display == nullptr)
        return nullptr;

    return CreateEGLDisplay(env, display);
}

napi_value StandardEGLDisplay::JSGetCurrentDisplay(napi_env env, napi_callback_info info) {
    EGLDisplay display = eglGetCurrentDisplay();
    if (display == nullptr)
        return nullptr;
    return CreateEGLDisplay(env, display);
}

napi_value StandardEGLDisplay::JSGetPlatformDisplay(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value argv[3]{nullptr};
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    EGLenum platform = 0;
    napi_get_value_uint32(env, argv[0], &platform);
    void *native_display = Ptr::NapiGetPtr(env, argv[1]);
    EGLAttrib *attrib_list = getEGLAttribList(env, argv[2]);
    EGLDisplay display = eglGetPlatformDisplay(platform, native_display, attrib_list);
    freeEGLAttribList(&attrib_list);
    if (display == nullptr)
        return nullptr;
    return CreateEGLDisplay(env, display);
}

napi_value StandardEGLDisplay::JSTerminate(napi_env env, napi_callback_info info) {
    EGLDisplay display = GetEGLDisplay(env, info);
    return NapiCreateInt32(env, eglTerminate(display));
}

napi_value StandardEGLDisplay::JSInitialize(napi_env env, napi_callback_info info) {
    EGLDisplay display = GetEGLDisplay(env, info);
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

napi_value StandardEGLDisplay::JSChooseConfig(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value argv[2]{nullptr};
    napi_value _this = nullptr;
    napi_get_cb_info(env, info, &argc, argv, &_this, nullptr);
    EGLDisplay display = GetEGLDisplay(env, _this);
    EGLint *attrib_list = getEGLintList(env, argv[0]);
    napi_valuetype type;
    napi_typeof(env, argv[1], &type);
    uint32_t count = 1;
    if (type == napi_number) {
        napi_get_value_uint32(env, argv[1], &count);
    }

    EGLConfig *configs = nullptr;
    EGLint num_config = 0;
    if (!eglChooseConfig(display, attrib_list, configs, count, &num_config)) {
        return nullptr;
    }
    return StandardEGLConfig::CreateEGLConfigList(env, configs, num_config);
}

napi_value StandardEGLDisplay::JSCreateContext(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value argv[3]{nullptr};
    napi_value _this = nullptr;
    napi_get_cb_info(env, info, &argc, argv, &_this, nullptr);
    EGLDisplay display = GetEGLDisplay(env, _this);
    EGLConfig config = StandardEGLConfig::GetEGLConfig(env, argv[0]);
    EGLContext share_context = StandardEGLContext::GetEGLContext(env, argv[1]);
    EGLint *attrib_list = getEGLintList(env, argv[2]);
    EGLContext context = eglCreateContext(display, config, share_context, attrib_list);
    freeEGLIntList(&attrib_list);
    if (context == nullptr)
        return nullptr;
    return StandardEGLContext::CreateEGLContext(env, context);
}
napi_value StandardEGLDisplay::JSCreateWindowSurface(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value argv[3]{nullptr};
    napi_value _this = nullptr;
    napi_get_cb_info(env, info, &argc, argv, &_this, nullptr);
    EGLDisplay display = GetEGLDisplay(env, _this);
    EGLConfig config = StandardEGLConfig::GetEGLConfig(env, argv[0]);
    void *win = getNativeWindow(env, argv[1]);
    EGLint *attrib_list = getEGLintList(env, argv[2]);
    EGLSurface surface = eglCreateWindowSurface(display, config, static_cast<EGLNativeWindowType>(win), attrib_list);
    freeEGLIntList(&attrib_list);
    return StandardEGLSurface::CreateEGLSurface(env, surface);
}
napi_value StandardEGLDisplay::JSMakeCurrent(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value argv[3]{nullptr};
    napi_value _this = nullptr;
    napi_get_cb_info(env, info, &argc, argv, &_this, nullptr);
    EGLDisplay dpy = GetEGLDisplay(env, _this);
    EGLSurface draw = StandardEGLSurface::GetEGLSurface(env, argv[0]);
    EGLSurface read = StandardEGLSurface::GetEGLSurface(env, argv[1]);
    EGLContext context = StandardEGLContext::GetEGLContext(env, argv[2]);
    return NapiCreateInt32(env, eglMakeCurrent(dpy, draw, read, context));
}
napi_value StandardEGLDisplay::JSCreatePbufferSurface(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value argv[2]{nullptr};
    napi_value _this = nullptr;
    napi_get_cb_info(env, info, &argc, argv, &_this, nullptr);
    EGLDisplay display = GetEGLDisplay(env, _this);
    EGLConfig config = StandardEGLConfig::GetEGLConfig(env, argv[0]);
    EGLint *attrib_list = getEGLintList(env, argv[1]);
    EGLSurface surface = eglCreatePbufferSurface(display, config, attrib_list);
    freeEGLIntList(&attrib_list);
    return StandardEGLSurface::CreateEGLSurface(env, surface);
}
napi_value StandardEGLDisplay::JSDestroyContext(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value argv[1]{nullptr};
    napi_value _this = nullptr;
    napi_get_cb_info(env, info, &argc, argv, &_this, nullptr);
    EGLDisplay dpy = GetEGLDisplay(env, _this);
    EGLContext ctx = StandardEGLContext::GetEGLContext(env, argv[0]);
    return NapiCreateInt32(env, eglDestroyContext(dpy, ctx));
}
napi_value StandardEGLDisplay::JSDestroySurface(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value argv[1]{nullptr};
    napi_value _this = nullptr;
    napi_get_cb_info(env, info, &argc, argv, &_this, nullptr);
    EGLDisplay dpy = GetEGLDisplay(env, _this);
    EGLSurface surface = StandardEGLSurface::GetEGLSurface(env, argv[0]);
    return NapiCreateInt32(env, eglDestroySurface(dpy, surface));
}
napi_value StandardEGLDisplay::JSGetConfigs(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value argv[1]{nullptr};
    napi_value _this = nullptr;
    napi_get_cb_info(env, info, &argc, argv, &_this, nullptr);
    EGLDisplay dpy = GetEGLDisplay(env, _this);
    EGLConfig *configs = nullptr;
    EGLint num_config = 0;
    EGLint config_size = 0;
    napi_get_value_int32(env, argv[0], &config_size);
    if (!eglGetConfigs(dpy, configs, config_size, &num_config))
        return nullptr;

    return StandardEGLConfig::CreateEGLConfigList(env, configs, num_config);
}
napi_value StandardEGLDisplay::JSQueryString(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value argv[1]{nullptr};
    napi_value _this = nullptr;
    napi_get_cb_info(env, info, &argc, argv, &_this, nullptr);
    EGLDisplay dpy = GetEGLDisplay(env, _this);
    EGLint name = 0;
    napi_get_value_int32(env, argv[0], &name);
    const char *str = eglQueryString(dpy, name);
    napi_value result = nullptr;
    napi_create_string_utf8(env, str, NAPI_AUTO_LENGTH, &result);
    return result;
}
napi_value StandardEGLDisplay::JSSwapBuffers(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value argv[1]{nullptr};
    napi_value _this = nullptr;
    napi_get_cb_info(env, info, &argc, argv, &_this, nullptr);
    EGLDisplay dpy = GetEGLDisplay(env, _this);
    EGLSurface surface = StandardEGLSurface::GetEGLSurface(env, argv[0]);
    return NapiCreateInt32(env, eglSwapBuffers(dpy, surface));
}
napi_value StandardEGLDisplay::JSCreateSync(napi_env env, napi_callback_info info) {return nullptr;}
napi_value StandardEGLDisplay::JSDestroySync(napi_env env, napi_callback_info info) {return nullptr;}
napi_value StandardEGLDisplay::JSClientWaitSync(napi_env env, napi_callback_info info) {return nullptr;}
napi_value StandardEGLDisplay::JSWaitSync(napi_env env, napi_callback_info info) {return nullptr;}
napi_value StandardEGLDisplay::JSGetSyncAttrib(napi_env env, napi_callback_info info) {return nullptr;}
napi_value StandardEGLDisplay::JSSwapInterval(napi_env env, napi_callback_info info) {return nullptr;}

napi_value StandardEGLDisplay::CreateEGLDisplay(napi_env env, EGLDisplay display) {
    napi_value _con = nullptr;
    napi_get_reference_value(env, cons, &_con);
    napi_value instance = nullptr;
    napi_new_instance(env, _con, 0, nullptr, &instance);
    if (instance == nullptr) {
        napi_throw_error(env, "EGLDisplay", "create new instance failed");
        return nullptr;
    }

    if (napi_ok != napi_wrap_sendable(env, instance, display, nullptr, nullptr)) {
        napi_throw_error(env, "EGLDisplay", "napi_wrap_sendable failed");
        return nullptr;
    }

    return instance;
}

EGLDisplay StandardEGLDisplay::GetEGLDisplay(napi_env env, napi_value value) {
    void *result = nullptr;
    if (napi_ok != napi_unwrap_sendable(env, value, &result)) {
        napi_throw_error(env, "EGLDisplay", "napi_unwrap_sendable failed");
        return nullptr;
    }
    if (result == nullptr) {
        napi_throw_error(env, "EGLDisplay", "egldislay is null pointer");
        return nullptr;
    }
    return static_cast<EGLDisplay>(result);
}

EGLDisplay StandardEGLDisplay::GetEGLDisplay(napi_env env, napi_callback_info info) {
    napi_value _this = nullptr;
    if (napi_ok != napi_get_cb_info(env, info, nullptr, nullptr, &_this, nullptr)) {
        napi_throw_error(env, "EGLDisplay", "napi_get_cb_info failed");
        return nullptr;
    }
    return GetEGLDisplay(env, _this);
}
