//
// Created on 2024/12/29.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef GLTEST_EGLSURFACE_H
#define GLTEST_EGLSURFACE_H
#include "napi/native_api.h"
#include <EGL/egl.h>

class StandardEGLSurface {
public:
    static napi_ref cons;
    static napi_value JSConstructor(napi_env env, napi_callback_info info);
    static napi_value CreateEGLSurface(napi_env env, EGLSurface surface);
    static napi_value JSGetCurrentSurface(napi_env env, napi_callback_info info);
    static napi_value JSSetAttribute(napi_env env, napi_callback_info info);
    static napi_value JSQuery(napi_env env, napi_callback_info info);
    static napi_value JSBindTexImage(napi_env env, napi_callback_info info);
    static napi_value JSReleaseTexImage(napi_env env, napi_callback_info info);
};

#endif // GLTEST_EGLSURFACE_H
