//
// Created on 2024/11/14.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef GLSURFACEVIEW_UTILS_H
#define GLSURFACEVIEW_UTILS_H

#include <EGL/egl.h>
#include <js_native_api.h>
#include <js_native_api_types.h>

EGLint *getEGLintList(napi_env env, napi_value val) {
    bool is_array = false;
    napi_is_array(env, val, &is_array);
    if (!is_array)
        return nullptr;
    
    uint32_t length;
    napi_get_array_length(env, val, &length);

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

EGLAttrib *getEGLAttribList(napi_env env, napi_value val) {
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

void freeEGLAttribList(EGLAttrib **list) {
    if (*list != nullptr) {
        delete[] *list;
        *list = nullptr;
    }
}

void freeEGLIntList(EGLint **list) {
    if (*list != nullptr) {
        delete[] *list;
        *list = nullptr;
    }
}


void getAttributeFromObject(napi_env env, napi_value obj, EGLint *attribute) {
    napi_valuetype type;
    napi_typeof(env, obj, &type);
    if (type != napi_object)
        return;

    napi_value napi_attrib = nullptr;
    napi_get_named_property(env, obj, "attribute", &napi_attrib);
    napi_get_value_int32(env, napi_attrib, attribute);
}

void setAttributeFromObject(napi_env env, napi_value obj, EGLint value) {
    napi_value val = nullptr;
    napi_create_int32(env, value, &val);
    napi_set_named_property(env, obj, "value", val);
}

void setAttribute64FromObject(napi_env env, napi_value obj, EGLAttrib value) {
    napi_value val = nullptr;
    napi_create_int64(env, value, &val);
    napi_set_named_property(env, obj, "value", val);
}

napi_value NapiCreateInt32(napi_env env, EGLint value) {
    napi_value result = nullptr;
    napi_create_int32(env, value, &result);
    return result;
}


#endif //GLSURFACEVIEW_UTILS_H
