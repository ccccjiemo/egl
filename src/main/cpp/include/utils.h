//
// Created on 2024/11/14.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef GLSURFACEVIEW_UTILS_H
#define GLSURFACEVIEW_UTILS_H

#include <EGL/egl.h>
#include <cstdlib>
#include <js_native_api.h>
#include <js_native_api_types.h>
#include <napi/native_api.h>
#include <native_window/external_window.h>

#define DefineFunction(name, func)                                                                                     \
    { name, nullptr, func, nullptr, nullptr, nullptr, napi_default, nullptr }

#define DefineSendableClass(env, exports, className, constructor, desc,  ref)                                     \
    defineSendableClass(env, exports, className, constructor, desc, sizeof(desc)/sizeof(desc[0]), ref)

static OHNativeWindow *getNativeWindow(napi_env env, napi_value value) {
    size_t size = 32;
    char *str = new char[size];
    napi_get_value_string_utf8(env, value, str, size, &size);

    uint64_t surfaceId = atoll(str);
    OHNativeWindow *window = nullptr;

    OH_NativeWindow_CreateNativeWindowFromSurfaceId(surfaceId, &window);
    return window;
}

static EGLint *getEGLintList(napi_env env, napi_value val) {
    bool is_array = false;
    napi_is_array(env, val, &is_array);
    if (!is_array) {
        EGLint *list = new EGLint[1];
        list[0] = EGL_NONE;
        return list;
    }

    uint32_t length;
    napi_get_array_length(env, val, &length);

    if (length == 0) {
        EGLint *list = new EGLint[1];
        list[0] = EGL_NONE;
        return list;
    }

    EGLint *attrib_list = new EGLint[length];

    napi_handle_scope scope = nullptr;
    napi_open_handle_scope(env, &scope);
    for (int i = 0; i < length; i++) {
        napi_value result;
        napi_valuetype type;
        napi_get_element(env, val, i, &result);
        napi_typeof(env, result, &type);
        if (type != napi_number) {
            attrib_list[i] = 0;
        } else {
            napi_get_value_int32(env, result, &attrib_list[i]);
        }
    }
    napi_close_handle_scope(env, scope);
    return attrib_list;
}

static EGLAttrib *getEGLAttribList(napi_env env, napi_value val) {
    bool is_array = false;
    napi_is_array(env, val, &is_array);
    if (!is_array)
        return nullptr;

    uint32_t length;
    napi_get_array_length(env, val, &length);

    EGLAttrib *attrib_list = new EGLAttrib[length];

    napi_handle_scope scope = nullptr;
    napi_open_handle_scope(env, &scope);
    for (int i = 0; i < length; i++) {
        napi_value result;
        napi_valuetype type;
        napi_get_element(env, val, i, &result);
        napi_typeof(env, result, &type);
        if (type != napi_number) {
            attrib_list[i] = 0;
        } else {
            napi_get_value_int64(env, result, &attrib_list[i]);
        }
    }
    napi_close_handle_scope(env, scope);
    return attrib_list;
}

static void freeEGLAttribList(EGLAttrib **list) {
    if (*list != nullptr) {
        delete[] *list;
        *list = nullptr;
    }
}

static void freeEGLIntList(EGLint **list) {
    if (*list != nullptr) {
        delete[] *list;
        *list = nullptr;
    }
}


static void getAttributeFromObject(napi_env env, napi_value obj, EGLint *attribute) {
    napi_valuetype type;
    napi_typeof(env, obj, &type);
    if (type != napi_object)
        return;

    napi_value napi_attrib = nullptr;
    napi_get_named_property(env, obj, "attribute", &napi_attrib);
    napi_get_value_int32(env, napi_attrib, attribute);
}

static void setAttributeFromObject(napi_env env, napi_value obj, EGLint value) {
    napi_value val = nullptr;
    napi_create_int32(env, value, &val);
    napi_set_named_property(env, obj, "value", val);
}

static void setAttribute64FromObject(napi_env env, napi_value obj, EGLAttrib value) {
    napi_value val = nullptr;
    napi_create_int64(env, value, &val);
    napi_set_named_property(env, obj, "value", val);
}

static napi_value NapiCreateInt32(napi_env env, EGLint value) {
    napi_value result = nullptr;
    napi_create_int32(env, value, &result);
    return result;
}

static void createFunction(napi_env env, napi_value exports, const char *funName, napi_callback function) {
    napi_value func = nullptr;
    napi_create_function(env, funName, NAPI_AUTO_LENGTH, function, nullptr, &func);

    napi_set_named_property(env, exports, funName, func);
}

static void defineSendableClass(napi_env env, napi_value exports, const char *className, napi_callback constructor,
                                const napi_property_descriptor *desc, size_t size, napi_ref *ref) {
    napi_value cons = nullptr;
    napi_define_sendable_class(env, className, NAPI_AUTO_LENGTH, constructor, nullptr, size, desc, nullptr, &cons);
    napi_create_reference(env, cons, 1, ref);
    napi_set_named_property(env, exports, className, cons);
}

#endif // GLSURFACEVIEW_UTILS_H
