//
// Created on 2024/12/29.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef GLTEST_NAPIEGL_H
#define GLTEST_NAPIEGL_H
#include "napi/native_api.h"



namespace NapiEGL {
napi_value NapiEGLGetDisplay(napi_env env, napi_callback_info info);
napi_value NapiEGLInitialize(napi_env env, napi_callback_info info);
napi_value NapiEGLChooseConfig(napi_env env, napi_callback_info info);
napi_value NapiEGLGetError(napi_env env, napi_callback_info info);
napi_value NapiEGLCreateWindowSurface(napi_env env, napi_callback_info info);
napi_value NapiEGLMakeCurrent(napi_env env, napi_callback_info info);
napi_value NapiEGLCreatePbufferSurface(napi_env env, napi_callback_info info);
napi_value NapiEGLDestroyContext(napi_env env, napi_callback_info info);
napi_value NapiEGLDestroySurface(napi_env env, napi_callback_info info);
napi_value NapiEGLGetConfigAttrib(napi_env env, napi_callback_info info);
napi_value NapiEGLGetConfigs(napi_env env, napi_callback_info info);
napi_value NapiEGLGetCurrentDisplay(napi_env env, napi_callback_info info);
napi_value NapiEGLGetCurrentSurface(napi_env env, napi_callback_info info);
napi_value NapiEGLGetProcAddress(napi_env env, napi_callback_info info);
napi_value NapiEGLQueryContext(napi_env env, napi_callback_info info);
napi_value NapiEGLQueryString(napi_env env, napi_callback_info info);
napi_value NapiEGLQuerySurface(napi_env env, napi_callback_info info);
napi_value NapiEGLSwapBuffers(napi_env env, napi_callback_info info);
napi_value NapiEGLTerminate(napi_env env, napi_callback_info info);
napi_value NapiEGLWaitGL(napi_env env, napi_callback_info info);
napi_value NapiEGLWaitNative(napi_env env, napi_callback_info info);
napi_value NapiEGLBindTexImage(napi_env env, napi_callback_info info);
napi_value NapiEGLReleaseTexImage(napi_env env, napi_callback_info info);
napi_value NapiEGLSurfaceAttrib(napi_env env, napi_callback_info info);
napi_value NapiEGLSwapInterval(napi_env env, napi_callback_info info);
napi_value NapiEGLBindAPI(napi_env env, napi_callback_info info);
napi_value NapiEGLQueryAPI(napi_env env, napi_callback_info info);
napi_value NapiEGLReleaseThread(napi_env env, napi_callback_info info);
napi_value NapiEGLWaitClient(napi_env env, napi_callback_info info);
napi_value NapiEGLGetCurrentContext(napi_env env, napi_callback_info info);
napi_value NapiEGLCreateSync(napi_env env, napi_callback_info info);
napi_value NapiEGLDestroySync(napi_env env, napi_callback_info info);
napi_value NapiEGLClientWaitSync(napi_env env, napi_callback_info info);
napi_value NapiEGLGetSyncAttrib(napi_env env, napi_callback_info info);
napi_value NapiEGLDestroyImage(napi_env env, napi_callback_info info);
napi_value NapiEGLGetPlatformDisplay(napi_env env, napi_callback_info info);
napi_value NapiEGLCreatePlatformWindowSurface(napi_env env, napi_callback_info info);
napi_value NapiEGLCreatePlatformPixmapSurface(napi_env env, napi_callback_info info);
napi_value NapiEGLWaitSync(napi_env env, napi_callback_info info);
napi_value NapiEGLCreatePixmapSurface(napi_env env, napi_callback_info info);
napi_value NapiEGLCreateImageKHR(napi_env env, napi_callback_info info);
napi_value NapiEGLCreatePbufferFromClientBuffer(napi_env env, napi_callback_info info);
napi_value NapiEGLCopyBuffers(napi_env env, napi_callback_info info);
napi_value NapiEGLDestroyImageKHR(napi_env env, napi_callback_info info);
napi_value NapiEGLCreateSyncKHR(napi_env env, napi_callback_info info);
napi_value NapiEGLDestroySyncKHR(napi_env env, napi_callback_info info);
napi_value NapiEGLCreateImage(napi_env env, napi_callback_info info);
napi_value NapiEGLCreateContext(napi_env env, napi_callback_info info);


} // namespace NapiEGL


#endif // GLTEST_NAPIEGL_H
