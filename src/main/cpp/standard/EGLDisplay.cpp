//
// Created on 2024/12/28.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#include "EGLDisplay.h"
#include "EGLBase.h"
#include "NapiEGL.h"
#include "utils.h"

napi_ref StandardEGLDisplay::cons = nullptr;
napi_value StandardEGLDisplay::JSConstructor(napi_env env, napi_callback_info info) {
    napi_value _this = nullptr;
    napi_get_cb_info(env, info, nullptr, nullptr, &_this, nullptr);
    return _this;
}
napi_value StandardEGLDisplay::JSGetDisplay(napi_env env, napi_callback_info info) {
    return NapiEGL::NapiEGLGetDisplay(env, info);
}
napi_value StandardEGLDisplay::JSGetCurrentDisplay(napi_env env, napi_callback_info info) {
    return NapiEGL::NapiEGLGetCurrentDisplay(env, info);
}
napi_value StandardEGLDisplay::JSGetPlatformDisplay(napi_env env, napi_callback_info info) {
    return NapiEGL::NapiEGLGetPlatformDisplay(env, info);
}
napi_value StandardEGLDisplay::JSCreateWindowSurface(napi_env env, napi_callback_info info) {
    Generate3(JSEGLCreateWindowSurface);
}
napi_value StandardEGLDisplay::JSCreatePbufferSurface(napi_env env, napi_callback_info info) {
    Generate2(JSEGLCreatePbufferSurface);
}
napi_value StandardEGLDisplay::JSDestroyContext(napi_env env, napi_callback_info info) {
    Generate1(JSEGLDestroyContext);
}
napi_value StandardEGLDisplay::JSDestroySurface(napi_env env, napi_callback_info info) {
    Generate1(JSEGLDestroySurface);
}
napi_value StandardEGLDisplay::JSMakeCurrent(napi_env env, napi_callback_info info) { Generate3(JSEGLMakeCurrent); }
napi_value StandardEGLDisplay::JSTerminate(napi_env env, napi_callback_info info) { Generate(JSEGLTerminate); }
napi_value StandardEGLDisplay::JSInitialize(napi_env env, napi_callback_info info) { Generate(JSEGLInitialize); }
napi_value StandardEGLDisplay::JSChooseConfig(napi_env env, napi_callback_info info) { Generate2(JSEGLChooseConfig); }
napi_value StandardEGLDisplay::JSCreateContext(napi_env env, napi_callback_info info) { Generate3(JSEGLCreateContext); }
napi_value StandardEGLDisplay::JSGetConfigs(napi_env env, napi_callback_info info) { Generate1(JSEGLGetConfigs); }
napi_value StandardEGLDisplay::JSQueryString(napi_env env, napi_callback_info info) { Generate1(JSEGLQueryString); }
napi_value StandardEGLDisplay::JSSwapBuffers(napi_env env, napi_callback_info info) { Generate1(JSEGLSwapBuffers); }
napi_value StandardEGLDisplay::JSCreateSync(napi_env env, napi_callback_info info) { Generate2(JSEGLCreateSync); }
napi_value StandardEGLDisplay::JSDestroySync(napi_env env, napi_callback_info info) { Generate1(JSEGLDestroySync); }
napi_value StandardEGLDisplay::JSWaitSync(napi_env env, napi_callback_info info) { Generate2(JSEGLWaitSync); }
napi_value StandardEGLDisplay::JSGetSyncAttrib(napi_env env, napi_callback_info info) { Generate2(JSEGLGetSyncAttrib); }
napi_value StandardEGLDisplay::JSSwapInterval(napi_env env, napi_callback_info info) { Generate1(JSEGLSwapInterval); }

napi_value StandardEGLDisplay::JSClientWaitSync(napi_env env, napi_callback_info info) {
    Generate3(JSEGLClientWaitSync);
}

napi_value StandardEGLDisplay::CreateEGLDisplay(napi_env env, EGLDisplay display) {
    napi_value _con = nullptr;
    napi_get_reference_value(env, cons, &_con);
    napi_value instance = nullptr;
    napi_new_instance(env, _con, 0, nullptr, &instance);
    if (instance == nullptr) {
        napi_throw_error(env, "EGLDisplay", "create new instance failed");
        return nullptr;
    }

    if (napi_ok != napi_wrap_sendable(env, instance, display, nullptr, nullptr)) {
        napi_throw_error(env, "EGLDisplay", "napi_wrap_sendable failed");
        return nullptr;
    }

    return instance;
}
