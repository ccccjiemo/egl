#include "NativeUtils.hpp"
#include "egl/EGLHelper.h"
#include "napi/native_api.h"
#include "nativebuffer/NativeBuffer.h"


EXTERN_C_START
static napi_value Init(napi_env env, napi_value exports) {


    napi_property_descriptor desc[] = {
        {"eglChooseConfig", nullptr, EGL::NapiEGLChooseConfig, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglCopyBuffers", nullptr, EGL::NapiEGLCopyBuffers, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglCreateContext", nullptr, EGL::NapiEGLCreateContext, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglCreatePbufferSurface", nullptr, EGL::NapiEGLCreatePbufferSurface, nullptr, nullptr, nullptr, napi_default,
         nullptr},
        {"eglCreatePixmapSurface", nullptr, EGL::NapiEGLCreatePixmapSurface, nullptr, nullptr, nullptr, napi_default,
         nullptr},
        {"eglCreateWindowSurface", nullptr, EGL::NapiEGLCreateWindowSurface, nullptr, nullptr, nullptr, napi_default,
         nullptr},
        {"eglDestroyContext", nullptr, EGL::NapiEGLDestroyContext, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglDestroySurface", nullptr, EGL::NapiEGLDestroySurface, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglGetConfigAttrib", nullptr, EGL::NapiEGLGetConfigAttrib, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglGetConfigs", nullptr, EGL::NapiEGLGetConfigs, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglGetCurrentDisplay", nullptr, EGL::NapiEGLGetCurrentDisplay, nullptr, nullptr, nullptr, napi_default,
         nullptr},
        {"eglGetCurrentSurface", nullptr, EGL::NapiEGLGetCurrentSurface, nullptr, nullptr, nullptr, napi_default,
         nullptr},
        {"eglGetDisplay", nullptr, EGL::NapiEGLGetDisplay, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglGetError", nullptr, EGL::NapiEGLGetError, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglGetProcAddress", nullptr, EGL::NapiEGLGetProcAddress, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglInitialize", nullptr, EGL::NapiEGLInitialize, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglMakeCurrent", nullptr, EGL::NapiEGLMakeCurrent, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglQueryContext", nullptr, EGL::NapiEGLQueryContext, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglQueryString", nullptr, EGL::NapiEGLQueryString, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglQuerySurface", nullptr, EGL::NapiEGLQuerySurface, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglSwapBuffers", nullptr, EGL::NapiEGLSwapBuffers, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglTerminate", nullptr, EGL::NapiEGLTerminate, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglWaitGL", nullptr, EGL::NapiEGLWaitGL, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglWaitNative", nullptr, EGL::NapiEGLWaitNative, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglBindTexImage", nullptr, EGL::NapiEGLBindTexImage, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglReleaseTexImage", nullptr, EGL::NapiEGLReleaseTexImage, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglSurfaceAttrib", nullptr, EGL::NapiEGLSurfaceAttrib, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglSwapInterval", nullptr, EGL::NapiEGLSwapInterval, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglBindAPI", nullptr, EGL::NapiEGLBindAPI, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglQueryAPI", nullptr, EGL::NapiEGLQueryAPI, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglCreatePbufferFromClientBuffer", nullptr, EGL::NapiEGLCreatePbufferFromClientBuffer, nullptr, nullptr,
         nullptr, napi_default, nullptr},
        {"eglReleaseThread", nullptr, EGL::NapiEGLReleaseThread, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglWaitClient", nullptr, EGL::NapiEGLWaitClient, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglGetCurrentContext", nullptr, EGL::NapiEGLGetCurrentContext, nullptr, nullptr, nullptr, napi_default,
         nullptr},
        {"eglCreateSync", nullptr, EGL::NapiEGLCreateSync, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglDestroySync", nullptr, EGL::NapiEGLDestroySync, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglClientWaitSync", nullptr, EGL::NapiEGLClientWaitSync, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglGetSyncAttrib", nullptr, EGL::NapiEGLGetSyncAttrib, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglCreateImage", nullptr, EGL::NapiEGLCreateImage, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglDestroyImage", nullptr, EGL::NapiEGLDestroyImage, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglGetPlatformDisplay", nullptr, EGL::NapiEGLGetPlatformDisplay, nullptr, nullptr, nullptr, napi_default,
         nullptr},
        {"eglCreatePlatformWindowSurface", nullptr, EGL::NapiEGLCreatePlatformWindowSurface, nullptr, nullptr, nullptr,
         napi_default, nullptr},
        {"eglCreatePlatformPixmapSurface", nullptr, EGL::NapiEGLCreatePlatformPixmapSurface, nullptr, nullptr, nullptr,
         napi_default, nullptr},
        {"eglWaitSync", nullptr, EGL::NapiEGLWaitSync, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglCreatePlatformWindowSurfaceEXT", nullptr, EGL::NapiEGLCreatePlatformWindowSurfaceEXT, nullptr, nullptr,
         nullptr, napi_default, nullptr},
        {"eglCreatePlatformPixmapSurfaceEXT", nullptr, EGL::NapiEGLCreatePlatformPixmapSurfaceEXT, nullptr, nullptr,
         nullptr, napi_default, nullptr},
        {"eglSwapBuffersWithDamageEXT", nullptr, EGL::NapiEGLSwapBuffersWithDamageEXT, nullptr, nullptr, nullptr,
         napi_default, nullptr},
        {"eglCreateImageKHR", nullptr, EGL::NapiEGLCreateImageKHR, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglDestroyImageKHR", nullptr, EGL::NapiEGLDestroyImageKHR, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"createNativeBuffer", nullptr, NativeBuffer::NapiCreateNativeBuffer, nullptr, nullptr, nullptr, napi_default,
         nullptr},
        {"releaseNativeBuffer", nullptr, NativeBuffer::NapiReleaseNativeBuffer, nullptr, nullptr, nullptr, napi_default,
         nullptr}};

    napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);

    return exports;
}
EXTERN_C_END

static napi_module demoModule = {
    .nm_version = 1,
    .nm_flags = 0,
    .nm_filename = nullptr,
    .nm_register_func = Init,
    .nm_modname = "egl",
    .nm_priv = ((void *)0),
    .reserved = {0},
};

extern "C" __attribute__((constructor)) void RegisterEglModule(void) { napi_module_register(&demoModule); }
