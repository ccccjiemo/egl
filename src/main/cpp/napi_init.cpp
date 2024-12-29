#include "EGLConfig.h"
#include "EGLContext.h"
#include "EGLDisplay.h"
#include "EGLImage.h"
#include "EGLImageKHR.h"
#include "EGLSurface.h"
#include "EGLSync.h"
#include "EGLSyncKHR.h"
#include "NapiEGL.h"
#include "NativeBufferSendable.h"
#include "EGLHelper.h"
#include "napi/native_api.h"
#include "utils.h"

//     napi_value eglConfigCons = nullptr;
//     napi_define_sendable_class(env, "EGLConfig", NAPI_AUTO_LENGTH, StandardEGLConfig::JSConstructor, nullptr,
//                                sizeof(eglConfigDesc) / sizeof(eglConfigDesc[0]), eglConfigDesc, nullptr,
//                                &eglConfigCons);
//     napi_create_reference(env, eglConfigCons, 1, &StandardEGLConfig::cons);
//     napi_set_named_property(env, exports, "EGLConfig", eglConfigCons);

//     napi_value eglDisplayCons = nullptr;
//     napi_define_sendable_class(env, "EGLDisplay", NAPI_AUTO_LENGTH, StandardEGLDisplay::JSConstructor, nullptr,
//                                sizeof(eglDisplayDesc) / sizeof(eglDisplayDesc[0]), eglDisplayDesc, nullptr,
//                                &eglDisplayCons);
//     napi_create_reference(env, eglDisplayCons, 1, &StandardEGLDisplay::cons);
//     napi_set_named_property(env, exports, "EGLDisplay", eglDisplayCons);


