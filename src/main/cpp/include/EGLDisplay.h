//
// Created on 2024/12/28.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef GLTEST_EGLDISPLAY_H
#define GLTEST_EGLDISPLAY_H
#include "napi/native_api.h"
#include <EGL/egl.h>

class StandardEGLDisplay {
public:
    static napi_value JSConstructor(napi_env env, napi_callback_info info);
    static napi_value JSGetDisplay(napi_env env, napi_callback_info info);
    static napi_value JSGetCurrentDisplay(napi_env env, napi_callback_info info);
    static napi_value JSGetPlatformDisplay(napi_env env, napi_callback_info info);
    static napi_value JSTerminate(napi_env env, napi_callback_info info);
    static napi_value JSInitialize(napi_env env, napi_callback_info info);
    static napi_value JSChooseConfig(napi_env env, napi_callback_info info);
    static napi_value JSCreateContext(napi_env env, napi_callback_info info);
    static napi_value JSCreateWindowSurface(napi_env env, napi_callback_info info);
    static napi_value JSMakeCurrent(napi_env env, napi_callback_info info);
    static napi_value JSCreatePbufferSurface(napi_env env, napi_callback_info info);
    static napi_value JSDestroyContext(napi_env env, napi_callback_info info);
    static napi_value JSDestroySurface(napi_env env, napi_callback_info info);
    static napi_value JSGetConfigs(napi_env env, napi_callback_info info);
    static napi_value JSQueryString(napi_env env, napi_callback_info info);
    static napi_value JSSwapBuffers(napi_env env, napi_callback_info info);
    static napi_value JSCreateSync(napi_env env, napi_callback_info info);
    static napi_value JSDestroySync(napi_env env, napi_callback_info info);
    static napi_value JSClientWaitSync(napi_env env, napi_callback_info info);
    static napi_value JSWaitSync(napi_env env, napi_callback_info info);
    static napi_value JSGetSyncAttrib(napi_env env, napi_callback_info info);
    static napi_value JSSwapInterval(napi_env env, napi_callback_info info);
    static napi_value CreateEGLDisplay(napi_env env, EGLDisplay display);


    static napi_ref cons;
};

#endif // GLTEST_EGLDISPLAY_H
