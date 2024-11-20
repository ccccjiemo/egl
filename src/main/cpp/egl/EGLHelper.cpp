//
// Created on 2024/11/6.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#include "EGLHelper.h"
#include <cstdint>
#include <cstdio>
#include <node_api.h>
#include <stdlib.h>
#include "Ptr.h"
#include "utils.h"


const char *class_name = "EGL";

namespace EGL {

void Export(napi_env env, napi_value exports) {
    napi_property_descriptor desc[] = {
        {"eglChooseConfig", nullptr, NapiEGLChooseConfig, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglCopyBuffers", nullptr, NapiEGLCopyBuffers, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglCreateContext", nullptr, NapiEGLCreateContext, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglCreatePbufferSurface", nullptr, NapiEGLCreatePbufferSurface, nullptr, nullptr, nullptr, napi_default,
         nullptr},
        {"eglCreatePixmapSurface", nullptr, NapiEGLCreatePixmapSurface, nullptr, nullptr, nullptr, napi_default,
         nullptr},
        {"eglCreateWindowSurface", nullptr, NapiEGLCreateWindowSurface, nullptr, nullptr, nullptr, napi_default,
         nullptr},
        {"eglDestroyContext", nullptr, NapiEGLDestroyContext, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglDestroySurface", nullptr, NapiEGLDestroySurface, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglGetConfigAttrib", nullptr, NapiEGLGetConfigAttrib, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglGetConfigs", nullptr, NapiEGLGetConfigs, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglGetCurrentDisplay", nullptr, NapiEGLGetCurrentDisplay, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglGetCurrentSurface", nullptr, NapiEGLGetCurrentSurface, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglGetDisplay", nullptr, NapiEGLGetDisplay, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglGetError", nullptr, NapiEGLGetError, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglGetProcAddress", nullptr, NapiEGLGetProcAddress, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglInitialize", nullptr, NapiEGLInitialize, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglMakeCurrent", nullptr, NapiEGLMakeCurrent, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglQueryContext", nullptr, NapiEGLQueryContext, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglQueryString", nullptr, NapiEGLQueryString, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglQuerySurface", nullptr, NapiEGLQuerySurface, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglSwapBuffers", nullptr, NapiEGLSwapBuffers, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglTerminate", nullptr, NapiEGLTerminate, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglWaitGL", nullptr, NapiEGLWaitGL, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglWaitNative", nullptr, NapiEGLWaitNative, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglBindTexImage", nullptr, NapiEGLBindTexImage, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglReleaseTexImage", nullptr, NapiEGLReleaseTexImage, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglSurfaceAttrib", nullptr, NapiEGLSurfaceAttrib, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglSwapInterval", nullptr, NapiEGLSwapInterval, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglBindAPI", nullptr, NapiEGLBindAPI, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglQueryAPI", nullptr, NapiEGLQueryAPI, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglCreatePbufferFromClientBuffer", nullptr, NapiEGLCreatePbufferFromClientBuffer, nullptr, nullptr, nullptr,
         napi_default, nullptr},
        {"eglReleaseThread", nullptr, NapiEGLReleaseThread, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglWaitClient", nullptr, NapiEGLWaitClient, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglGetCurrentContext", nullptr, NapiEGLGetCurrentContext, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglCreateSync", nullptr, NapiEGLCreateSync, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglDestroySync", nullptr, NapiEGLDestroySync, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglClientWaitSync", nullptr, NapiEGLClientWaitSync, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglGetSyncAttrib", nullptr, NapiEGLGetSyncAttrib, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglCreateImage", nullptr, NapiEGLCreateImage, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglDestroyImage", nullptr, NapiEGLDestroyImage, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglGetPlatformDisplay", nullptr, NapiEGLGetPlatformDisplay, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglCreatePlatformWindowSurface", nullptr, NapiEGLCreatePlatformWindowSurface, nullptr, nullptr, nullptr,
         napi_default, nullptr},
        {"eglCreatePlatformPixmapSurface", nullptr, NapiEGLCreatePlatformPixmapSurface, nullptr, nullptr, nullptr,
         napi_default, nullptr},
        {"eglWaitSync", nullptr, NapiEGLWaitSync, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglCreatePlatformWindowSurfaceEXT", nullptr, NapiEGLCreatePlatformWindowSurfaceEXT, nullptr, nullptr, nullptr,
         napi_default, nullptr},
        {"eglCreatePlatformPixmapSurfaceEXT", nullptr, NapiEGLCreatePlatformPixmapSurfaceEXT, nullptr, nullptr, nullptr,
         napi_default, nullptr},
        {"eglSwapBuffersWithDamageEXT", nullptr, NapiEGLSwapBuffersWithDamageEXT, nullptr, nullptr, nullptr,
         napi_default, nullptr},
        {"EGL_ALPHA_MASK_SIZE ", nullptr, nullptr, nullptr, nullptr, NapiCreateInt32(env, EGL_ALPHA_MASK_SIZE),
         napi_default, nullptr},
        {"EGL_ALPHA_SIZE ", nullptr, nullptr, nullptr, nullptr, NapiCreateInt32(env, EGL_ALPHA_SIZE), napi_default,
         nullptr},
        {"EGL_BIND_TO_TEXTURE_RGB ", nullptr, nullptr, nullptr, nullptr, NapiCreateInt32(env, EGL_BIND_TO_TEXTURE_RGB),
         napi_default, nullptr},
        {"EGL_BIND_TO_TEXTURE_RGBA ", nullptr, nullptr, nullptr, nullptr,
         NapiCreateInt32(env, EGL_BIND_TO_TEXTURE_RGBA), napi_default, nullptr},
        {"EGL_BUFFER_SIZE ", nullptr, nullptr, nullptr, nullptr, NapiCreateInt32(env, EGL_BUFFER_SIZE), napi_default,
         nullptr},
        {"EGL_BLUE_SIZE ", nullptr, nullptr, nullptr, nullptr, NapiCreateInt32(env, EGL_BLUE_SIZE), napi_default,
         nullptr},
        {"EGL_RED_SIZE ", nullptr, nullptr, nullptr, nullptr, NapiCreateInt32(env, EGL_RED_SIZE), napi_default,
         nullptr},
        {"EGL_COLOR_BUFFER_TYPE ", nullptr, nullptr, nullptr, nullptr, NapiCreateInt32(env, EGL_COLOR_BUFFER_TYPE),
         napi_default, nullptr},
        {"EGL_CONFIG_CAVEAT ", nullptr, nullptr, nullptr, nullptr, NapiCreateInt32(env, EGL_CONFIG_CAVEAT),
         napi_default, nullptr},
        {"EGL_CONFIG_ID ", nullptr, nullptr, nullptr, nullptr, NapiCreateInt32(env, EGL_CONFIG_ID), napi_default,
         nullptr},
        {"EGL_CONFORMANT ", nullptr, nullptr, nullptr, nullptr, NapiCreateInt32(env, EGL_CONFORMANT), napi_default,
         nullptr},
        {"EGL_DEPTH_SIZE ", nullptr, nullptr, nullptr, nullptr, NapiCreateInt32(env, EGL_DEPTH_SIZE), napi_default,
         nullptr},
        {"EGL_GREEN_SIZE ", nullptr, nullptr, nullptr, nullptr, NapiCreateInt32(env, EGL_GREEN_SIZE), napi_default,
         nullptr},
        {"EGL_LEVEL ", nullptr, nullptr, nullptr, nullptr, NapiCreateInt32(env, EGL_LEVEL), napi_default, nullptr},
        {"EGL_LUMINANCE_SIZE ", nullptr, nullptr, nullptr, nullptr, NapiCreateInt32(env, EGL_LUMINANCE_SIZE),
         napi_default, nullptr},
        {"EGL_MATCH_NATIVE_PIXMAP ", nullptr, nullptr, nullptr, nullptr, NapiCreateInt32(env, EGL_MATCH_NATIVE_PIXMAP),
         napi_default, nullptr},
        {"EGL_NATIVE_RENDERABLE ", nullptr, nullptr, nullptr, nullptr, NapiCreateInt32(env, EGL_NATIVE_RENDERABLE),
         napi_default, nullptr},
        {"EGL_MAX_SWAP_INTERVAL ", nullptr, nullptr, nullptr, nullptr, NapiCreateInt32(env, EGL_MAX_SWAP_INTERVAL),
         napi_default, nullptr},
        {"EGL_MIN_SWAP_INTERVAL ", nullptr, nullptr, nullptr, nullptr, NapiCreateInt32(env, EGL_MIN_SWAP_INTERVAL),
         napi_default, nullptr},
        {"EGL_SAMPLE_BUFFERS ", nullptr, nullptr, nullptr, nullptr, NapiCreateInt32(env, EGL_SAMPLE_BUFFERS),
         napi_default, nullptr},
        {"EGL_SAMPLES ", nullptr, nullptr, nullptr, nullptr, NapiCreateInt32(env, EGL_SAMPLES), napi_default, nullptr},
        {"EGL_STENCIL_SIZE ", nullptr, nullptr, nullptr, nullptr, NapiCreateInt32(env, EGL_STENCIL_SIZE), napi_default,
         nullptr},
        {"EGL_RENDERABLE_TYPE ", nullptr, nullptr, nullptr, nullptr, NapiCreateInt32(env, EGL_RENDERABLE_TYPE),
         napi_default, nullptr},
        {"EGL_SURFACE_TYPE ", nullptr, nullptr, nullptr, nullptr, NapiCreateInt32(env, EGL_SURFACE_TYPE), napi_default,
         nullptr},
        {"EGL_TRANSPARENT_TYPE ", nullptr, nullptr, nullptr, nullptr, NapiCreateInt32(env, EGL_TRANSPARENT_TYPE),
         napi_default, nullptr},
        {"EGL_TRANSPARENT_RED_VALUE ", nullptr, nullptr, nullptr, nullptr,
         NapiCreateInt32(env, EGL_TRANSPARENT_RED_VALUE), napi_default, nullptr},
        {"EGL_TRANSPARENT_GREEN_VALUE ", nullptr, nullptr, nullptr, nullptr,
         NapiCreateInt32(env, EGL_TRANSPARENT_GREEN_VALUE), napi_default, nullptr},
        {"EGL_TRANSPARENT_BLUE_VALUE ", nullptr, nullptr, nullptr, nullptr,
         NapiCreateInt32(env, EGL_TRANSPARENT_BLUE_VALUE), napi_default, nullptr},
        {"EGL_GL_COLORSPACE ", nullptr, nullptr, nullptr, nullptr, NapiCreateInt32(env, EGL_GL_COLORSPACE),
         napi_default, nullptr},
        {"EGL_HEIGHT ", nullptr, nullptr, nullptr, nullptr, NapiCreateInt32(env, EGL_HEIGHT), napi_default, nullptr},
        {"EGL_LARGEST_PBUFFER ", nullptr, nullptr, nullptr, nullptr, NapiCreateInt32(env, EGL_LARGEST_PBUFFER),
         napi_default, nullptr},
        {"EGL_MIPMAP_TEXTURE ", nullptr, nullptr, nullptr, nullptr, NapiCreateInt32(env, EGL_MIPMAP_TEXTURE),
         napi_default, nullptr},
        {"EGL_TEXTURE_FORMAT ", nullptr, nullptr, nullptr, nullptr, NapiCreateInt32(env, EGL_TEXTURE_FORMAT),
         napi_default, nullptr},
        {"EGL_TEXTURE_TARGET ", nullptr, nullptr, nullptr, nullptr, NapiCreateInt32(env, EGL_TEXTURE_TARGET),
         napi_default, nullptr},
        {"EGL_VG_ALPHA_FORMAT ", nullptr, nullptr, nullptr, nullptr, NapiCreateInt32(env, EGL_VG_ALPHA_FORMAT),
         napi_default, nullptr},
        {"EGL_VG_COLORSPACE ", nullptr, nullptr, nullptr, nullptr, NapiCreateInt32(env, EGL_VG_COLORSPACE),
         napi_default, nullptr},
        {"EGL_WIDTH ", nullptr, nullptr, nullptr, nullptr, NapiCreateInt32(env, EGL_WIDTH), napi_default, nullptr},
        {"EGL_SYNC_TYPE ", nullptr, nullptr, nullptr, nullptr, NapiCreateInt32(env, EGL_SYNC_TYPE), napi_default,
         nullptr},
        {"EGL_SYNC_STATUS ", nullptr, nullptr, nullptr, nullptr, NapiCreateInt32(env, EGL_SYNC_STATUS), napi_default,
         nullptr},
        {"EGL_SYNC_CONDITION ", nullptr, nullptr, nullptr, nullptr, NapiCreateInt32(env, EGL_SYNC_CONDITION),
         napi_default, nullptr},
        {"EGL_GL_TEXTURE_LEVEL ", nullptr, nullptr, nullptr, nullptr, NapiCreateInt32(env, EGL_GL_TEXTURE_LEVEL),
         napi_default, nullptr},
        {"EGL_GL_TEXTURE_ZOFFSET ", nullptr, nullptr, nullptr, nullptr, NapiCreateInt32(env, EGL_GL_TEXTURE_ZOFFSET),
         napi_default, nullptr},
        {"EGL_IMAGE_PRESERVED ", nullptr, nullptr, nullptr, nullptr, NapiCreateInt32(env, EGL_IMAGE_PRESERVED),
         napi_default, nullptr},
        {"EGL_RENDER_BUFFER ", nullptr, nullptr, nullptr, nullptr, NapiCreateInt32(env, EGL_RENDER_BUFFER),
         napi_default, nullptr},
        {"EGL_CONTEXT_MAJOR_VERSION ", nullptr, nullptr, nullptr, nullptr,
         NapiCreateInt32(env, EGL_CONTEXT_MAJOR_VERSION), napi_default, nullptr},
        {"EGL_CONTEXT_MINOR_VERSION ", nullptr, nullptr, nullptr, nullptr,
         NapiCreateInt32(env, EGL_CONTEXT_MINOR_VERSION), napi_default, nullptr},
        {"EGL_CONTEXT_OPENGL_PROFILE_MASK ", nullptr, nullptr, nullptr, nullptr,
         NapiCreateInt32(env, EGL_CONTEXT_OPENGL_PROFILE_MASK), napi_default, nullptr},
        {"EGL_CONTEXT_OPENGL_DEBUG ", nullptr, nullptr, nullptr, nullptr,
         NapiCreateInt32(env, EGL_CONTEXT_OPENGL_DEBUG), napi_default, nullptr},
        {"EGL_CONTEXT_OPENGL_FORWARD_COMPATIBLE ", nullptr, nullptr, nullptr, nullptr,
         NapiCreateInt32(env, EGL_CONTEXT_OPENGL_FORWARD_COMPATIBLE), napi_default, nullptr},
        {"EGL_CONTEXT_OPENGL_ROBUST_ACCESS ", nullptr, nullptr, nullptr, nullptr,
         NapiCreateInt32(env, EGL_CONTEXT_OPENGL_ROBUST_ACCESS), napi_default, nullptr},
        {"EGL_CONTEXT_OPENGL_RESET_NOTIFICATION_STRATEGY ", nullptr, nullptr, nullptr, nullptr,
         NapiCreateInt32(env, EGL_CONTEXT_OPENGL_RESET_NOTIFICATION_STRATEGY), napi_default, nullptr},
        {"EGL_CONTEXT_CLIENT_VERSION ", nullptr, nullptr, nullptr, nullptr,
         NapiCreateInt32(env, EGL_CONTEXT_CLIENT_VERSION), napi_default, nullptr},
        {"EGL_DONT_CARE ", nullptr, nullptr, nullptr, nullptr, NapiCreateInt32(env, EGL_DONT_CARE), napi_default,
         nullptr},
        {"EGL_TRUE ", nullptr, nullptr, nullptr, nullptr, NapiCreateInt32(env, EGL_TRUE), napi_default, nullptr},
        {"EGL_FALSE ", nullptr, nullptr, nullptr, nullptr, NapiCreateInt32(env, EGL_FALSE), napi_default, nullptr},
        {"EGL_RGB_BUFFER ", nullptr, nullptr, nullptr, nullptr, NapiCreateInt32(env, EGL_RGB_BUFFER), napi_default,
         nullptr},
        {"EGL_LUMINANCE_BUFFER ", nullptr, nullptr, nullptr, nullptr, NapiCreateInt32(env, EGL_LUMINANCE_BUFFER),
         napi_default, nullptr},
        {"EGL_NONE ", nullptr, nullptr, nullptr, nullptr, NapiCreateInt32(env, EGL_NONE), napi_default, nullptr},
        {"EGL_SLOW_CONFIG ", nullptr, nullptr, nullptr, nullptr, NapiCreateInt32(env, EGL_SLOW_CONFIG), napi_default,
         nullptr},
        {"EGL_NON_CONFORMANT_CONFIG ", nullptr, nullptr, nullptr, nullptr,
         NapiCreateInt32(env, EGL_NON_CONFORMANT_CONFIG), napi_default, nullptr},
        {"EGL_OPENGL_BIT ", nullptr, nullptr, nullptr, nullptr, NapiCreateInt32(env, EGL_OPENGL_BIT), napi_default,
         nullptr},
        {"EGL_OPENGL_ES_BIT ", nullptr, nullptr, nullptr, nullptr, NapiCreateInt32(env, EGL_OPENGL_ES_BIT),
         napi_default, nullptr},
        {"EGL_OPENGL_ES2_BIT ", nullptr, nullptr, nullptr, nullptr, NapiCreateInt32(env, EGL_OPENGL_ES2_BIT),
         napi_default, nullptr},
        {"EGL_OPENVG_BIT ", nullptr, nullptr, nullptr, nullptr, NapiCreateInt32(env, EGL_OPENVG_BIT), napi_default,
         nullptr},
        {"EGL_MULTISAMPLE_RESOLVE_BOX_BIT ", nullptr, nullptr, nullptr, nullptr,
         NapiCreateInt32(env, EGL_MULTISAMPLE_RESOLVE_BOX_BIT), napi_default, nullptr},
        {"EGL_PBUFFER_BIT ", nullptr, nullptr, nullptr, nullptr, NapiCreateInt32(env, EGL_PBUFFER_BIT), napi_default,
         nullptr},
        {"EGL_PIXMAP_BIT ", nullptr, nullptr, nullptr, nullptr, NapiCreateInt32(env, EGL_PIXMAP_BIT), napi_default,
         nullptr},
        {"EGL_SWAP_BEHAVIOR_PRESERVED_BIT ", nullptr, nullptr, nullptr, nullptr,
         NapiCreateInt32(env, EGL_SWAP_BEHAVIOR_PRESERVED_BIT), napi_default, nullptr},
        {"EGL_VG_ALPHA_FORMAT_PRE_BIT ", nullptr, nullptr, nullptr, nullptr,
         NapiCreateInt32(env, EGL_VG_ALPHA_FORMAT_PRE_BIT), napi_default, nullptr},
        {"EGL_VG_COLORSPACE_LINEAR_BIT ", nullptr, nullptr, nullptr, nullptr,
         NapiCreateInt32(env, EGL_VG_COLORSPACE_LINEAR_BIT), napi_default, nullptr},
        {"EGL_WINDOW_BIT ", nullptr, nullptr, nullptr, nullptr, NapiCreateInt32(env, EGL_WINDOW_BIT), napi_default,
         nullptr},
        {"EGL_TRANSPARENT_RGB ", nullptr, nullptr, nullptr, nullptr, NapiCreateInt32(env, EGL_TRANSPARENT_RGB),
         napi_default, nullptr},
        {"EGL_GL_COLORSPACE_SRGB ", nullptr, nullptr, nullptr, nullptr, NapiCreateInt32(env, EGL_GL_COLORSPACE_SRGB),
         napi_default, nullptr},
        {"EGL_GL_COLORSPACE_LINEAR ", nullptr, nullptr, nullptr, nullptr,
         NapiCreateInt32(env, EGL_GL_COLORSPACE_LINEAR), napi_default, nullptr},
        {"EGL_NO_TEXTURE ", nullptr, nullptr, nullptr, nullptr, NapiCreateInt32(env, EGL_NO_TEXTURE), napi_default,
         nullptr},
        {"EGL_TEXTURE_RGB ", nullptr, nullptr, nullptr, nullptr, NapiCreateInt32(env, EGL_TEXTURE_RGB), napi_default,
         nullptr},
        {"EGL_TEXTURE_RGBA ", nullptr, nullptr, nullptr, nullptr, NapiCreateInt32(env, EGL_TEXTURE_RGBA), napi_default,
         nullptr},
        {"EGL_TEXTURE_2D ", nullptr, nullptr, nullptr, nullptr, NapiCreateInt32(env, EGL_TEXTURE_2D), napi_default,
         nullptr},
        {"EGL_VG_ALPHA_FORMAT_NONPRE ", nullptr, nullptr, nullptr, nullptr,
         NapiCreateInt32(env, EGL_VG_ALPHA_FORMAT_NONPRE), napi_default, nullptr},
        {"EGL_VG_ALPHA_FORMAT_PRE ", nullptr, nullptr, nullptr, nullptr, NapiCreateInt32(env, EGL_VG_ALPHA_FORMAT_PRE),
         napi_default, nullptr},
        {"EGL_VG_COLORSPACE_sRGB ", nullptr, nullptr, nullptr, nullptr, NapiCreateInt32(env, EGL_VG_COLORSPACE_sRGB),
         napi_default, nullptr},
        {"EGL_VG_COLORSPACE_LINEAR ", nullptr, nullptr, nullptr, nullptr,
         NapiCreateInt32(env, EGL_VG_COLORSPACE_LINEAR), napi_default, nullptr},
        {"EGL_SYNC_FENCE ", nullptr, nullptr, nullptr, nullptr, NapiCreateInt32(env, EGL_SYNC_FENCE), napi_default,
         nullptr},
        {"EGL_UNSIGNALED ", nullptr, nullptr, nullptr, nullptr, NapiCreateInt32(env, EGL_UNSIGNALED), napi_default,
         nullptr},
        {"EGL_SIGNALED ", nullptr, nullptr, nullptr, nullptr, NapiCreateInt32(env, EGL_SIGNALED), napi_default,
         nullptr},
        {"EGL_SYNC_PRIOR_COMMANDS_COMPLETE ", nullptr, nullptr, nullptr, nullptr,
         NapiCreateInt32(env, EGL_SYNC_PRIOR_COMMANDS_COMPLETE), napi_default, nullptr},
        {"EGL_GL_TEXTURE_2D ", nullptr, nullptr, nullptr, nullptr, NapiCreateInt32(env, EGL_GL_TEXTURE_2D),
         napi_default, nullptr},
        {"EGL_GL_TEXTURE_CUBE_MAP_POSITIVE_X ", nullptr, nullptr, nullptr, nullptr,
         NapiCreateInt32(env, EGL_GL_TEXTURE_CUBE_MAP_POSITIVE_X), napi_default, nullptr},
        {"EGL_GL_TEXTURE_CUBE_MAP_NEGATIVE_X ", nullptr, nullptr, nullptr, nullptr,
         NapiCreateInt32(env, EGL_GL_TEXTURE_CUBE_MAP_NEGATIVE_X), napi_default, nullptr},
        {"EGL_GL_TEXTURE_CUBE_MAP_POSITIVE_Y ", nullptr, nullptr, nullptr, nullptr,
         NapiCreateInt32(env, EGL_GL_TEXTURE_CUBE_MAP_POSITIVE_Y), napi_default, nullptr},
        {"EGL_GL_TEXTURE_CUBE_MAP_NEGATIVE_Y ", nullptr, nullptr, nullptr, nullptr,
         NapiCreateInt32(env, EGL_GL_TEXTURE_CUBE_MAP_NEGATIVE_Y), napi_default, nullptr},
        {"EGL_GL_TEXTURE_CUBE_MAP_POSITIVE_Z ", nullptr, nullptr, nullptr, nullptr,
         NapiCreateInt32(env, EGL_GL_TEXTURE_CUBE_MAP_POSITIVE_Z), napi_default, nullptr},
        {"EGL_GL_TEXTURE_CUBE_MAP_NEGATIVE_Z ", nullptr, nullptr, nullptr, nullptr,
         NapiCreateInt32(env, EGL_GL_TEXTURE_CUBE_MAP_NEGATIVE_Z), napi_default, nullptr},
        {"EGL_GL_TEXTURE_3D ", nullptr, nullptr, nullptr, nullptr, NapiCreateInt32(env, EGL_GL_TEXTURE_3D),
         napi_default, nullptr},
        {"EGL_GL_RENDERBUFFER ", nullptr, nullptr, nullptr, nullptr, NapiCreateInt32(env, EGL_GL_RENDERBUFFER),
         napi_default, nullptr},
        {"EGL_SINGLE_BUFFER ", nullptr, nullptr, nullptr, nullptr, NapiCreateInt32(env, EGL_SINGLE_BUFFER),
         napi_default, nullptr},
        {"EGL_BACK_BUFFER ", nullptr, nullptr, nullptr, nullptr, NapiCreateInt32(env, EGL_BACK_BUFFER), napi_default,
         nullptr},
        {"EGL_CONTEXT_OPENGL_CORE_PROFILE_BIT ", nullptr, nullptr, nullptr, nullptr,
         NapiCreateInt32(env, EGL_CONTEXT_OPENGL_CORE_PROFILE_BIT), napi_default, nullptr},
        {"EGL_CONTEXT_OPENGL_COMPATIBILITY_PROFILE_BIT ", nullptr, nullptr, nullptr, nullptr,
         NapiCreateInt32(env, EGL_CONTEXT_OPENGL_COMPATIBILITY_PROFILE_BIT), napi_default, nullptr},
        {"EGL_LOSE_CONTEXT_ON_RESET ", nullptr, nullptr, nullptr, nullptr,
         NapiCreateInt32(env, EGL_LOSE_CONTEXT_ON_RESET), napi_default, nullptr},
        {"EGL_NO_RESET_NOTIFICATION ", nullptr, nullptr, nullptr, nullptr,
         NapiCreateInt32(env, EGL_NO_RESET_NOTIFICATION), napi_default, nullptr},
        {"EGL_OPENVG_IMAGE ", nullptr, nullptr, nullptr, nullptr, NapiCreateInt32(env, EGL_OPENVG_IMAGE), napi_default,
         nullptr},
        {"EGL_OPENGL_API ", nullptr, nullptr, nullptr, nullptr, NapiCreateInt32(env, EGL_OPENGL_API), napi_default,
         nullptr},
        {"EGL_OPENGL_ES_API ", nullptr, nullptr, nullptr, nullptr, NapiCreateInt32(env, EGL_OPENGL_ES_API),
         napi_default, nullptr},
        {"EGL_OPENVG_API ", nullptr, nullptr, nullptr, nullptr, NapiCreateInt32(env, EGL_OPENVG_API), napi_default,
         nullptr},


    };

    /*  napi_value cons = nullptr;
      napi_define_class(env, class_name, NAPI_AUTO_LENGTH, nullptr, nullptr, sizeof(desc) / sizeof(desc[0]), desc,
      &cons);

      napi_set_named_property(env, exports, class_name, cons);*/
    NapiCreateInt32(env, EGL_SUCCESS);
    napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
}


napi_value NapiEGLInitialize(napi_env env, napi_callback_info info) {

    size_t argc = 2;
    napi_value argv[2];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    EGLDisplay display = Ptr::NapiGetPtr(env, argv[0]);
    EGLint major = 0, minor = 0;

    EGLBoolean result = eglInitialize(display, &major, &minor);

    napi_set_named_property(env, argv[1], "major", NapiCreateInt32(env, major));
    napi_set_named_property(env, argv[1], "minor", NapiCreateInt32(env, minor));
    return NapiCreateInt32(env, result);
}


napi_value NapiEGLGetDisplay(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value argv[1];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    void *display_id = Ptr::NapiGetPtr(env, argv[0]);

    EGLDisplay display = eglGetDisplay(static_cast<EGLNativeDisplayType>(display_id));

    return Ptr::NapiCreatePtr(env, display);
}


napi_value NapiEGLChooseConfig(napi_env env, napi_callback_info info) {
    size_t argc = 4;
    napi_value argv[4];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    EGLDisplay display = Ptr::NapiGetPtr(env, argv[0]);
    EGLint *attrib_list = getEGLintList(env, argv[1]);
    EGLint config_size = 0;

    napi_get_value_int32(env, argv[2], &config_size);

    EGLConfig *configs = new EGLConfig[config_size];
    EGLint num_config = 0;
    EGLBoolean result = eglChooseConfig(display, attrib_list, configs, config_size, &num_config);

    for (int i = 0; i < num_config; i++) {
        napi_value ptr = Ptr::NapiCreatePtr(env, configs[i]);
        napi_set_element(env, argv[3], i, ptr);
    }

    freeEGLIntList(&attrib_list);
    delete[] configs;

    return NapiCreateInt32(env, result);
}

napi_value NapiEGLCopyBuffers(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value argv[3];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    EGLDisplay display = Ptr::NapiGetPtr(env, argv[0]);
    EGLSurface surface = Ptr::NapiGetPtr(env, argv[1]);
    EGLNativePixmapType target = Ptr::NapiGetPtr(env, argv[2]);

    return NapiCreateInt32(env, eglCopyBuffers(display, surface, target));
}

napi_value NapiEGLCreateContext(napi_env env, napi_callback_info info) {
    size_t argc = 4;
    napi_value argv[4];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    EGLDisplay egl_display = Ptr::NapiGetPtr(env, argv[0]);
    EGLConfig egl_config = Ptr::NapiGetPtr(env, argv[1]);
    EGLContext share_context = Ptr::NapiGetPtr(env, argv[2]);

    EGLint *attrib_list = getEGLintList(env, argv[3]);
    EGLContext context = eglCreateContext(egl_display, egl_config, share_context, attrib_list);

    freeEGLIntList(&attrib_list);

    return Ptr::NapiCreatePtr(env, context);
}

napi_value NapiEGLGetError(napi_env env, napi_callback_info info) {
    EGLint error = eglGetError();
    napi_value result;
    napi_create_int32(env, error, &result);
    return result;
}


napi_value NapiEGLCreatePbufferSurface(napi_env env, napi_callback_info info) {
    napi_value argv[3];
    size_t argc = 3;
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    EGLDisplay display = Ptr::NapiGetPtr(env, argv[0]);
    EGLConfig config = Ptr::NapiGetPtr(env, argv[1]);
    EGLint *attrib_list = getEGLintList(env, argv[2]);

    EGLSurface surface = eglCreatePbufferSurface(display, config, attrib_list);

    freeEGLIntList(&attrib_list);
    return Ptr::NapiCreatePtr(env, surface);
}

napi_value NapiEGLCreatePixmapSurface(napi_env env, napi_callback_info info) {
    napi_value argv[4];
    size_t argc = 4;

    EGLDisplay display = Ptr::NapiGetPtr(env, argv[0]);
    EGLConfig config = Ptr::NapiGetPtr(env, argv[1]);
    EGLNativePixmapType pixmap = Ptr::NapiGetPtr(env, argv[2]);
    EGLint *attrib_list = getEGLintList(env, argv[3]);

    EGLSurface surface = eglCreatePixmapSurface(display, config, pixmap, attrib_list);
    freeEGLIntList(&attrib_list);

    return Ptr::NapiCreatePtr(env, surface);
}

napi_value NapiEGLCreateWindowSurface(napi_env env, napi_callback_info info) {
    size_t argc = 4;
    napi_value argv[4];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    EGLDisplay display = Ptr::NapiGetPtr(env, argv[0]);
    EGLConfig config = Ptr::NapiGetPtr(env, argv[1]);
    void *win = Ptr::NapiGetPtr(env, argv[2]);
    EGLint *attrib_list = getEGLintList(env, argv[3]);

    EGLSurface surface = eglCreateWindowSurface(display, config, static_cast<EGLNativeWindowType>(win), attrib_list);

    freeEGLIntList(&attrib_list);

    return Ptr::NapiCreatePtr(env, surface);
}

napi_value NapiEGLDestroyContext(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value argv[2];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    EGLDisplay display = Ptr::NapiGetPtr(env, argv[0]);
    EGLContext context = Ptr::NapiGetPtr(env, argv[1]);

    return NapiCreateInt32(env, eglDestroyContext(display, context));
}

napi_value NapiEGLDestroySurface(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value argv[2];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    EGLDisplay display = Ptr::NapiGetPtr(env, argv[0]);
    EGLSurface surface = Ptr::NapiGetPtr(env, argv[1]);

    return NapiCreateInt32(env, eglDestroySurface(display, surface));
}

napi_value NapiEGLGetConfigAttrib(napi_env env, napi_callback_info info) {
    size_t argc = 4;
    napi_value argv[4];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    EGLDisplay display = Ptr::NapiGetPtr(env, argv[0]);
    EGLConfig config = Ptr::NapiGetPtr(env, argv[1]);
    EGLint attribute = 0;
    void *value = nullptr;
    napi_get_value_int32(env, argv[2], &attribute);
    napi_get_typedarray_info(env, argv[3], nullptr, nullptr, &value, nullptr, 0);

    EGLBoolean r = eglGetConfigAttrib(display, config, attribute, (EGLint *)value);

    return NapiCreateInt32(env, r);
}

napi_value NapiEGLGetConfigs(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value argv[3];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    EGLDisplay display = Ptr::NapiGetPtr(env, argv[0]);

    EGLint config_size = 0;
    napi_get_value_int32(env, argv[1], &config_size);

    EGLConfig *configs = new EGLConfig[config_size];
    EGLint num_config = 0;

    EGLBoolean r = eglGetConfigs(display, configs, config_size, &num_config);
    napi_handle_scope scope = nullptr;
    napi_open_handle_scope(env, &scope);
    for (int i = 0; i < num_config; i++) {
        EGLConfig config = configs[i];
        napi_set_element(env, argv[2], i, Ptr::NapiCreatePtr(env, config));
    }
    napi_close_handle_scope(env, scope);

    delete[] configs;

    return NapiCreateInt32(env, r);
}

napi_value NapiEGLGetCurrentDisplay(napi_env env, napi_callback_info info) {
    EGLDisplay display = eglGetCurrentDisplay();
    return Ptr::NapiCreatePtr(env, display);
}

napi_value NapiEGLGetCurrentSurface(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value argv[1];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    EGLint readdraw = 0;
    napi_get_value_int32(env, argv[0], &readdraw);
    EGLSurface surface = eglGetCurrentSurface(readdraw);
    return Ptr::NapiCreatePtr(env, surface);
}

napi_value NapiEGLGetProcAddress(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value argv[1];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    char procName[256];
    size_t size = 256;
    napi_get_value_string_utf8(env, argv[0], procName, size, &size);
    auto ptr = eglGetProcAddress(procName);
    return Ptr::NapiCreatePtr(env, (void *)ptr);
}

napi_value NapiEGLMakeCurrent(napi_env env, napi_callback_info info) {
    napi_value argv[4];
    size_t argc = 4;
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    EGLDisplay display = Ptr::NapiGetPtr(env, argv[0]);
    EGLSurface draw = Ptr::NapiGetPtr(env, argv[1]);
    EGLSurface read = Ptr::NapiGetPtr(env, argv[2]);
    EGLContext context = Ptr::NapiGetPtr(env, argv[3]);

    EGLBoolean result = eglMakeCurrent(display, draw, read, context);
    return NapiCreateInt32(env, result);
}

napi_value NapiEGLQueryContext(napi_env env, napi_callback_info info) {
    size_t argc = 4;
    napi_value argv[4];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    EGLDisplay display = Ptr::NapiGetPtr(env, argv[0]);
    EGLContext context = Ptr::NapiGetPtr(env, argv[1]);
    EGLint attribute = 0;
    void *value = nullptr;

    napi_get_value_int32(env, argv[2], &attribute);
    napi_get_typedarray_info(env, argv[3], nullptr, nullptr, &value, nullptr, nullptr);

    EGLBoolean r = eglQueryContext(display, context, attribute, (EGLint *)value);

    return NapiCreateInt32(env, r);
}

napi_value NapiEGLQueryString(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value argv[2];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    EGLDisplay display = Ptr::NapiGetPtr(env, argv[0]);
    EGLint name = 0;
    napi_get_value_int32(env, argv[1], &name);

    const char *str = eglQueryString(display, name);
    napi_value result = nullptr;

    napi_create_string_utf8(env, str, NAPI_AUTO_LENGTH, &result);
    return result;
}

napi_value NapiEGLQuerySurface(napi_env env, napi_callback_info info) {
    size_t argc = 4;
    napi_value argv[4];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    EGLDisplay display = Ptr::NapiGetPtr(env, argv[0]);
    EGLSurface surface = Ptr::NapiGetPtr(env, argv[1]);
    EGLint attribute = 0;
    void *value = nullptr;
    napi_get_value_int32(env, argv[2], &attribute);
    napi_get_typedarray_info(env, argv[3], nullptr, nullptr, &value, nullptr, nullptr);

    EGLBoolean r = eglQuerySurface(display, surface, attribute, (EGLint *)value);

    return NapiCreateInt32(env, r);
}

napi_value NapiEGLSwapBuffers(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value argv[2];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    EGLDisplay display = Ptr::NapiGetPtr(env, argv[0]);
    EGLSurface surface = Ptr::NapiGetPtr(env, argv[1]);

    EGLBoolean r = eglSwapBuffers(display, surface);
    return NapiCreateInt32(env, r);
}

napi_value NapiEGLTerminate(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value argv[1];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    EGLDisplay display = Ptr::NapiGetPtr(env, argv[0]);

    EGLBoolean r = eglTerminate(display);
    return NapiCreateInt32(env, r);
}

napi_value NapiEGLWaitGL(napi_env env, napi_callback_info info) {
    EGLBoolean r = eglWaitGL();
    return NapiCreateInt32(env, r);
}

napi_value NapiEGLWaitNative(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value argv[1];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    EGLint engine = 0;
    napi_get_value_int32(env, argv[0], &engine);
    return NapiCreateInt32(env, eglWaitNative(engine));
}

napi_value NapiEGLBindTexImage(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value argv[3];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    EGLDisplay display = Ptr::NapiGetPtr(env, argv[0]);
    EGLSurface surface = Ptr::NapiGetPtr(env, argv[1]);
    EGLint buffer = 0;
    napi_get_value_int32(env, argv[2], &buffer);

    return NapiCreateInt32(env, eglBindTexImage(display, surface, buffer));
}

napi_value NapiEGLReleaseTexImage(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value argv[3];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    EGLDisplay display = Ptr::NapiGetPtr(env, argv[0]);
    EGLSurface surface = Ptr::NapiGetPtr(env, argv[1]);
    EGLint buffer = 0;

    napi_get_value_int32(env, argv[2], &buffer);
    return NapiCreateInt32(env, eglReleaseTexImage(display, surface, buffer));
}

napi_value NapiEGLSurfaceAttrib(napi_env env, napi_callback_info info) {
    size_t argc = 4;
    napi_value argv[4];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    EGLDisplay display = Ptr::NapiGetPtr(env, argv[0]);
    EGLSurface surface = Ptr::NapiGetPtr(env, argv[1]);
    EGLint attribute = 0;
    EGLint value = 0;
    napi_get_value_int32(env, argv[2], &attribute);
    napi_get_value_int32(env, argv[3], &value);
    return NapiCreateInt32(env, eglSurfaceAttrib(display, surface, attribute, value));
}

napi_value NapiEGLSwapInterval(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value argv[2];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    EGLDisplay display = Ptr::NapiGetPtr(env, argv[0]);
    EGLint interval = 0;
    napi_get_value_int32(env, argv[1], &interval);

    return NapiCreateInt32(env, eglSwapInterval(display, interval));
}

napi_value NapiEGLBindAPI(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value argv[1];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    int32_t api = EGL_OPENGL_ES_API;
    napi_get_value_int32(env, argv[0], &api);
    return NapiCreateInt32(env, eglBindAPI(api));
}

napi_value NapiEGLQueryAPI(napi_env env, napi_callback_info info) { return NapiCreateInt32(env, eglQueryAPI()); }

napi_value NapiEGLCreatePbufferFromClientBuffer(napi_env env, napi_callback_info info) {
    size_t argc = 5;
    napi_value argv[5];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    EGLDisplay display = Ptr::NapiGetPtr(env, argv[0]);
    int32_t buftype = 0;
    EGLClientBuffer buffer = Ptr::NapiGetPtr(env, argv[2]);
    EGLConfig config = Ptr::NapiGetPtr(env, argv[3]);
    EGLint *attrib_list = getEGLintList(env, argv[4]);

    napi_get_value_int32(env, argv[1], &buftype);

    EGLSurface surface = eglCreatePbufferFromClientBuffer(display, buftype, buffer, config, attrib_list);

    freeEGLIntList(&attrib_list);

    return Ptr::NapiCreatePtr(env, surface);
}

napi_value NapiEGLReleaseThread(napi_env env, napi_callback_info info) {
    return NapiCreateInt32(env, eglReleaseThread());
}

napi_value NapiEGLWaitClient(napi_env env, napi_callback_info info) { return NapiCreateInt32(env, eglWaitClient()); }

napi_value NapiEGLGetCurrentContext(napi_env env, napi_callback_info info) {
    return Ptr::NapiCreatePtr(env, eglGetCurrentContext());
}

napi_value NapiEGLCreateSync(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value argv[3];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    EGLDisplay display = Ptr::NapiGetPtr(env, argv[0]);
    int32_t type = 0;
    EGLAttrib *attrib_list = getEGLAttribList(env, argv[2]);
    napi_get_value_int32(env, argv[1], &type);
    EGLSync sync = eglCreateSync(display, type, attrib_list);

    freeEGLAttribList(&attrib_list);
    return Ptr::NapiCreatePtr(env, sync);
}

napi_value NapiEGLDestroySync(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value argv[2];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    EGLDisplay display = Ptr::NapiGetPtr(env, argv[0]);
    EGLSync sync = Ptr::NapiGetPtr(env, argv[1]);
    return NapiCreateInt32(env, eglDestroySync(display, sync));
}

napi_value NapiEGLClientWaitSync(napi_env env, napi_callback_info info) {
    size_t argc = 4;
    napi_value argv[4];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    EGLDisplay display = Ptr::NapiGetPtr(env, argv[0]);
    EGLSync sync = Ptr::NapiGetPtr(env, argv[1]);
    EGLint flags = 0;
    long timeout = 0;
    napi_get_value_int32(env, argv[2], &flags);
    napi_get_value_int64(env, argv[3], &timeout);
    return NapiCreateInt32(env, eglClientWaitSync(display, sync, flags, timeout));
}

napi_value NapiEGLGetSyncAttrib(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value argv[3];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    EGLDisplay display = Ptr::NapiGetPtr(env, argv[0]);
    EGLSync sync = Ptr::NapiGetPtr(env, argv[1]);
    EGLint attribute = 0;
    void *value = nullptr;
    napi_get_value_int32(env, argv[2], &attribute);
    napi_get_typedarray_info(env, argv[3], nullptr, nullptr, &value, nullptr, nullptr);

    EGLBoolean r = eglGetSyncAttrib(display, sync, attribute, (EGLAttrib *)value);

    return NapiCreateInt32(env, r);
}

napi_value NapiEGLCreateImage(napi_env env, napi_callback_info info) {
    size_t argc = 5;
    napi_value argv[5];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    EGLDisplay display = Ptr::NapiGetPtr(env, argv[0]);
    EGLContext context = Ptr::NapiGetPtr(env, argv[1]);
    int32_t target = 0;
    EGLClientBuffer buffer = Ptr::NapiGetPtr(env, argv[3]);
    EGLAttrib *attrib_list = getEGLAttribList(env, argv[4]);
    napi_get_value_int32(env, argv[2], &target);

    EGLImage image = eglCreateImage(display, context, target, buffer, attrib_list);

    freeEGLAttribList(&attrib_list);

    return Ptr::NapiCreatePtr(env, image);
}
napi_value NapiEGLDestroyImage(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value argv[2];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    EGLDisplay display = Ptr::NapiGetPtr(env, argv[0]);
    EGLImage image = Ptr::NapiGetPtr(env, argv[1]);

    return NapiCreateInt32(env, eglDestroyImage(display, image));
}

napi_value NapiEGLGetPlatformDisplay(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value argv[3];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    int32_t platform = 0;
    void *native_display = Ptr::NapiGetPtr(env, argv[1]);
    EGLAttrib *attrib_list = getEGLAttribList(env, argv[2]);
    napi_get_value_int32(env, argv[0], &platform);
    EGLDisplay display = eglGetPlatformDisplay(platform, native_display, attrib_list);

    freeEGLAttribList(&attrib_list);

    return Ptr::NapiCreatePtr(env, display);
}

napi_value NapiEGLCreatePlatformWindowSurface(napi_env env, napi_callback_info info) {
    size_t argc = 4;
    napi_value argv[4];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    EGLDisplay display = Ptr::NapiGetPtr(env, argv[0]);
    EGLConfig config = Ptr::NapiGetPtr(env, argv[1]);
    void *native_window = Ptr::NapiGetPtr(env, argv[2]);
    EGLAttrib *attrib_list = getEGLAttribList(env, argv[3]);

    EGLSurface surface = eglCreatePlatformWindowSurface(display, config, native_window, attrib_list);

    freeEGLAttribList(&attrib_list);

    return Ptr::NapiCreatePtr(env, surface);
}

napi_value NapiEGLCreatePlatformPixmapSurface(napi_env env, napi_callback_info info) {
    size_t argc = 4;
    napi_value argv[4];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    EGLDisplay display = Ptr::NapiGetPtr(env, argv[0]);
    EGLConfig config = Ptr::NapiGetPtr(env, argv[1]);
    void *native_pixmap = Ptr::NapiGetPtr(env, argv[2]);
    EGLAttrib *attrib_list = getEGLAttribList(env, argv[3]);

    EGLSurface surface = eglCreatePlatformPixmapSurface(display, config, native_pixmap, attrib_list);

    freeEGLAttribList(&attrib_list);

    return Ptr::NapiCreatePtr(env, surface);
}

napi_value NapiEGLWaitSync(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value argv[3];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    EGLDisplay display = Ptr::NapiGetPtr(env, argv[0]);
    EGLSync sync = Ptr::NapiGetPtr(env, argv[1]);
    EGLint flags = 0;
    napi_get_value_int32(env, argv[2], &flags);

    return NapiCreateInt32(env, eglWaitSync(display, sync, flags));
}

napi_value NapiEGLCreatePlatformWindowSurfaceEXT(napi_env env, napi_callback_info info) { return nullptr; }
napi_value NapiEGLCreatePlatformPixmapSurfaceEXT(napi_env env, napi_callback_info info) { return nullptr; }
napi_value NapiEGLSwapBuffersWithDamageEXT(napi_env env, napi_callback_info info) { return nullptr; }
}