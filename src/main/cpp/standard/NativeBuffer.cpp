//
// Created on 2024/12/29.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#include "NativeBufferSendable.h"
#include <native_buffer/native_buffer.h>

napi_ref StandardNativeBuffer::cons = nullptr;

napi_value StandardNativeBuffer::JSConstructor(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value argv[1];
    napi_value _this = nullptr;
    napi_get_cb_info(env, info, &argc, argv, &_this, nullptr);

    int width = 0, height = 0, format = 0, usage = 0, stride = 0;
    napi_value nWidth = nullptr, nHeight = nullptr, nFormat = nullptr, nUsage = nullptr, nStride = nullptr;
    napi_get_named_property(env, argv[0], "width", &nWidth);
    napi_get_named_property(env, argv[0], "height", &nHeight);
    napi_get_named_property(env, argv[0], "format", &nFormat);
    napi_get_named_property(env, argv[0], "usage", &nUsage);
    napi_get_named_property(env, argv[0], "stride", &nStride);
    napi_get_value_int32(env, nWidth, &width);
    napi_get_value_int32(env, nHeight, &height);
    napi_get_value_int32(env, nFormat, &format);
    napi_get_value_int32(env, nUsage, &usage);
    napi_get_value_int32(env, nStride, &stride);
    OH_NativeBuffer_Config config = {};
    config.width = width;
    config.height = height;
    config.format = format;
    config.stride = stride;
    config.usage = usage;

    OH_NativeBuffer *bufferHandle = OH_NativeBuffer_Alloc(&config);
    if (bufferHandle == nullptr) {
        napi_throw_error(env, "NativeBuffer", "create OH_NativeBuffer failed");
        return nullptr;
    }

    OHNativeWindowBuffer *nativeWindowBuffer = OH_NativeWindow_CreateNativeWindowBufferFromNativeBuffer(bufferHandle);
    napi_wrap_sendable(
        env, _this, nativeWindowBuffer,
        [](napi_env env, void *data, void *hint) {
            OHNativeWindowBuffer *oh_buffer = reinterpret_cast<OHNativeWindowBuffer *>(data);
            OH_NativeBuffer *native_buffer = nullptr;
            OH_NativeBuffer_FromNativeWindowBuffer(oh_buffer, &native_buffer);
            OH_NativeWindow_DestroyNativeWindowBuffer(oh_buffer);
            OH_NativeBuffer_Unreference(native_buffer);
        },
        nullptr);
    return _this;
}

napi_value StandardNativeBuffer::JSDestroy(napi_env env, napi_callback_info info) {
    napi_value _this = nullptr;
    napi_get_cb_info(env, info, nullptr, nullptr, &_this, nullptr);
    void *data = nullptr;
    napi_remove_wrap_sendable(env, _this, &data);
    return nullptr;
}
