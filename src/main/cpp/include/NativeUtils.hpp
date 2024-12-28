#include "napi/native_api.h"
#include <cstdio>
#include <cstdlib>
#include <native_window/external_window.h>


namespace NativeUtils {


napi_value NapiGetWindowFromSurfaceId(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value argv[1];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    size_t size = 32;
    char *str = new char[size];
    napi_get_value_string_utf8(env, argv[0], str, size, &size);

    uint64_t surfaceId = atoll(str);
    OHNativeWindow *window = nullptr;

    OH_NativeWindow_CreateNativeWindowFromSurfaceId(surfaceId, &window);

    snprintf(str, 32, "%lld", (long long int)window);
    napi_value result = nullptr;
    napi_create_string_utf8(env, str, NAPI_AUTO_LENGTH, &result);

    delete[] str;
    return result;
}

void Export(napi_env env, napi_value exports) {
    /*    napi_property_descriptor desc[] = {{"getWindowFromSurfaceId", nullptr, NapiGetWindowFromSurfaceId, nullptr,
       nullptr, nullptr, napi_default, nullptr}};

        napi_value cons = nullptr;
        napi_define_class(env, "NativeHelper", NAPI_AUTO_LENGTH, nullptr, nullptr, sizeof(desc) / sizeof(desc[0]), desc,
                          &cons);*/

    napi_value func = nullptr;
    napi_create_function(env, "getWindowFromSurfaceId", NAPI_AUTO_LENGTH, NapiGetWindowFromSurfaceId, nullptr, &func);
    napi_set_named_property(env, exports, "getWindowFromSurfaceId", func);
}
} // namespace NativeUtils
