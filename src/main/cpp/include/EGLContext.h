//
// Created on 2024/12/28.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef GLTEST_EGLCONTEXT_H
#define GLTEST_EGLCONTEXT_H
#include "napi/native_api.h"
#include <EGL/egl.h>

class StandardEGLContext {
public:
    static napi_ref cons;
    static napi_value JSConstructor(napi_env env, napi_callback_info info);
    static napi_value JSGetCurrentContext(napi_env env, napi_callback_info info);
    static napi_value JSQuery(napi_env env, napi_callback_info info);
    static napi_value CreateEGLContext(napi_env env, EGLContext context);
};

#endif // GLTEST_EGLCONTEXT_H
