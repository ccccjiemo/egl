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
        DefineStaticFunction("getDisplay", StandardEGLDisplay::JSGetDisplay),
        DefineStaticFunction("getCurrentDisplay", StandardEGLDisplay::JSGetCurrentDisplay),
        DefineStaticFunction("getPlatformDisplay", StandardEGLDisplay::JSGetPlatformDisplay),
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
        DefineStaticFunction("getCurrentContext", StandardEGLContext::JSGetCurrentContext),
        DefineFunction("query", StandardEGLContext::JSQuery),
    };
    DefineSendableClass(env, exports, "EGLContext", StandardEGLContext::JSConstructor, eglContextDesc,
                        &StandardEGLContext::cons);

    /***
     * define eglSurface
     */
    napi_property_descriptor eglSurfaceDesc[] = {
        DefineStaticFunction("getCurrentSurface", StandardEGLSurface::JSGetCurrentSurface),
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
        DefineFunction("eglCreateContext", NapiEGL::NapiEGLCreateContext),
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
