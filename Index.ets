export * as egl from 'libegl.so'

export namespace egl10 {
  export const EGL_DONT_CARE = -1;

  export const EGL_TRUE = 1;

  export const EGL_FALSE = 0;

  export const EGL_RGB_BUFFER = 0x308E;

  export const EGL_LUMINANCE_BUFFER = 0x308F;

  export const EGL_NONE = 0x3038;

  export const EGL_SLOW_CONFIG = 0x3050;

  export const EGL_NON_CONFORMANT_CONFIG = 0x3051;

  export const EGL_OPENGL_BIT = 0x0008;

  export const EGL_OPENGL_ES_BIT = 0x0001;

  export const EGL_OPENGL_ES2_BIT = 0x0004;

  export const EGL_OPENVG_BIT = 0x0002;

  export const EGL_MULTISAMPLE_RESOLVE_BOX_BIT = 0x0200;

  export const EGL_PBUFFER_BIT = 0x0001;

  export const EGL_PIXMAP_BIT = 0x0002;

  export const EGL_SWAP_BEHAVIOR_PRESERVED_BIT = 0x0400;

  export const EGL_VG_ALPHA_FORMAT_PRE_BIT = 0x0040;

  export const EGL_VG_COLORSPACE_LINEAR_BIT = 0x0020;

  export const EGL_WINDOW_BIT = 0x0004;

  export const EGL_TRANSPARENT_RGB = 0x3052;

  export const EGL_GL_COLORSPACE_SRGB = 0x3089;

  export const EGL_GL_COLORSPACE_LINEAR = 0x308A;

  export const EGL_NO_TEXTURE = 0x305C;

  export const EGL_TEXTURE_RGB = 0x305D;

  export const EGL_TEXTURE_RGBA = 0x305E;

  export const EGL_TEXTURE_2D = 0x305F;

  export const EGL_VG_ALPHA_FORMAT_NONPRE = 0x308B;

  export const EGL_VG_ALPHA_FORMAT_PRE = 0x308C;

  export const EGL_VG_COLORSPACE_sRGB = 0x3089;

  export const EGL_VG_COLORSPACE_LINEAR = 0x308A;

  export const EGL_SYNC_FENCE = 0x30F9;

  export const EGL_UNSIGNALED = 0x30F3;

  export const EGL_SIGNALED = 0x30F2;

  export const EGL_SYNC_PRIOR_COMMANDS_COMPLETE = 0x30F0;

  export const EGL_GL_TEXTURE_2D = 0x30B1;

  export const EGL_GL_TEXTURE_CUBE_MAP_POSITIVE_X = 0x30B3;

  export const EGL_GL_TEXTURE_CUBE_MAP_NEGATIVE_X = 0x30B4;

  export const EGL_GL_TEXTURE_CUBE_MAP_POSITIVE_Y = 0x30B5;

  export const EGL_GL_TEXTURE_CUBE_MAP_NEGATIVE_Y = 0x30B6;

  export const EGL_GL_TEXTURE_CUBE_MAP_POSITIVE_Z = 0x30B7;

  export const EGL_GL_TEXTURE_CUBE_MAP_NEGATIVE_Z = 0x30B8;

  export const EGL_GL_TEXTURE_3D = 0x30B2;

  export const EGL_GL_RENDERBUFFER = 0x30B9;

  export const EGL_SINGLE_BUFFER = 0x3085;

  export const EGL_BACK_BUFFER = 0x3084;

  export const EGL_CONTEXT_OPENGL_CORE_PROFILE_BIT = 0x00000001;

  export const EGL_CONTEXT_OPENGL_COMPATIBILITY_PROFILE_BIT = 0x00000002;

  export const EGL_LOSE_CONTEXT_ON_RESET = 0x31BF;

  export const EGL_NO_RESET_NOTIFICATION = 0x31BE;

  //attribkey
  export const EGL_ALPHA_MASK_SIZE = 0x303E;

  export const EGL_ALPHA_SIZE = 0x3021;

  export const EGL_BIND_TO_TEXTURE_RGB = 0x3039;

  export const EGL_BIND_TO_TEXTURE_RGBA = 0x303A;

  export const EGL_BUFFER_SIZE = 0x3020;

  export const EGL_BLUE_SIZE = 0x3022;

  export const EGL_RED_SIZE = 0X3024;

  export const EGL_COLOR_BUFFER_TYPE = 0x303F;

  export const EGL_CONFIG_CAVEAT = 0x3027;

  export const EGL_CONFIG_ID = 0x3028;

  export const EGL_CONFORMANT = 0x3042;

  export const EGL_DEPTH_SIZE = 0x3025;

  export const EGL_GREEN_SIZE = 0x3023;

  export const EGL_LEVEL = 0x3029;

  export const EGL_LUMINANCE_SIZE = 0x303D;

  export const EGL_MATCH_NATIVE_PIXMAP = 0x3041;

  export const EGL_NATIVE_RENDERABLE = 0x302D;

  export const EGL_MAX_SWAP_INTERVAL = 0x303C;

  export const EGL_MIN_SWAP_INTERVAL = 0x303B;

  export const EGL_SAMPLE_BUFFERS = 0x3032;

  export const EGL_SAMPLES = 0x3031;

  export const EGL_STENCIL_SIZE = 0x3026;

  export const EGL_RENDERABLE_TYPE = 0x3040;

  export const EGL_SURFACE_TYPE = 0x3033;

  export const EGL_TRANSPARENT_TYPE = 0x3034;

  export const EGL_TRANSPARENT_RED_VALUE = 0x3037;

  export const EGL_TRANSPARENT_GREEN_VALUE = 0x3036;

  export const EGL_TRANSPARENT_BLUE_VALUE = 0x3035;

  export const EGL_GL_COLORSPACE = 0x309D;

  export const EGL_HEIGHT = 0x3056;

  export const EGL_LARGEST_PBUFFER = 0x3058;

  export const EGL_MIPMAP_TEXTURE = 0x3082;

  export const EGL_TEXTURE_FORMAT = 0x3080;

  export const EGL_TEXTURE_TARGET = 0x3081;

  export const EGL_VG_ALPHA_FORMAT = 0x3088;

  export const EGL_VG_COLORSPACE = 0x3087;

  export const EGL_WIDTH = 0x3057;

  export const EGL_SYNC_TYPE = 0x30F7;

  export const EGL_SYNC_STATUS = 0x30F1;

  export const EGL_SYNC_CONDITION = 0x30F8;

  export const EGL_GL_TEXTURE_LEVEL = 0x30BC;

  export const EGL_GL_TEXTURE_ZOFFSET = 0x30BD;

  export const EGL_IMAGE_PRESERVED = 0x30D2;

  export const EGL_RENDER_BUFFER = 0x3086;

  export const EGL_CONTEXT_MAJOR_VERSION = 0x3098;

  export const EGL_CONTEXT_MINOR_VERSION = 0x30FB;

  export const EGL_CONTEXT_OPENGL_PROFILE_MASK = 0x30FD;

  export const EGL_CONTEXT_OPENGL_DEBUG = 0x31B0;

  export const EGL_CONTEXT_OPENGL_FORWARD_COMPATIBLE = 0x31B1;

  export const EGL_CONTEXT_OPENGL_ROBUST_ACCESS = 0x31B2;

  export const EGL_CONTEXT_OPENGL_RESET_NOTIFICATION_STRATEGY = 0x31BD;

  export const EGL_CONTEXT_CLIENT_VERSION = 0x3098;

}