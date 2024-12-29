//
// Created on 2024/12/29.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#include "EGLSync.h"


napi_ref StandardEGLSync::cons = nullptr;
napi_value StandardEGLSync::JSConstructor(napi_env env, napi_callback_info info) {
    napi_value _this = nullptr;
    napi_get_cb_info(env, info, nullptr, nullptr, &_this, nullptr);
    return _this;
}

napi_value StandardEGLSync::CreateEGLSync(napi_env env, EGLSync sync) {
    if (sync == nullptr)
        return nullptr;
    napi_value _con = nullptr;
    napi_get_reference_value(env, cons, &_con);
    napi_value instance = nullptr;
    napi_new_instance(env, _con, 0, nullptr, &instance);
    if (instance == nullptr) {
        napi_throw_error(env, "EGLSync", "create new instance failed");
        return nullptr;
    }

    if (napi_ok != napi_wrap_sendable(env, instance, sync, nullptr, nullptr)) {
        napi_throw_error(env, "EGLSync", "napi_wrap_sendable failed");
        return nullptr;
    }

    return instance;
}
EGLSync StandardEGLSync::GetEGLSync(napi_env env, napi_value value) {
    napi_valuetype type;
    napi_typeof(env, value, &type);
    if (napi_undefined == type)
        return nullptr;
    void *result = nullptr;
    if (napi_ok != napi_unwrap_sendable(env, value, &result)) {
        napi_throw_error(env, "EGLSync", "napi_unwrap_sendable failed");
        return nullptr;
    }
    return static_cast<EGLSync>(result);
}
EGLSync StandardEGLSync::GetEGLSync(napi_env env, napi_callback_info info){
    napi_value _this = nullptr;
    if (napi_ok != napi_get_cb_info(env, info, nullptr, nullptr, &_this, nullptr)) {
        napi_throw_error(env, "EGLSync", "napi_get_cb_info failed");
        return nullptr;
    }
    return GetEGLSync(env, _this);
}