//
// Created on 2024/12/29.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#include "NapiEGL.h"
#include "EGLBase.h"
#include "utils.h"


namespace NapiEGL {
napi_value NapiEGLChooseConfig(napi_env env, napi_callback_info info) { GenerateNAPI(JSEGLChooseConfig, 3); }
napi_value NapiEGLGetError(napi_env env, napi_callback_info info) { return EGLBase::JSEGLGetError(env); }
napi_value NapiEGLDestroyContext(napi_env env, napi_callback_info info) { GenerateNAPI(JSEGLDestroyContext, 2); }
napi_value NapiEGLDestroySurface(napi_env env, napi_callback_info info) { GenerateNAPI(JSEGLDestroySurface, 2); }
napi_value NapiEGLGetConfigAttrib(napi_env env, napi_callback_info info) { GenerateNAPI(JSEGLGetConfigAttrib, 3); }
napi_value NapiEGLGetConfigs(napi_env env, napi_callback_info info) { GenerateNAPI(JSEGLGetConfigs, 2); }
napi_value NapiEGLQueryContext(napi_env env, napi_callback_info info) { GenerateNAPI(JSEGLQueryContext, 3); }
napi_value NapiEGLQueryString(napi_env env, napi_callback_info info) { GenerateNAPI(JSEGLQueryString, 2); }
napi_value NapiEGLQuerySurface(napi_env env, napi_callback_info info) { GenerateNAPI(JSEGLQuerySurface, 3); }
napi_value NapiEGLSwapBuffers(napi_env env, napi_callback_info info) { GenerateNAPI(JSEGLSwapBuffers, 2); }
napi_value NapiEGLTerminate(napi_env env, napi_callback_info info) { GenerateNAPI(JSEGLTerminate, 1); }
napi_value NapiEGLWaitGL(napi_env env, napi_callback_info info) { return EGLBase::JSEGLWaitGL(env); }
napi_value NapiEGLBindTexImage(napi_env env, napi_callback_info info) { GenerateNAPI(JSEGLBindTexImage, 3); }
napi_value NapiEGLReleaseTexImage(napi_env env, napi_callback_info info) { GenerateNAPI(JSEGLReleaseTexImage, 3); }
napi_value NapiEGLSurfaceAttrib(napi_env env, napi_callback_info info) { GenerateNAPI(JSEGLSurfaceAttrib, 4); }
napi_value NapiEGLSwapInterval(napi_env env, napi_callback_info info) { GenerateNAPI(JSEGLSwapInterval, 2); }
napi_value NapiEGLQueryAPI(napi_env env, napi_callback_info info) { return EGLBase::JSEGLQueryAPI(env); }
napi_value NapiEGLReleaseThread(napi_env env, napi_callback_info info) { return EGLBase::JSEGLReleaseThread(env); }
napi_value NapiEGLWaitClient(napi_env env, napi_callback_info info) { return EGLBase::JSEGLWaitClient(env); }
napi_value NapiEGLCreateSync(napi_env env, napi_callback_info info) { GenerateNAPI(JSEGLCreateSync, 3); }
napi_value NapiEGLDestroySync(napi_env env, napi_callback_info info) { GenerateNAPI(JSEGLDestroySync, 2); }
napi_value NapiEGLClientWaitSync(napi_env env, napi_callback_info info) { GenerateNAPI(JSEGLClientWaitSync, 4); }
napi_value NapiEGLGetSyncAttrib(napi_env env, napi_callback_info info) { GenerateNAPI(JSEGLGetSyncAttrib, 3); }
napi_value NapiEGLDestroyImage(napi_env env, napi_callback_info info) { GenerateNAPI(JSEGLDestroyImage, 2); }
napi_value NapiEGLWaitSync(napi_env env, napi_callback_info info) { GenerateNAPI(JSEGLWaitSync, 3); }
napi_value NapiEGLGetDisplay(napi_env env, napi_callback_info info) { GenerateNAPI(JSEGLGetDisplay, 1); }
napi_value NapiEGLGetCurrentSurface(napi_env env, napi_callback_info info) { GenerateNAPI(JSEGLGetCurrentSurface, 1); }
napi_value NapiEGLGetProcAddress(napi_env env, napi_callback_info info) { GenerateNAPI(JSEGLGetProcAddress, 1); }
napi_value NapiEGLWaitNative(napi_env env, napi_callback_info info) { GenerateNAPI(JSEGLWaitNative, 1); }
napi_value NapiEGLBindAPI(napi_env env, napi_callback_info info) { GenerateNAPI(JSEGLBindAPI, 1); }
napi_value NapiEGLCreateImageKHR(napi_env env, napi_callback_info info) { GenerateNAPI(JSEGLCreateImageKHR, 5); }
napi_value NapiEGLCreateImage(napi_env env, napi_callback_info info) { GenerateNAPI(JSEGLCreateImage, 5); }
napi_value NapiEGLCopyBuffers(napi_env env, napi_callback_info info) { GenerateNAPI(JSEGLCopyBuffers, 3); }
napi_value NapiEGLDestroyImageKHR(napi_env env, napi_callback_info info) { GenerateNAPI(JSEGLDestroyImageKHR, 2); }
napi_value NapiEGLCreateSyncKHR(napi_env env, napi_callback_info info) { GenerateNAPI(JSEGLCreateSyncKHR, 3); }
napi_value NapiEGLDestroySyncKHR(napi_env env, napi_callback_info info) { GenerateNAPI(JSEGLDestroySyncKHR, 2); }
napi_value NapiEGLMakeCurrent(napi_env env, napi_callback_info info) { GenerateNAPI(JSEGLMakeCurrent, 4); }
napi_value NapiEGLInitialize(napi_env env, napi_callback_info info) { GenerateNAPI(JSEGLInitialize, 1); }
napi_value NapiEGLCreateContext(napi_env env, napi_callback_info info) { GenerateNAPI(JSEGLCreateContext, 4); }
napi_value NapiEGLGetCurrentContext(napi_env env, napi_callback_info info) {
    return EGLBase::JSEGLGetCurrentContext(env);
}
napi_value NapiEGLGetCurrentDisplay(napi_env env, napi_callback_info info) {
    return EGLBase::JSEGLGetCurrentDisplay(env);
}
napi_value NapiEGLCreatePlatformWindowSurface(napi_env env, napi_callback_info info) {
    GenerateNAPI(JSEGLCreatePlatformWindowSurface, 4);
}
napi_value NapiEGLCreatePlatformPixmapSurface(napi_env env, napi_callback_info info) {
    GenerateNAPI(JSEGLCreatePlatformPixmapSurface, 4);
}
napi_value NapiEGLCreatePbufferFromClientBuffer(napi_env env, napi_callback_info info) {
    GenerateNAPI(JSEGLCreatePbufferFromClientBuffer, 5);
}
napi_value NapiEGLCreatePixmapSurface(napi_env env, napi_callback_info info) {
    GenerateNAPI(JSEGLCreatePixmapSurface, 4);
}
napi_value NapiEGLCreateWindowSurface(napi_env env, napi_callback_info info) {
    GenerateNAPI(JSEGLCreateWindowSurface, 4);
}
napi_value NapiEGLCreatePbufferSurface(napi_env env, napi_callback_info info) {
    GenerateNAPI(JSEGLCreatePbufferSurface, 3);
}
napi_value NapiEGLGetPlatformDisplay(napi_env env, napi_callback_info info) {
    GenerateNAPI(JSEGLGetPlatformDisplay, 3);
}


}