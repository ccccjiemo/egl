//
// Created on 2024/12/29.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef GLTEST_EGLIMAGE_H
#define GLTEST_EGLIMAGE_H
#include "napi/native_api.h"
#include <EGL/egl.h>

class StandardEGLImage {
public:
    static napi_ref cons;
    static napi_value JSConstructor(napi_env env, napi_callback_info info);
    static napi_value CreateEGLImage(napi_env env, EGLImage image);

};

#endif // GLTEST_EGLIMAGE_H
