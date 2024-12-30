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

#define DefineStaticFunction(name, func)                                                                                     \
    { name, nullptr, func, nullptr, nullptr, nullptr, napi_static, nullptr }

#define DefineSendableClass(env, exports, className, constructor, desc, ref)                                           \
    defineSendableClass(env, exports, className, constructor, desc, sizeof(desc) / sizeof(desc[0]), ref)

#define DefineSendableClassWithSize(env, exports, className, constructor, desc, size, ref)                             \
    defineSendableClass(env, exports, className, constructor, desc, size, ref)

#define Generate(name)                                                                                                 \
    napi_value _this = nullptr;                                                                                        \
    napi_get_cb_info(env, info, nullptr, nullptr, &_this, nullptr);                                                    \
    return EGLBase::name(env, _this);

#define Generate1(name)                                                                                                \
    size_t argc = 1;                                                                                                   \
    napi_value argv[1]{nullptr};                                                                                       \
    napi_value _this = nullptr;                                                                                        \
    napi_get_cb_info(env, info, &argc, argv, &_this, nullptr);                                                         \
    return EGLBase::name(env, _this, argv[0]);

#define Generate2(name)                                                                                                \
    size_t argc = 2;                                                                                                   \
    napi_value argv[2]{nullptr};                                                                                       \
    napi_value _this = nullptr;                                                                                        \
    napi_get_cb_info(env, info, &argc, argv, &_this, nullptr);                                                         \
    return EGLBase::name(env, _this, argv[0], argv[1]);

#define Generate3(name)                                                                                                \
    size_t argc = 3;                                                                                                   \
    napi_value argv[3]{nullptr};                                                                                       \
    napi_value _this = nullptr;                                                                                        \
    napi_get_cb_info(env, info, &argc, argv, &_this, nullptr);                                                         \
    return EGLBase::name(env, _this, argv[0], argv[1], argv[2]);

#define Generate4(name)                                                                                                \
    size_t argc = 4;                                                                                                   \
    napi_value argv[4]{nullptr};                                                                                       \
    napi_value _this = nullptr;                                                                                        \
    napi_get_cb_info(env, info, &argc, argv, &_this, nullptr);                                                         \
    return EGLBase::name(env, _this, argv[0], argv[1], argv[2], argv[3]);

#define Argv1 argv[0]
#define Argv2 Argv1, argv[1]
#define Argv3 Argv2, argv[2]
#define Argv4 Argv3, argv[3]
#define Argv5 Argv4, argv[4]

#define GenerateNAPI(name, count)                                                                                      \
    size_t argc = count;                                                                                               \
    napi_value argv[count]{nullptr};                                                                                   \
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);                                                        \
    return EGLBase::name(env, Argv##count);


static OHNativeWindow *getNativeWindow(napi_env env, napi_value value) {
    size_t size = 32;
    char *str = new char[size];
    napi_get_value_string_utf8(env, value, str, size, &size);

    uint64_t surfaceId = atoll(str);
    OHNativeWindow *window = nullptr;

    OH_NativeWindow_CreateNativeWindowFromSurfaceId(surfaceId, &window);
    return window;
}

static EGLint getEGLInt(napi_env env, napi_value value) {
    napi_valuetype type;
    napi_typeof(env, value, &type);
    EGLint result = 0;
    if (type == napi_number) {
        napi_get_value_int32(env, value, &result);
    }
    return result;
}

static EGLTime getEGLTime(napi_env env, napi_value value) {
    napi_valuetype type;
    napi_typeof(env, value, &type);
    long result = 0;
    if (type == napi_number) {
        napi_get_value_int64(env, value, &result);
    }
    return result;
}

static EGLenum getEGLenum(napi_env env, napi_value value) {
    napi_valuetype type;
    napi_typeof(env, value, &type);
    EGLenum result = 0;
    if (type == napi_number) {
        napi_get_value_uint32(env, value, &result);
    }
    return result;
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

static napi_value NapiCreateEGLAttrib(napi_env env, EGLAttrib value) {
    napi_value result = nullptr;
    napi_create_int64(env, value, &result);
    return result;
}

static napi_value NapiCreateEGLenum(napi_env env, EGLenum value) {
    napi_value result = nullptr;
    napi_create_uint32(env, value, &result);
    return result;
}

static napi_value NapiCreateBoolean(napi_env env, EGLBoolean value) {
    napi_value result = nullptr;
    napi_get_boolean(env, value, &result);
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

static napi_value JSConstructor(napi_env env, napi_callback_info info) {
    napi_value _this = nullptr;
    napi_get_cb_info(env, info, nullptr, nullptr, &_this, nullptr);
    return _this;
}
template <typename T> static T GetSendable(napi_env env, napi_value value) {
    napi_valuetype type;
    napi_typeof(env, value, &type);
    if (napi_undefined == type)
        return nullptr;
    void *result = nullptr;
    if (napi_ok != napi_unwrap_sendable(env, value, &result)) {
        napi_throw_error(env, "Sendable", "napi_unwrap_sendable failed");
        return nullptr;
    }
    return static_cast<T>(result);
}
template <typename T> static T GetSendable(napi_env env, napi_callback_info info) {
    napi_value _this = nullptr;
    if (napi_ok != napi_get_cb_info(env, info, nullptr, nullptr, &_this, nullptr)) {
        napi_throw_error(env, "EGLSync", "napi_get_cb_info failed");
        return nullptr;
    }
    return GetSendable<T>(env, _this);
}

template <typename T> static T RemoveSendable(napi_env env, napi_value value) {
    void *result = nullptr;
    napi_remove_wrap_sendable(env, value, &result);
    return static_cast<T>(result);
}

template <typename T> static T RemoveSendable(napi_env env, napi_callback_info info) {
    napi_value _this = nullptr;
    napi_get_cb_info(env, info, nullptr, nullptr, &_this, nullptr);
    return RemoveSendable<T>(env, _this);
}

static napi_value GetThis(napi_env env, napi_callback_info info) {
    napi_value _this = nullptr;
    napi_get_cb_info(env, info, nullptr, nullptr, &_this, nullptr);
    return _this;
}

#endif // GLSURFACEVIEW_UTILS_H
