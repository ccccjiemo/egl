//
// Created on 2024/12/28.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#include "EGLContext.h"
#include "EGLDisplay.h"
#include "utils.h"

napi_ref StandardEGLContext::cons = nullptr;
napi_value StandardEGLContext::JSConstructor(napi_env env, napi_callback_info info) {
    napi_value _this = nullptr;
    napi_get_cb_info(env, info, nullptr, nullptr, &_this, nullptr);
    return _this;
}

napi_value StandardEGLContext::CreateEGLContext(napi_env env, EGLContext context) {
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
    EGLDisplay display = StandardEGLDisplay::GetEGLDisplay(env, argv[0]);
    EGLContext context = GetEGLContext(env, _this);
    EGLint attribute = 0, value = 0;
    napi_get_value_int32(env, argv[1], &attribute);

    if (!eglQueryContext(display, context, attribute, &value)) {
        return nullptr;
    }
    return NapiCreateInt32(env, value);
}

EGLContext StandardEGLContext::GetEGLContext(napi_env env, napi_value value) {
    napi_valuetype type;
    napi_typeof(env, value, &type);
    if (napi_undefined == type)
        return nullptr;
    void *result = nullptr;
    if (napi_ok != napi_unwrap_sendable(env, value, &result)) {
        napi_throw_error(env, "EGLContext", "napi_unwrap_sendable failed");
        return nullptr;
    }
    return static_cast<EGLContext>(result);
}

EGLContext StandardEGLContext::GetEGLContext(napi_env env, napi_callback_info info) {
    napi_value _this = nullptr;
    if (napi_ok != napi_get_cb_info(env, info, nullptr, nullptr, &_this, nullptr)) {
        napi_throw_error(env, "EGLContext", "napi_get_cb_info failed");
        return nullptr;
    }
    return GetEGLContext(env, _this);
}
