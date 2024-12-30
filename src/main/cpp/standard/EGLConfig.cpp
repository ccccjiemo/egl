//
// Created on 2024/12/28.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#include "EGLConfig.h"
#include "EGLBase.h"

napi_ref StandardEGLConfig::cons = nullptr;

napi_value StandardEGLConfig::JSConstructor(napi_env env, napi_callback_info info) {
    napi_value _this = nullptr;
    napi_get_cb_info(env, info, nullptr, nullptr, &_this, nullptr);
    return _this;
}

napi_value StandardEGLConfig::CreateEGLConfig(napi_env env, EGLConfig config) {
    napi_value _con = nullptr;
    napi_get_reference_value(env, cons, &_con);
    napi_value instance = nullptr;
    napi_new_instance(env, _con, 0, nullptr, &instance);
    if (instance == nullptr) {
        napi_throw_error(env, "EGLDisplay", "create new instance failed");
        return nullptr;
    }

    if (napi_ok != napi_wrap_sendable(env, instance, config, nullptr, nullptr)) {
        napi_throw_error(env, "EGLDisplay", "napi_wrap_sendable failed");
        return nullptr;
    }

    return instance;
}

napi_value StandardEGLConfig::CreateEGLConfigList(napi_env env, EGLConfig *config, size_t size) {
    napi_value arr = nullptr;
    napi_create_array_with_length(env, size, &arr);
    for (int i = 0; i < size; i++) {
        napi_set_element(env, arr, i, CreateEGLConfig(env, config[i]));
    }
    return arr;
}

napi_value StandardEGLConfig::JSGetConfigAttrib(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value argv[2]{nullptr};
    napi_value _this = nullptr;
    napi_get_cb_info(env, info, &argc, argv, &_this, nullptr);

    return EGLBase::JSEGLGetConfigAttrib(env, argv[0], _this, argv[1]);
}
