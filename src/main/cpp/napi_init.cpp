#include "egl/EGLHelper.h"
#include "napi/native_api.h"


static napi_value NAPI_Global_EGL_ALPHA_MASK_SIZE(napi_env env, napi_callback_info info) {
    // TODO: implements the code;
}
EXTERN_C_START
static napi_value Init(napi_env env, napi_value exports) {
    EGL::Export(env, exports);

    napi_property_descriptor desc[] = {
        {"eglChooseConfig", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglCopyBuffers", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglCreateContext", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglCreatePbufferSurface", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglCreatePixmapSurface", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglCreateWindowSurface", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglDestroyContext", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglDestroySurface", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglGetConfigAttrib", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglGetConfigs", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglGetCurrentDisplay", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglGetCurrentSurface", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglGetDisplay", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglGetError", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglGetProcAddress", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglInitialize", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglMakeCurrent", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglQueryContext", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglQueryString", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglQuerySurface", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglSwapBuffers", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglTerminate", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglWaitGL", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglWaitNative", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglBindTexImage", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglReleaseTexImage", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglSurfaceAttrib", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglSwapInterval", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglBindAPI", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglQueryAPI", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglCreatePbufferFromClientBuffer", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglReleaseThread", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglWaitClient", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglGetCurrentContext", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglCreateSync", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglDestroySync", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglClientWaitSync", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglGetSyncAttrib", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglCreateImage", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglDestroyImage", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglGetPlatformDisplay", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglCreatePlatformWindowSurface", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglCreatePlatformPixmapSurface", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglWaitSync", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglCreatePlatformWindowSurfaceEXT", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglCreatePlatformPixmapSurfaceEXT", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"eglSwapBuffersWithDamageEXT", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"EGL_ALPHA_SIZE", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"EGL_BIND_TO_TEXTURE_RGB", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"EGL_BIND_TO_TEXTURE_RGBA", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"EGL_BUFFER_SIZE", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"EGL_BLUE_SIZE", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"EGL_RED_SIZE", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"EGL_COLOR_BUFFER_TYPE", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"EGL_CONFIG_CAVEAT", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"EGL_CONFIG_ID", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"EGL_CONFORMANT", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"EGL_DEPTH_SIZE", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"EGL_GREEN_SIZE", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"EGL_LEVEL", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"EGL_LUMINANCE_SIZE", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"EGL_MATCH_NATIVE_PIXMAP", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"EGL_NATIVE_RENDERABLE", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"EGL_MAX_SWAP_INTERVAL", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"EGL_MIN_SWAP_INTERVAL", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"EGL_SAMPLE_BUFFERS", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"EGL_SAMPLES", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"EGL_STENCIL_SIZE", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"EGL_RENDERABLE_TYPE", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"EGL_SURFACE_TYPE", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"EGL_TRANSPARENT_TYPE", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"EGL_TRANSPARENT_RED_VALUE", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"EGL_TRANSPARENT_GREEN_VALUE", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"EGL_TRANSPARENT_BLUE_VALUE", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"EGL_GL_COLORSPACE", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"EGL_HEIGHT", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"EGL_LARGEST_PBUFFER", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"EGL_MIPMAP_TEXTURE", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"EGL_TEXTURE_FORMAT", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"EGL_TEXTURE_TARGET", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"EGL_VG_ALPHA_FORMAT", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"EGL_VG_COLORSPACE", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"EGL_WIDTH", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"EGL_SYNC_TYPE", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"EGL_SYNC_STATUS", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"EGL_SYNC_CONDITION", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"EGL_GL_TEXTURE_LEVEL", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"EGL_GL_TEXTURE_ZOFFSET", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"EGL_IMAGE_PRESERVED", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"EGL_RENDER_BUFFER", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"EGL_CONTEXT_MAJOR_VERSION", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"EGL_CONTEXT_MINOR_VERSION", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"EGL_CONTEXT_OPENGL_PROFILE_MASK", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"EGL_CONTEXT_OPENGL_DEBUG", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"EGL_CONTEXT_OPENGL_FORWARD_COMPATIBLE", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"EGL_CONTEXT_OPENGL_ROBUST_ACCESS", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"EGL_CONTEXT_OPENGL_RESET_NOTIFICATION_STRATEGY", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default,
         nullptr},
        {"EGL_CONTEXT_CLIENT_VERSION", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"EGL_DONT_CARE", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"EGL_TRUE", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"EGL_FALSE", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"EGL_RGB_BUFFER", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"EGL_LUMINANCE_BUFFER", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"EGL_NONE", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"EGL_SLOW_CONFIG", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"EGL_NON_CONFORMANT_CONFIG", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"EGL_OPENGL_BIT", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"EGL_OPENGL_ES_BIT", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"EGL_OPENGL_ES2_BIT", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"EGL_OPENVG_BIT", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"EGL_MULTISAMPLE_RESOLVE_BOX_BIT", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"EGL_PBUFFER_BIT", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"EGL_PIXMAP_BIT", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"EGL_SWAP_BEHAVIOR_PRESERVED_BIT", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"EGL_VG_ALPHA_FORMAT_PRE_BIT", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"EGL_VG_COLORSPACE_LINEAR_BIT", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"EGL_WINDOW_BIT", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"EGL_TRANSPARENT_RGB", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"EGL_GL_COLORSPACE_SRGB", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"EGL_GL_COLORSPACE_LINEAR", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"EGL_NO_TEXTURE", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"EGL_TEXTURE_RGB", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"EGL_TEXTURE_RGBA", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"EGL_TEXTURE_2D", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"EGL_VG_ALPHA_FORMAT_NONPRE", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"EGL_VG_ALPHA_FORMAT_PRE", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"EGL_VG_COLORSPACE_sRGB", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"EGL_VG_COLORSPACE_LINEAR", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"EGL_SYNC_FENCE", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"EGL_UNSIGNALED", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"EGL_SIGNALED", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"EGL_SYNC_PRIOR_COMMANDS_COMPLETE", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"EGL_GL_TEXTURE_2D", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"EGL_GL_TEXTURE_CUBE_MAP_POSITIVE_X", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"EGL_GL_TEXTURE_CUBE_MAP_NEGATIVE_X", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"EGL_GL_TEXTURE_CUBE_MAP_POSITIVE_Y", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"EGL_GL_TEXTURE_CUBE_MAP_NEGATIVE_Y", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"EGL_GL_TEXTURE_CUBE_MAP_POSITIVE_Z", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"EGL_GL_TEXTURE_CUBE_MAP_NEGATIVE_Z", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"EGL_GL_TEXTURE_3D", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"EGL_GL_RENDERBUFFER", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"EGL_SINGLE_BUFFER", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"EGL_BACK_BUFFER", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"EGL_CONTEXT_OPENGL_CORE_PROFILE_BIT", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"EGL_CONTEXT_OPENGL_COMPATIBILITY_PROFILE_BIT", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default,
         nullptr},
        {"EGL_LOSE_CONTEXT_ON_RESET", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"EGL_NO_RESET_NOTIFICATION", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"EGL_OPENVG_IMAGE", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"EGL_OPENGL_API", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"EGL_OPENGL_ES_API", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"EGL_OPENVG_API", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"EGL_ALPHA_MASK_SIZE", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, nullptr},


    };

    return exports;
}
EXTERN_C_END

static napi_module demoModule = {
    .nm_version = 1,
    .nm_flags = 0,
    .nm_filename = nullptr,
    .nm_register_func = Init,
    .nm_modname = "egl",
    .nm_priv = ((void *)0),
    .reserved = {0},
};

extern "C" __attribute__((constructor)) void RegisterEglModule(void) { napi_module_register(&demoModule); }
