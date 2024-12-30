//
// Created on 2024/12/29.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#include "EGLSyncKHR.h"

napi_ref StandardEGLSyncKHR::cons = nullptr;
napi_value StandardEGLSyncKHR::JSConstructor(napi_env env, napi_callback_info info) {
    napi_value _this = nullptr;
    napi_get_cb_info(env, info, nullptr, nullptr, &_this, nullptr);
    return _this;
}

napi_value StandardEGLSyncKHR::CreateEGLSyncKHR(napi_env env, EGLSyncKHR sync) {
    if (sync == nullptr)
        return nullptr;
    napi_value _con = nullptr;
    napi_get_reference_value(env, cons, &_con);
    napi_value instance = nullptr;
    napi_new_instance(env, _con, 0, nullptr, &instance);
    if (instance == nullptr) {
        napi_throw_error(env, "EGLSyncKHR", "create new instance failed");
        return nullptr;
    }

    if (napi_ok != napi_wrap_sendable(env, instance, sync, nullptr, nullptr)) {
        napi_throw_error(env, "EGLSyncKHR", "napi_wrap_sendable failed");
        return nullptr;
    }

    return instance;
}
