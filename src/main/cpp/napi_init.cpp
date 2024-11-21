#include "NativeUtils.hpp"
#include "egl/EGLHelper.h"
#include "napi/native_api.h"


EXTERN_C_START
static napi_value Init(napi_env env, napi_value exports) {
    EGL::Export(env, exports);
    NativeUtils::Export(env, exports);


    napi_property_descriptor desc[] = {
        {"eglChooseConfig", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglCopyBuffers", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglCreateContext", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglCreatePbufferSurface", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglCreatePixmapSurface", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglCreateWindowSurface", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglDestroyContext", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglDestroySurface", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglGetConfigAttrib", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglGetConfigs", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglGetCurrentDisplay", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglGetCurrentSurface", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglGetDisplay", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglGetError", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglGetProcAddress", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglInitialize", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglMakeCurrent", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglQueryContext", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglQueryString", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglQuerySurface", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglSwapBuffers", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglTerminate", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglWaitGL", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglWaitNative", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglBindTexImage", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglReleaseTexImage", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglSurfaceAttrib", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglSwapInterval", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglBindAPI", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglQueryAPI", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglCreatePbufferFromClientBuffer", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglReleaseThread", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglWaitClient", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglGetCurrentContext", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglCreateSync", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglDestroySync", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglClientWaitSync", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglGetSyncAttrib", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglCreateImage", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglDestroyImage", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglGetPlatformDisplay", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglCreatePlatformWindowSurface", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglCreatePlatformPixmapSurface", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglWaitSync", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglCreatePlatformWindowSurfaceEXT", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglCreatePlatformPixmapSurfaceEXT", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglSwapBuffersWithDamageEXT", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},

        {"getWindowFromSurfaceId", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},

    };

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
