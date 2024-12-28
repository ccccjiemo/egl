//
// Created on 2024/12/28.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef GLTEST_EGLCONFIG_H
#define GLTEST_EGLCONFIG_H

#include "napi/native_api.h"
#include <EGL/egl.h>

class StandardEGLConfig {
public:
    static napi_value JSConstructor(napi_env env, napi_callback_info info);
    static napi_ref cons;
    static napi_value CreateEGLConfig(napi_env env, EGLConfig config);
    static napi_value CreateEGLConfigList(napi_env env, EGLConfig *config, size_t size);
    static napi_value JSGetConfigAttrib(napi_env env, napi_callback_info info);
    static EGLConfig GetEGLConfig(napi_env env, napi_value value);
    static EGLConfig GetEGLConfig(napi_env env, napi_callback_info info);
};


#endif // GLTEST_EGLCONFIG_H
