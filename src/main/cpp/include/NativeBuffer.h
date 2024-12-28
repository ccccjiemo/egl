//
// Created on 2024/12/8.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef GLTEST_NATIVEBUFFER_H
#define GLTEST_NATIVEBUFFER_H

#include "napi/native_api.h"
namespace NativeBuffer {
void Export(napi_env env, napi_value exports);
napi_value NapiCreateNativeBuffer(napi_env env, napi_callback_info info);
napi_value NapiReleaseNativeBuffer(napi_env env, napi_callback_info info);
} // namespace NativeBuffer


#endif // GLTEST_NATIVEBUFFER_H
