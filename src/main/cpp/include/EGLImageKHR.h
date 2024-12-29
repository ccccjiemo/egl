//
// Created on 2024/12/29.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef GLTEST_EGLIMAGEKHR_H
#define GLTEST_EGLIMAGEKHR_H
#include "napi/native_api.h"
#include <EGL/egl.h>
#include <EGL/eglext.h>
class StandardEGLImageKHR {
public:
    static napi_ref cons;
    static napi_value JSConstructor(napi_env env, napi_callback_info info);
    static napi_value CreateEGLImageKHR(napi_env env, EGLImageKHR image);
    static EGLImageKHR GetEGLImageKHR(napi_env env, napi_value value);
    static EGLImageKHR GetEGLImageKHR(napi_env env, napi_callback_info info);
};

#endif // GLTEST_EGLIMAGEKHR_H
