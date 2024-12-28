//
// Created on 2024/11/13.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef GLSURFACEVIEW_PTR_H
#define GLSURFACEVIEW_PTR_H

#include <js_native_api.h>
#include <node_api.h>
#include <node_api_types.h>
#include <unordered_map>


class Ptr {
public:
    static napi_ref g_ref;
    static napi_value constructor(napi_env env, napi_callback_info info);
    static void Export(napi_env env, napi_value exports);
    static napi_value NapiCreatePtr(napi_env env, void *ptr);
    static void *NapiGetPtr(napi_env env, napi_value obj);
    static void NapiToPtr(napi_env env, napi_value val, void **ptr);
    static napi_value NapiToString(napi_env env, napi_callback_info info);
    static napi_value NapiEquals(napi_env env, napi_callback_info info);
    static std::unordered_map<void *, napi_ref> _ptr_cache;
};
#endif // GLSURFACEVIEW_PTR_H