EXTERN_C_START
static napi_value Init(napi_env env, napi_value exports) {
    /***
     * define eglDisplay
     */
    napi_property_descriptor eglDisplayDesc[] = {
        DefineFunction("getDisplay", StandardEGLDisplay::JSGetDisplay),
        DefineFunction("getCurrentDisplay", StandardEGLDisplay::JSGetCurrentDisplay),
        DefineFunction("getPlatformDisplay", StandardEGLDisplay::JSGetPlatformDisplay),
        DefineFunction("terminate", StandardEGLDisplay::JSTerminate),
        DefineFunction("initialize", StandardEGLDisplay::JSInitialize),
        DefineFunction("chooseConfig", StandardEGLDisplay::JSChooseConfig),
        DefineFunction("createContext", StandardEGLDisplay::JSCreateContext),
        DefineFunction("createWindowSurface", StandardEGLDisplay::JSCreateWindowSurface),
        DefineFunction("makeCurrent", StandardEGLDisplay::JSMakeCurrent),
        DefineFunction("createPbufferSurface", StandardEGLDisplay::JSCreatePbufferSurface),
        DefineFunction("destroyContext", StandardEGLDisplay::JSDestroyContext),
        DefineFunction("destroySurface", StandardEGLDisplay::JSDestroySurface),
        DefineFunction("getConfigs", StandardEGLDisplay::JSGetConfigs),
        DefineFunction("queryString", StandardEGLDisplay::JSQueryString),
        DefineFunction("swapBuffers", StandardEGLDisplay::JSSwapBuffers),
        DefineFunction("createSync", StandardEGLDisplay::JSCreateSync),
        DefineFunction("destroySync", StandardEGLDisplay::JSDestroySync),
        DefineFunction("clientWaitSync", StandardEGLDisplay::JSClientWaitSync),
        DefineFunction("waitSync", StandardEGLDisplay::JSWaitSync),
        DefineFunction("getSyncAttrib", StandardEGLDisplay::JSGetSyncAttrib),
        DefineFunction("swapInterval", StandardEGLDisplay::JSSwapInterval),
    };

    DefineSendableClass(env, exports, "EGLDisplay", StandardEGLDisplay::JSConstructor, eglDisplayDesc,
                        &StandardEGLDisplay::cons);

    /***
     * define eglConfig
     */
    napi_property_descriptor eglConfigDesc[] = {
        DefineFunction("getConfigAttrib", StandardEGLConfig::JSGetConfigAttrib),
    };
    DefineSendableClass(env, exports, "EGLConfig", StandardEGLConfig::JSConstructor, eglConfigDesc,
                        &StandardEGLConfig::cons);

    /***
     * define eglContext
     */
    napi_property_descriptor eglContextDesc[] = {
        DefineFunction("getCurrentContext", StandardEGLContext::JSGetCurrentContext),
        DefineFunction("query", StandardEGLContext::JSQuery),
    };
    DefineSendableClass(env, exports, "EGLContext", StandardEGLContext::JSConstructor, eglContextDesc,
                        &StandardEGLContext::cons);

    /***
     * define eglSurface
     */
    napi_property_descriptor eglSurfaceDesc[] = {
        DefineFunction("getCurrentSurface", StandardEGLSurface::JSGetCurrentSurface),
        DefineFunction("setAttribute", StandardEGLSurface::JSSetAttribute),
        DefineFunction("query", StandardEGLSurface::JSQuery),
        DefineFunction("bindTexImage", StandardEGLSurface::JSBindTexImage),
        DefineFunction("releaseTexImage", StandardEGLSurface::JSReleaseTexImage),
    };
    DefineSendableClass(env, exports, "EGLSurface", StandardEGLSurface::JSConstructor, eglSurfaceDesc,
                        &StandardEGLSurface::cons);

    /**
     * define eglImage
     */
    DefineSendableClassWithSize(env, exports, "EGLImage", StandardEGLImage::JSConstructor, nullptr, 0,
                                &StandardEGLImage::cons);
    /**
     * define eglImageKHR
     */
    DefineSendableClassWithSize(env, exports, "EGLImageKHR", StandardEGLImageKHR::JSConstructor, nullptr, 0,
                                &StandardEGLImageKHR::cons);

    /***
     * define eglSync
     */
    DefineSendableClassWithSize(env, exports, "EGLSync", StandardEGLSync::JSConstructor, nullptr, 0,
                                &StandardEGLSync::cons);

    /**
     * define eglSyncKHR
     */
    DefineSendableClassWithSize(env, exports, "EGLSyncKHR", StandardEGLSyncKHR::JSConstructor, nullptr, 0,
                                &StandardEGLSyncKHR::cons);

    /**
     * define nativeBuffer
     */
    napi_property_descriptor nativeBufferDesc[] = {
        {"destroy", nullptr, StandardNativeBuffer::JSDestroy, nullptr, nullptr, nullptr, napi_default, nullptr},
    };
    DefineSendableClass(env, exports, "NativeBuffer", StandardNativeBuffer::JSConstructor, nativeBufferDesc,
                        &StandardNativeBuffer::cons);

    /**
     * define global method
     */
//     napi_property_descriptor desc[] = {
//         {"eglChooseConfig", nullptr, EGL::NapiEGLChooseConfig, nullptr, nullptr, nullptr, napi_default, nullptr},
//         {"eglCopyBuffers", nullptr, EGL::NapiEGLCopyBuffers, nullptr, nullptr, nullptr, napi_default, nullptr},
//         {"eglCreateContext", nullptr, EGL::NapiEGLCreateContext, nullptr, nullptr, nullptr, napi_default,
    //         nullptr},
//         {"eglCreatePbufferSurface", nullptr, EGL::NapiEGLCreatePbufferSurface, nullptr, nullptr, nullptr,
    //         napi_default,
//          nullptr},
//         {"eglCreatePixmapSurface", nullptr, EGL::NapiEGLCreatePixmapSurface, nullptr, nullptr, nullptr,
    //         napi_default,
//          nullptr},
//         {"eglCreateWindowSurface", nullptr, EGL::NapiEGLCreateWindowSurface, nullptr, nullptr, nullptr,
    //         napi_default,
//          nullptr},
//         {"eglDestroyContext", nullptr, EGL::NapiEGLDestroyContext, nullptr, nullptr, nullptr, napi_default,
    //         nullptr},
//         {"eglDestroySurface", nullptr, EGL::NapiEGLDestroySurface, nullptr, nullptr, nullptr, napi_default,
    //         nullptr},
//         {"eglGetConfigAttrib", nullptr, EGL::NapiEGLGetConfigAttrib, nullptr, nullptr, nullptr, napi_default,
    //         nullptr},
//         {"eglGetConfigs", nullptr, EGL::NapiEGLGetConfigs, nullptr, nullptr, nullptr, napi_default, nullptr},
//         {"eglGetCurrentDisplay", nullptr, EGL::NapiEGLGetCurrentDisplay, nullptr, nullptr, nullptr, napi_default,
//          nullptr},
//         {"eglGetCurrentSurface", nullptr, EGL::NapiEGLGetCurrentSurface, nullptr, nullptr, nullptr, napi_default,
//          nullptr},
//         {"eglGetDisplay", nullptr, EGL::NapiEGLGetDisplay, nullptr, nullptr, nullptr, napi_default, nullptr},
//         {"eglGetError", nullptr, EGL::NapiEGLGetError, nullptr, nullptr, nullptr, napi_default, nullptr},
//         {"eglGetProcAddress", nullptr, EGL::NapiEGLGetProcAddress, nullptr, nullptr, nullptr, napi_default,
    //         nullptr},
//         {"eglInitialize", nullptr, EGL::NapiEGLInitialize, nullptr, nullptr, nullptr, napi_default, nullptr},
//         {"eglMakeCurrent", nullptr, EGL::NapiEGLMakeCurrent, nullptr, nullptr, nullptr, napi_default, nullptr},
//         {"eglQueryContext", nullptr, EGL::NapiEGLQueryContext, nullptr, nullptr, nullptr, napi_default, nullptr},
//         {"eglQueryString", nullptr, EGL::NapiEGLQueryString, nullptr, nullptr, nullptr, napi_default, nullptr},
//         {"eglQuerySurface", nullptr, EGL::NapiEGLQuerySurface, nullptr, nullptr, nullptr, napi_default, nullptr},
//         {"eglSwapBuffers", nullptr, EGL::NapiEGLSwapBuffers, nullptr, nullptr, nullptr, napi_default, nullptr},
//         {"eglTerminate", nullptr, EGL::NapiEGLTerminate, nullptr, nullptr, nullptr, napi_default, nullptr},
//         {"eglWaitGL", nullptr, EGL::NapiEGLWaitGL, nullptr, nullptr, nullptr, napi_default, nullptr},
//         {"eglWaitNative", nullptr, EGL::NapiEGLWaitNative, nullptr, nullptr, nullptr, napi_default, nullptr},
//         {"eglBindTexImage", nullptr, EGL::NapiEGLBindTexImage, nullptr, nullptr, nullptr, napi_default, nullptr},
//         {"eglReleaseTexImage", nullptr, EGL::NapiEGLReleaseTexImage, nullptr, nullptr, nullptr, napi_default,
    //         nullptr},
//         {"eglSurfaceAttrib", nullptr, EGL::NapiEGLSurfaceAttrib, nullptr, nullptr, nullptr, napi_default,
    //         nullptr},
//         {"eglSwapInterval", nullptr, EGL::NapiEGLSwapInterval, nullptr, nullptr, nullptr, napi_default, nullptr},
//         {"eglBindAPI", nullptr, EGL::NapiEGLBindAPI, nullptr, nullptr, nullptr, napi_default, nullptr},
//         {"eglQueryAPI", nullptr, EGL::NapiEGLQueryAPI, nullptr, nullptr, nullptr, napi_default, nullptr},
//         {"eglCreatePbufferFromClientBuffer", nullptr, EGL::NapiEGLCreatePbufferFromClientBuffer, nullptr,
    //         nullptr,
//          nullptr, napi_default, nullptr},
//         {"eglReleaseThread", nullptr, EGL::NapiEGLReleaseThread, nullptr, nullptr, nullptr, napi_default,
    //         nullptr},
//         {"eglWaitClient", nullptr, EGL::NapiEGLWaitClient, nullptr, nullptr, nullptr, napi_default, nullptr},
//         {"eglGetCurrentContext", nullptr, EGL::NapiEGLGetCurrentContext, nullptr, nullptr, nullptr, napi_default,
//          nullptr},
//         {"eglCreateSync", nullptr, EGL::NapiEGLCreateSync, nullptr, nullptr, nullptr, napi_default, nullptr},
//         {"eglDestroySync", nullptr, EGL::NapiEGLDestroySync, nullptr, nullptr, nullptr, napi_default, nullptr},
//         {"eglClientWaitSync", nullptr, EGL::NapiEGLClientWaitSync, nullptr, nullptr, nullptr, napi_default,
    //         nullptr},
//         {"eglGetSyncAttrib", nullptr, EGL::NapiEGLGetSyncAttrib, nullptr, nullptr, nullptr, napi_default,
    //         nullptr},
//         {"eglCreateImage", nullptr, EGL::NapiEGLCreateImage, nullptr, nullptr, nullptr, napi_default, nullptr},
//         {"eglDestroyImage", nullptr, EGL::NapiEGLDestroyImage, nullptr, nullptr, nullptr, napi_default, nullptr},
//         {"eglGetPlatformDisplay", nullptr, EGL::NapiEGLGetPlatformDisplay, nullptr, nullptr, nullptr,
    //         napi_default,
//          nullptr},
//         {"eglCreatePlatformWindowSurface", nullptr, EGL::NapiEGLCreatePlatformWindowSurface, nullptr, nullptr,
    //         nullptr,
//          napi_default, nullptr},
//         {"eglCreatePlatformPixmapSurface", nullptr, EGL::NapiEGLCreatePlatformPixmapSurface, nullptr, nullptr,
    //         nullptr,
//          napi_default, nullptr},
//         {"eglWaitSync", nullptr, EGL::NapiEGLWaitSync, nullptr, nullptr, nullptr, napi_default, nullptr},
//         {"eglCreatePlatformWindowSurfaceEXT", nullptr, EGL::NapiEGLCreatePlatformWindowSurfaceEXT, nullptr,
    //         nullptr,
//          nullptr, napi_default, nullptr},
//         {"eglCreatePlatformPixmapSurfaceEXT", nullptr, EGL::NapiEGLCreatePlatformPixmapSurfaceEXT, nullptr,
    //         nullptr,
//          nullptr, napi_default, nullptr},
//         {"eglSwapBuffersWithDamageEXT", nullptr, EGL::NapiEGLSwapBuffersWithDamageEXT, nullptr, nullptr, nullptr,
//          napi_default, nullptr},
//         {"eglCreateImageKHR", nullptr, EGL::NapiEGLCreateImageKHR, nullptr, nullptr, nullptr, napi_default,
    //         nullptr},
//         {"eglDestroyImageKHR", nullptr, EGL::NapiEGLDestroyImageKHR, nullptr, nullptr, nullptr, napi_default,
    //         nullptr},
//         {"createNativeBuffer", nullptr, NativeBuffer::NapiCreateNativeBuffer, nullptr, nullptr, nullptr,
    //         napi_default,
//          nullptr},
//         {"releaseNativeBuffer", nullptr, NativeBuffer::NapiReleaseNativeBuffer, nullptr, nullptr, nullptr,
    //         napi_default,
//          nullptr},
    napi_property_descriptor desc[] = {
        DefineFunction("eglGetDisplay", NapiEGL::NapiEGLGetDisplay),
        DefineFunction("eglInitialize", NapiEGL::NapiEGLInitialize),
        DefineFunction("eglChooseConfig", NapiEGL::NapiEGLChooseConfig),
        DefineFunction("eglGetError", NapiEGL::NapiEGLGetError),
        DefineFunction("eglCreateWindowSurface", NapiEGL::NapiEGLCreateWindowSurface),
        DefineFunction("eglMakeCurrent", NapiEGL::NapiEGLMakeCurrent),
        DefineFunction("eglCreatePbufferSurface", NapiEGL::NapiEGLCreatePbufferSurface),
        DefineFunction("eglDestroyContext", NapiEGL::NapiEGLDestroyContext),
        DefineFunction("eglDestroySurface", NapiEGL::NapiEGLDestroySurface),
        DefineFunction("eglGetConfigAttrib", NapiEGL::NapiEGLGetConfigAttrib),
        DefineFunction("eglGetConfigs", NapiEGL::NapiEGLGetConfigs),
        DefineFunction("eglGetCurrentDisplay", NapiEGL::NapiEGLGetCurrentDisplay),
        DefineFunction("eglGetCurrentSurface", NapiEGL::NapiEGLGetCurrentSurface),
        DefineFunction("eglGetProcAddress", NapiEGL::NapiEGLGetProcAddress),
        DefineFunction("eglQueryContext", NapiEGL::NapiEGLQueryContext),
        DefineFunction("eglQueryString", NapiEGL::NapiEGLQueryString),
        DefineFunction("eglQuerySurface", NapiEGL::NapiEGLQuerySurface),
        DefineFunction("eglSwapBuffers", NapiEGL::NapiEGLSwapBuffers),
        DefineFunction("eglTerminate", NapiEGL::NapiEGLTerminate),
        DefineFunction("eglWaitGL", NapiEGL::NapiEGLWaitGL),
        DefineFunction("eglWaitNative", NapiEGL::NapiEGLWaitNative),
        DefineFunction("eglBindTexImage", NapiEGL::NapiEGLBindTexImage),
        DefineFunction("eglReleaseTexImage", NapiEGL::NapiEGLReleaseTexImage),
        DefineFunction("eglSurfaceAttrib", NapiEGL::NapiEGLSurfaceAttrib),
        DefineFunction("eglSwapInterval", NapiEGL::NapiEGLSwapInterval),
        DefineFunction("eglBindAPI", NapiEGL::NapiEGLBindAPI),
        DefineFunction("eglQueryAPI", NapiEGL::NapiEGLQueryAPI),
        DefineFunction("eglReleaseThread", NapiEGL::NapiEGLReleaseThread),
        DefineFunction("eglWaitClient", NapiEGL::NapiEGLWaitClient),
        DefineFunction("eglGetCurrentContext", NapiEGL::NapiEGLGetCurrentContext),
        DefineFunction("eglCreateSync", NapiEGL::NapiEGLCreateSync),
        DefineFunction("eglDestroySync", NapiEGL::NapiEGLDestroySync),
        DefineFunction("eglClientWaitSync", NapiEGL::NapiEGLClientWaitSync),
        DefineFunction("eglGetSyncAttrib", NapiEGL::NapiEGLGetSyncAttrib),
        DefineFunction("eglDestroyImage", NapiEGL::NapiEGLDestroyImage),
        DefineFunction("eglGetPlatformDisplay", NapiEGL::NapiEGLGetPlatformDisplay),
        DefineFunction("eglCreatePlatformWindowSurface", NapiEGL::NapiEGLCreatePlatformWindowSurface),
        DefineFunction("eglCreatePlatformPixmapSurface", NapiEGL::NapiEGLCreatePlatformPixmapSurface),
        DefineFunction("eglWaitSync", NapiEGL::NapiEGLWaitSync),
        DefineFunction("eglCreatePixmapSurface", NapiEGL::NapiEGLCreatePixmapSurface),
        DefineFunction("eglCreateImageKHR", NapiEGL::NapiEGLCreateImageKHR),
        DefineFunction("eglCreatePbufferFromClientBuffer", NapiEGL::NapiEGLCreatePbufferFromClientBuffer),
        DefineFunction("eglCopyBuffers", NapiEGL::NapiEGLCopyBuffers),
        DefineFunction("eglDestroyImageKHR", NapiEGL::NapiEGLDestroyImageKHR),
        DefineFunction("eglCreateSyncKHR", NapiEGL::NapiEGLCreateSyncKHR),
        DefineFunction("eglDestroySyncKHR", NapiEGL::NapiEGLDestroySyncKHR),
        DefineFunction("eglCreateImage", NapiEGL::NapiEGLCreateImage),
    };

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
