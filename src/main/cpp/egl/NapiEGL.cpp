//
// Created on 2024/12/29.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#include "NapiEGL.h"
#include "EGLBase.h"
#include "utils.h"


namespace NapiEGL {

napi_value NapiEGLChooseConfig(napi_env env, napi_callback_info info) { Generate2(JSEGLChooseConfig); }
napi_value NapiEGLGetError(napi_env env, napi_callback_info info) { return EGLBase::JSEGLGetError(env); }
napi_value NapiEGLCreateWindowSurface(napi_env env, napi_callback_info info) { Generate3(JSEGLCreateWindowSurface); }
napi_value NapiEGLMakeCurrent(napi_env env, napi_callback_info info) { Generate3(JSEGLMakeCurrent); }
napi_value NapiEGLCreatePbufferSurface(napi_env env, napi_callback_info info) { Generate2(JSEGLCreatePbufferSurface); }
napi_value NapiEGLDestroyContext(napi_env env, napi_callback_info info) { Generate1(JSEGLDestroyContext); }
napi_value NapiEGLDestroySurface(napi_env env, napi_callback_info info) { Generate1(JSEGLDestroySurface); }
napi_value NapiEGLGetConfigAttrib(napi_env env, napi_callback_info info) { Generate2(JSEGLGetConfigAttrib); }
napi_value NapiEGLGetConfigs(napi_env env, napi_callback_info info) { Generate1(JSEGLGetConfigs); }
napi_value NapiEGLQueryContext(napi_env env, napi_callback_info info) { Generate2(JSEGLQueryContext); }
napi_value NapiEGLQueryString(napi_env env, napi_callback_info info) { Generate1(JSEGLQueryString); }
napi_value NapiEGLQuerySurface(napi_env env, napi_callback_info info) { Generate2(JSEGLQuerySurface); }
napi_value NapiEGLSwapBuffers(napi_env env, napi_callback_info info) { Generate1(JSEGLSwapBuffers); }
napi_value NapiEGLTerminate(napi_env env, napi_callback_info info) { Generate(JSEGLTerminate); }
napi_value NapiEGLWaitGL(napi_env env, napi_callback_info info) { return EGLBase::JSEGLWaitGL(env); }
napi_value NapiEGLBindTexImage(napi_env env, napi_callback_info info) { Generate2(JSEGLBindTexImage); }
napi_value NapiEGLReleaseTexImage(napi_env env, napi_callback_info info) { Generate2(JSEGLReleaseTexImage); }
napi_value NapiEGLSurfaceAttrib(napi_env env, napi_callback_info info) { Generate3(JSEGLSurfaceAttrib); }
napi_value NapiEGLSwapInterval(napi_env env, napi_callback_info info) { Generate1(JSEGLSwapInterval); }
napi_value NapiEGLQueryAPI(napi_env env, napi_callback_info info) { return EGLBase::JSEGLQueryAPI(env); }
napi_value NapiEGLReleaseThread(napi_env env, napi_callback_info info) { return EGLBase::JSEGLReleaseThread(env); }
napi_value NapiEGLWaitClient(napi_env env, napi_callback_info info) { return EGLBase::JSEGLWaitClient(env); }
napi_value NapiEGLCreateSync(napi_env env, napi_callback_info info) { Generate2(JSEGLCreateSync); }
napi_value NapiEGLDestroySync(napi_env env, napi_callback_info info) { Generate1(JSEGLDestroySync); }
napi_value NapiEGLClientWaitSync(napi_env env, napi_callback_info info) { Generate3(JSEGLClientWaitSync); }
napi_value NapiEGLGetSyncAttrib(napi_env env, napi_callback_info info) { Generate2(JSEGLGetSyncAttrib); }
napi_value NapiEGLDestroyImage(napi_env env, napi_callback_info info) { Generate1(JSEGLDestroyImage); }
napi_value NapiEGLWaitSync(napi_env env, napi_callback_info info) { Generate2(JSEGLWaitSync); }
napi_value NapiEGLCreatePixmapSurface(napi_env env, napi_callback_info info) { Generate3(JSEGLCreatePixmapSurface); }
napi_value NapiEGLCreateImageKHR(napi_env env, napi_callback_info info) { Generate4(JSEGLCreateImageKHR); }
napi_value NapiEGLCreateImage(napi_env env, napi_callback_info info) { Generate4(JSEGLCreateImage); }
napi_value NapiEGLCopyBuffers(napi_env env, napi_callback_info info) { Generate2(JSEGLCopyBuffers); }
napi_value NapiEGLDestroyImageKHR(napi_env env, napi_callback_info info) { Generate1(JSEGLDestroyImageKHR); }
napi_value NapiEGLCreateSyncKHR(napi_env env, napi_callback_info info) { Generate2(JSEGLCreateSyncKHR); }
napi_value NapiEGLDestroySyncKHR(napi_env env, napi_callback_info info) { Generate1(JSEGLDestroySyncKHR); }
napi_value NapiEGLInitialize(napi_env env, napi_callback_info info) {
    napi_value _this = GetThis(env, info);
    return EGLBase::JSEGLInitialize(env, _this);
}
napi_value NapiEGLGetCurrentContext(napi_env env, napi_callback_info info) {
    return EGLBase::JSEGLGetCurrentContext(env);
}
napi_value NapiEGLGetCurrentDisplay(napi_env env, napi_callback_info info) {
    return EGLBase::JSEGLGetCurrentDisplay(env);
}
napi_value NapiEGLCreatePlatformWindowSurface(napi_env env, napi_callback_info info) {
    Generate3(JSEGLCreatePlatformWindowSurface);
}
napi_value NapiEGLCreatePlatformPixmapSurface(napi_env env, napi_callback_info info) {
    Generate3(JSEGLCreatePlatformPixmapSurface);
}
napi_value NapiEGLCreatePbufferFromClientBuffer(napi_env env, napi_callback_info info) {
    Generate4(JSEGLCreatePbufferFromClientBuffer);
}
napi_value NapiEGLGetDisplay(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value argv[1]{nullptr};
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    return EGLBase::JSEGLGetDisplay(env, argv[0]);
}
napi_value NapiEGLGetCurrentSurface(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value argv[1]{nullptr};
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    return EGLBase::JSEGLGetCurrentSurface(env, argv[0]);
}
napi_value NapiEGLGetProcAddress(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value argv[1]{nullptr};
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    return EGLBase::JSEGLGetProcAddress(env, argv[0]);
}
napi_value NapiEGLWaitNative(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value argv[1]{nullptr};
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    return EGLBase::JSEGLWaitNative(env, argv[0]);
}
napi_value NapiEGLBindAPI(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value argv[1]{nullptr};
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    return EGLBase::JSEGLBindAPI(env, argv[0]);
}
napi_value NapiEGLGetPlatformDisplay(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value argv[3]{nullptr};
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    return EGLBase::JSEGLGetPlatformDisplay(env, argv[0], argv[1], argv[2]);
}


}