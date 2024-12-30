//
// Created on 2024/12/29.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#include "EGLSurface.h"
#include "EGLBase.h"
#include "utils.h"

napi_ref StandardEGLSurface::cons = nullptr;
napi_value StandardEGLSurface::JSConstructor(napi_env env, napi_callback_info info) {
    napi_value _this = nullptr;
    napi_get_cb_info(env, info, nullptr, nullptr, &_this, nullptr);
    return _this;
}
napi_value StandardEGLSurface::CreateEGLSurface(napi_env env, EGLSurface surface) {
    if (surface == nullptr)
        return nullptr;
    napi_value _con = nullptr;
    napi_get_reference_value(env, cons, &_con);
    napi_value instance = nullptr;
    napi_new_instance(env, _con, 0, nullptr, &instance);
    if (instance == nullptr) {
        napi_throw_error(env, "EGLSurface", "create new instance failed");
        return nullptr;
    }

    if (napi_ok != napi_wrap_sendable(env, instance, surface, nullptr, nullptr)) {
        napi_throw_error(env, "EGLSurface", "napi_wrap_sendable failed");
        return nullptr;
    }
    return instance;
}

napi_value StandardEGLSurface::JSGetCurrentSurface(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value argv[1];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    EGLint readdraw = 0;
    napi_get_value_int32(env, argv[0], &readdraw);
    EGLSurface surface = eglGetCurrentSurface(readdraw);
    return CreateEGLSurface(env, surface);
}

napi_value StandardEGLSurface::JSSetAttribute(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value argv[3]{nullptr};
    napi_value _this = nullptr;
    napi_get_cb_info(env, info, &argc, argv, &_this, nullptr);
    return EGLBase::JSEGLSurfaceAttrib(env, argv[0], _this, argv[1], argv[2]);
}
napi_value StandardEGLSurface::JSQuery(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value argv[2]{nullptr};
    napi_value _this = nullptr;
    napi_get_cb_info(env, info, &argc, argv, &_this, nullptr);
    return EGLBase::JSEGLQuerySurface(env, argv[0], _this, argv[1]);
}
napi_value StandardEGLSurface::JSBindTexImage(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value argv[2]{nullptr};
    napi_value _this = nullptr;
    napi_get_cb_info(env, info, &argc, argv, &_this, nullptr);
    return EGLBase::JSEGLBindTexImage(env, argv[0], _this, argv[1]);
}
napi_value StandardEGLSurface::JSReleaseTexImage(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value argv[2]{nullptr};
    napi_value _this = nullptr;
    napi_get_cb_info(env, info, &argc, argv, &_this, nullptr);
    return EGLBase::JSEGLReleaseTexImage(env, argv[0], _this, argv[1]);
}
