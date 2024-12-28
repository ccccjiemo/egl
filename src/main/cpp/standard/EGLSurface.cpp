//
// Created on 2024/12/29.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#include "EGLSurface.h"
#include "EGLDisplay.h"
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
EGLSurface StandardEGLSurface::GetEGLSurface(napi_env env, napi_value value) {
    napi_valuetype type;
    napi_typeof(env, value, &type);
    if (napi_undefined == type)
        return nullptr;
    void *result = nullptr;
    if (napi_ok != napi_unwrap_sendable(env, value, &result)) {
        napi_throw_error(env, "EGLSurface", "napi_unwrap_sendable failed");
        return nullptr;
    }
    return static_cast<EGLSurface>(result);
}
EGLSurface StandardEGLSurface::GetEGLSurface(napi_env env, napi_callback_info info) {
    napi_value _this = nullptr;
    if (napi_ok != napi_get_cb_info(env, info, nullptr, nullptr, &_this, nullptr)) {
        napi_throw_error(env, "EGLSurface", "napi_get_cb_info failed");
        return nullptr;
    }
    return GetEGLSurface(env, _this);
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
    EGLDisplay dpy = StandardEGLDisplay::GetEGLDisplay(env, argv[0]);
    EGLSurface surface = GetEGLSurface(env, _this);
    EGLint attribute = 0, value = 0;
    napi_get_value_int32(env, argv[1], &attribute);
    napi_get_value_int32(env, argv[2], &value);
    return NapiCreateInt32(env, eglSurfaceAttrib(dpy, surface, attribute, value));
}
napi_value StandardEGLSurface::JSQuery(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value argv[2]{nullptr};
    napi_value _this = nullptr;
    napi_get_cb_info(env, info, &argc, argv, &_this, nullptr);
    EGLDisplay dpy = StandardEGLDisplay::GetEGLDisplay(env, argv[0]);
    EGLSurface surface = GetEGLSurface(env, _this);
    EGLint attribute = 0, value = 0;
    napi_get_value_int32(env, argv[1], &attribute);
    return NapiCreateInt32(env, eglQuerySurface(dpy, surface, attribute, &value));
}
napi_value StandardEGLSurface::JSBindTexImage(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value argv[2]{nullptr};
    napi_value _this = nullptr;
    napi_get_cb_info(env, info, &argc, argv, &_this, nullptr);
    EGLDisplay dpy = StandardEGLDisplay::GetEGLDisplay(env, argv[0]);
    EGLSurface surface = GetEGLSurface(env, _this);
    EGLint buffer = 0;
    napi_get_value_int32(env, argv[1], &buffer);
    return NapiCreateInt32(env, eglBindTexImage(dpy, surface, buffer));
}
napi_value StandardEGLSurface::JSReleaseTexImage(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value argv[2]{nullptr};
    napi_value _this = nullptr;
    napi_get_cb_info(env, info, &argc, argv, &_this, nullptr);
    EGLDisplay dpy = StandardEGLDisplay::GetEGLDisplay(env, argv[0]);
    EGLSurface surface = GetEGLSurface(env, _this);
    EGLint buffer = 0;
    napi_get_value_int32(env, argv[1], &buffer);
    return NapiCreateInt32(env, eglReleaseTexImage(dpy, surface, buffer));
}
