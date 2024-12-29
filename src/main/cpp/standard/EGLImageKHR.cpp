//
// Created on 2024/12/29.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#include "EGLImageKHR.h"

napi_ref StandardEGLImageKHR::cons = nullptr;

napi_value StandardEGLImageKHR::JSConstructor(napi_env env, napi_callback_info info) {
    napi_value _this = nullptr;
    napi_get_cb_info(env, info, nullptr, nullptr, &_this, nullptr);
    return _this;
}
napi_value StandardEGLImageKHR::CreateEGLImageKHR(napi_env env, EGLImageKHR image) {
    if (image == nullptr)
        return nullptr;
    napi_value _con = nullptr;
    napi_get_reference_value(env, cons, &_con);
    napi_value instance = nullptr;
    napi_new_instance(env, _con, 0, nullptr, &instance);
    if (instance == nullptr) {
        napi_throw_error(env, "EGLImageKHR", "create new instance failed");
        return nullptr;
    }

    if (napi_ok != napi_wrap_sendable(env, instance, image, nullptr, nullptr)) {
        napi_throw_error(env, "EGLImageKHR", "napi_wrap_sendable failed");
        return nullptr;
    }

    return instance;
}
EGLImageKHR StandardEGLImageKHR::GetEGLImageKHR(napi_env env, napi_value value) {
    napi_valuetype type;
    napi_typeof(env, value, &type);
    if (napi_undefined == type)
        return nullptr;
    void *result = nullptr;
    if (napi_ok != napi_unwrap_sendable(env, value, &result)) {
        napi_throw_error(env, "EGLImageKHR", "napi_unwrap_sendable failed");
        return nullptr;
    }
    return static_cast<EGLImageKHR>(result);
}
EGLImageKHR StandardEGLImageKHR::GetEGLImageKHR(napi_env env, napi_callback_info info) {
    napi_value _this = nullptr;
    napi_get_cb_info(env, info, nullptr, nullptr, &_this, nullptr);
    return GetEGLImageKHR(env, _this);
}
