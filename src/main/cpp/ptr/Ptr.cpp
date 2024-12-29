//
// Created on 2024/11/13.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#include "Ptr.h"
#include <cstdio>
#include <cstdlib>


napi_ref Ptr::g_ref = nullptr;
std::unordered_map<void *, napi_ref> Ptr::_ptr_cache;


void Ptr::NapiToPtr(napi_env env, napi_value val, void **ptr) {
    napi_valuetype type;
    napi_typeof(env, val, &type);
    int64_t t = 0;
    char str[36];
    size_t size = 36;
    switch (type) {
    case napi_number:
        napi_get_value_int64(env, val, &t);
        break;
    case napi_string:
        napi_get_value_string_utf8(env, val, str, size, &size);
        t = atoll(str);
        break;
    default:
        break;
    }
    *ptr = reinterpret_cast<void *>(t);
}

napi_value Ptr::constructor(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value argv[1];
    napi_value _this = nullptr;
    napi_get_cb_info(env, info, &argc, argv, &_this, nullptr);

    void *ptr = nullptr;
    NapiToPtr(env, argv[0], &ptr);

    if (_ptr_cache.find(ptr) != _ptr_cache.end()) {
        napi_value result = nullptr;
        napi_ref ref = _ptr_cache[ptr];
        napi_get_reference_value(env, ref, &result);
        return result;
    }

    napi_wrap(
        env, _this, ptr, [](napi_env env, void *finalize_data, void *finalize_hit) {}, nullptr, nullptr);

    napi_ref ref = nullptr;
    napi_create_reference(env, _this, 1, &ref);
    _ptr_cache[ptr] = ref;

    return _this;
}

void Ptr::Export(napi_env env, napi_value exports) {
    napi_value cons = nullptr;
    napi_property_descriptor descriptor[] = {
        {"toString", nullptr, NapiToString, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"equals", nullptr, NapiEquals, nullptr, nullptr, nullptr, napi_default, nullptr}};
    napi_define_class(env, "Ptr", NAPI_AUTO_LENGTH, constructor, nullptr, sizeof(descriptor) / sizeof(descriptor[0]),
                      descriptor, &cons);
    napi_create_reference(env, cons, 1, &g_ref);

    /* napi_value function = nullptr;
     napi_create_function(env, "toString", NAPI_AUTO_LENGTH, NapiToString, nullptr, &function);
     napi_set_named_property(env, cons, "toString", function);*/

    napi_set_named_property(env, exports, "Ptr", cons);
}

napi_value Ptr::NapiToString(napi_env env, napi_callback_info info) {
    napi_value _this = nullptr;
    napi_get_cb_info(env, info, nullptr, nullptr, &_this, nullptr);

    void *result;
    napi_unwrap(env, _this, &result);

    char str[36];
    sprintf(str, "%lld", (long long int)result);
    napi_value r = nullptr;

    napi_create_string_utf8(env, str, NAPI_AUTO_LENGTH, &r);
    return r;
}

napi_value Ptr::NapiEquals(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value argv[1];
    napi_value _this = nullptr;
    napi_get_cb_info(env, info, &argc, argv, &_this, nullptr);

    void *own = nullptr;
    napi_unwrap(env, _this, &own);
    void *target = nullptr;
    napi_unwrap(env, argv[0], &target);

    napi_value result = nullptr;
    napi_create_int32(env, own == target, &result);
    return result;
}


napi_value Ptr::NapiCreatePtr(napi_env env, void *ptr) {

    /*    if (_ptr_cache.find(ptr) != _ptr_cache.end()) {
            napi_ref ref = _ptr_cache[ptr];
            napi_value target = nullptr;
            napi_get_reference_value(env, ref, &target);
            return target;
        } else {
            napi_value argv[1];
            napi_create_int64(env, (long long int)ptr, &argv[0]);
            napi_value cons = nullptr;
            napi_value target = nullptr;
            napi_get_reference_value(env, Ptr::g_ref, &cons);
            napi_new_instance(env, cons, 1, argv, &target);*/

    /* napi_wrap(
         env, target, ptr, [](napi_env env, void *finalize_data, void *finalize_hit) {}, nullptr, nullptr);

     napi_ref ref = nullptr;
     napi_create_reference(env, target, 1, &ref);
     _ptr_cache[ptr] = ref;*/
    if(ptr == nullptr) {
        return nullptr;
    }
    char str[36];
    sprintf(str, "%lld", (long long int)ptr);
    napi_value r = nullptr;

    napi_create_string_utf8(env, str, NAPI_AUTO_LENGTH, &r);

    return r;
}

// void *getPtrFromString(napi_env env, napi_value value) {
//     long long int result = 0;
//     char str[36];
//     size_t bufsize = 0;
//     napi_get_value_string_utf8(env, value, str, bufsize, &bufsize);
//     result = atoll(str);
// }

void *Ptr::NapiGetPtr(napi_env env, napi_value obj) {
    void *result = nullptr;
    NapiToPtr(env, obj, &result);
    return result;
}