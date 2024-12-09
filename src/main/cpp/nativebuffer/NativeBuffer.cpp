//
// Created on 2024/12/8.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#include "NativeBuffer.h"
#include "Ptr.h"
#include "utils.h"
#include <native_buffer/native_buffer.h>

namespace NativeBuffer {
void Export(napi_env env, napi_value exports) {
    /* napi_value createNativeBuffer = nullptr;
     napi_value releaseNativeBuffer = nullptr;

     napi_create_function(env, "createNativeBuffer", NAPI_AUTO_LENGTH, NapiCreateNativeBuffer, nullptr,
                          &createNativeBuffer);
     napi_create_function(env, "releaseNativeBuffer", NAPI_AUTO_LENGTH, NapiReleaseNativeBuffer, nullptr,
                          &releaseNativeBuffer);

     napi_set_named_property(env, exports, "createNativeBuffer", createNativeBuffer);
     napi_set_named_property(env, exports, "releaseNativeBuffer", releaseNativeBuffer);*/
    createFunction(env, exports, "createNativeBuffer", NapiCreateNativeBuffer);
    createFunction(env, exports, "releaseNativeBuffer", NapiReleaseNativeBuffer);
}
napi_value NapiCreateNativeBuffer(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value argv[1];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

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

    OH_NativeBuffer_Config config;
    config.width = width;
    config.height = height;
    config.format = format;
    config.usage = usage;
    config.stride = stride;

    OH_NativeBuffer *buffer = OH_NativeBuffer_Alloc(&config);
    OHNativeWindowBuffer *ohos_buffer = OH_NativeWindow_CreateNativeWindowBufferFromNativeBuffer(buffer);

    return Ptr::NapiCreatePtr(env, ohos_buffer);
}

napi_value NapiReleaseNativeBuffer(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value argv[1];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    void *buffer = nullptr;
    Ptr::NapiToPtr(env, argv[0], &buffer);
    OHNativeWindowBuffer *oh_buffer = reinterpret_cast<OHNativeWindowBuffer *>(buffer);
    OH_NativeBuffer *native_buffer = nullptr;
    OH_NativeBuffer_FromNativeWindowBuffer(oh_buffer, &native_buffer);
    OH_NativeWindow_DestroyNativeWindowBuffer(oh_buffer);
    OH_NativeBuffer_Unreference(native_buffer);

    // int result = OH_NativeBuffer_Unreference(reinterpret_cast<OH_NativeBuffer *>(buffer));
    return NapiCreateInt32(env, 1);
}
} // namespace NativeBuffer
