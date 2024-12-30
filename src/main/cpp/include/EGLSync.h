//
// Created on 2024/12/29.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef GLTEST_EGLSYNC_H
#define GLTEST_EGLSYNC_H

#include <EGL/egl.h>
#endif // GLTEST_EGLSYNC_H
#include "napi/native_api.h"

class StandardEGLSync {
public:
    static napi_ref cons;
    static napi_value JSConstructor(napi_env env, napi_callback_info info);
    static napi_value CreateEGLSync(napi_env env, EGLSync sync);

};