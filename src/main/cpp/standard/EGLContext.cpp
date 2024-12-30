//
// Created on 2024/12/28.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#include "EGLContext.h"
#include "EGLBase.h"

napi_ref StandardEGLContext::cons = nullptr;
napi_value StandardEGLContext::JSConstructor(napi_env env, napi_callback_info info) {
    napi_value _this = nullptr;
    napi_get_cb_info(env, info, nullptr, nullptr, &_this, nullptr);
    return _this;
}

napi_value StandardEGLContext::CreateEGLContext(napi_env env, EGLContext context) {
    if (context == nullptr)
        return nullptr;
    napi_value _con = nullptr;
    napi_get_reference_value(env, cons, &_con);
    napi_value instance = nullptr;
    napi_new_instance(env, _con, 0, nullptr, &instance);
    if (instance == nullptr) {
        napi_throw_error(env, "EGLContext", "create new instance failed");
        return nullptr;
    }

    if (napi_ok != napi_wrap_sendable(env, instance, context, nullptr, nullptr)) {
        napi_throw_error(env, "EGLContext", "napi_wrap_sendable failed");
        return nullptr;
    }

    return instance;
}

napi_value StandardEGLContext::JSGetCurrentContext(napi_env env, napi_callback_info info) {
    EGLContext context = eglGetCurrentContext();
    if (context == nullptr)
        return nullptr;
    return CreateEGLContext(env, context);
}
napi_value StandardEGLContext::JSQuery(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value argv[2]{nullptr};
    napi_value _this = nullptr;
    napi_get_cb_info(env, info, &argc, argv, &_this, nullptr);

    return EGLBase::JSEGLQueryContext(env, argv[0], _this, argv[1]);
}

