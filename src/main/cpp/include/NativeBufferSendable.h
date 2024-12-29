//
// Created on 2024/12/29.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef GLTEST_NATIVEBUFFERSENDABLE_H
#define GLTEST_NATIVEBUFFERSENDABLE_H
#include "napi/native_api.h"

class StandardNativeBuffer {
public:
    static napi_ref cons;
    static napi_value JSConstructor(napi_env env, napi_callback_info info);
    static napi_value JSDestroy(napi_env env, napi_callback_info info);
};


#endif // GLTEST_NATIVEBUFFERSENDABLE_H
