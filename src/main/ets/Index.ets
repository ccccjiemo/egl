import * as EGLBase from 'libegl.so'

export namespace egl {
  export type EGLDisplay = EGLBase.EGLDisplay;

  export type EGLConfig = EGLBase.EGLConfig;

  export type EGLSurface = EGLBase.EGLSurface;

  export type EGLContext = EGLBase.EGLContext;

  export type EGLNativeWindowType = EGLBase.EGLNativeWindowType;

  export type EGLNativePixmapType = EGLBase.EGLNativePixmapType;

  export type EGLNativeDisplayType = EGLBase.EGLNativeDisplayType;

  export type EGLClientBuffer = EGLBase.EGLClientBuffer;

  export type EGLAttrib = EGLBase.EGLAttrib;

  export type EGLint = EGLBase.EGLint;

  export type EGLSync = EGLBase.EGLSync;

  export type EGLTime = EGLBase.EGLTime;

  export type EGLImage = EGLBase.EGLImage;

  export type EGLBoolean = 1 | 0;

  export interface EGLVersion {
    major?: EGLint;
    minor?: EGLint;
  }

  export enum EGLImageType {
    EGL_GL_TEXTURE_2D = 0x30B1,
    EGL_GL_TEXTURE_CUBE_MAP_POSITIVE_X = 0x30B3,
    EGL_GL_TEXTURE_CUBE_MAP_NEGATIVE_X = 0x30B4,
    EGL_GL_TEXTURE_CUBE_MAP_POSITIVE_Y = 0x30B5,
    EGL_GL_TEXTURE_CUBE_MAP_NEGATIVE_Y = 0x30B6,
    EGL_GL_TEXTURE_CUBE_MAP_POSITIVE_Z = 0x30B7,
    EGL_GL_TEXTURE_CUBE_MAP_NEGATIVE_Z = 0x30B8,
    EGL_GL_TEXTURE_3D = 0x30B2,
    EGL_GL_RENDERBUFFER = 0x30B9
  }

  export enum EGLError {
    EGL_SUCCESS = 0x3000,
    EGL_NOT_INITIALIZED = 0x3001,
    EGL_BAD_ACCESS = 0x3002,
    EGL_BAD_ALLOC = 0x3003,
    EGL_BAD_ATTRIBUTE = 0x3004,
    EGL_BAD_CONFIG = 0x3005,
    EGL_BAD_CONTEXT = 0x3006,
    EGL_BAD_CURRENT_SURFACE = 0x3007,
    EGL_BAD_DISPLAY = 0x3008,
    EGL_BAD_MATCH = 0x3009,
    EGL_BAD_NATIVE_PIXMAP = 0x300A,
    EGL_BAD_NATIVE_WINDOW = 0x300B,
    EGL_BAD_PARAMETER = 0x300C,
    EGL_BAD_SURFACE = 0x300D,
  }

  export enum EGLApi {
    EGL_OPENGL_API = 0x30A2,
    EGL_OPENGL_ES_API = 0x30A0,
    EGL_OPENVG_API = 0x30A1
  }

  export enum EGLBufferType {
    EGL_OPENVG_IMAGE = 0x3096
  }

  export enum EGLSyncType {
    EGL_SYNC_FENCE = 0x30F9
  }

  export enum EGLPlatform {
    EGL_PLATFORM_X11_EXT = 0x31D5,
    EGL_PLATFORM_X11_SCREEN_EXT = 0x31D6,
    EGL_PLATFORM_XCB_EXT = 0x31DC,
    EGL_PLATFORM_XCB_SCREEN_EXT = 0x31DE,
    EGL_PLATFORM_DEVICE_EXT = 0x313F,
    EGL_PLATFORM_WAYLAND_EXT = 0x31D8,
    EGL_PLATFORM_ANDROID_KHR = 0x3141,
    EGL_PLATFORM_OHOS_KHR = 0x34E0,
    EGL_PLATFORM_GBM_KHR = 0x31D7,
    EGL_PLATFORM_X11_KHR = 0x31D5,
    EGL_PLATFORM_X11_SCREEN_KHR = 0x31D6,
    EGL_PRESENT_OPAQUE_EXT = 0x31DF,
    EGL_PROTECTED_CONTENT_EXT = 0x32C0,
    EGL_PLATFORM_GBM_MESA = 0x31D7,
    EGL_PLATFORM_SURFACELESS_MESA = 0x31DD
  }

  export const eglChooseConfig: (dpy: EGLDisplay, attrib_list: EGLint[], config_size: EGLint,
    configs: EGLConfig[]) => EGLBoolean = EGLBase.eglChooseConfig;

  export const eglCopyBuffers: (dpy: EGLDisplay, surface: EGLSurface, target: EGLNativePixmapType) => EGLBoolean =
    EGLBase.eglCopyBuffers;

  export const eglCreateContext: (dpy: EGLDisplay, config: EGLConfig, share_context: EGLContext,
    attrib_list: EGLint[]) => EGLContext = EGLBase.eglCreateContext;

  export const eglCreatePbufferSurface: (dpy: EGLDisplay, config: EGLConfig, attrib_list?: EGLint[]) => EGLSurface =
    EGLBase.eglCreatePbufferSurface;

  export const eglCreatePixmapSurface: (dpy: EGLDisplay, config: EGLConfig, pixmap: EGLNativePixmapType,
    attrib_list?: EGLint[]) => EGLSurface = EGLBase.eglCreatePixmapSurface;

  export const eglCreateWindowSurface: (dpy: EGLDisplay, config: EGLConfig, win: EGLNativeWindowType,
    attrib_list?: EGLint[]) => EGLSurface = EGLBase.eglCreateWindowSurface;

  export const eglDestroyContext: (dpy: EGLDisplay, context: EGLContext) => EGLBoolean = EGLBase.eglDestroyContext;

  export const eglDestroySurface: (dpy: EGLDisplay, surface: EGLSurface) => EGLBoolean = EGLBase.eglDestroySurface;

  export const eglGetConfigAttrib: (dpy: EGLDisplay, config: EGLConfig, attribute: EGLint,
    value: Int32Array) => EGLBoolean = EGLBase.eglGetConfigAttrib;

  export const eglGetConfigs: (dpy: EGLDisplay, config_size: EGLint, configs: EGLConfig[]) => EGLBoolean =
    EGLBase.eglGetConfigs;

  export const eglGetCurrentDisplay: () => EGLDisplay = EGLBase.eglGetCurrentDisplay;

  export const eglGetCurrentSurface: (readdraw: EGLint) => EGLSurface = EGLBase.eglGetCurrentSurface;

  export const eglGetDisplay: (display_id: EGLNativeDisplayType) => EGLDisplay = EGLBase.eglGetDisplay;

  export const eglGetError: () => EGLError = EGLBase.eglGetError;

  export const eglGetProcAddress: (procName: string) => string = EGLBase.eglGetProcAddress;

  export const eglInitialize: (dpy: EGLDisplay, versions: EGLVersion) => EGLBoolean = EGLBase.eglInitialize;

  export const eglMakeCurrent: (dpy: EGLDisplay, draw: EGLSurface, read: EGLSurface,
    context: EGLContext) => EGLBoolean = EGLBase.eglMakeCurrent;

  export const eglQueryContext: (dpy: EGLDisplay, context: EGLContext, attribute: EGLint,
    value: Int32Array) => EGLBoolean = EGLBase.eglQueryContext;

  export const eglQueryString: (dpy: EGLDisplay, name: EGLint) => string = EGLBase.eglQueryString;

  export const eglQuerySurface: (dpy: EGLDisplay, surface: EGLSurface, attribute: EGLint,
    value: Int32Array) => EGLBoolean = EGLBase.eglQuerySurface;

  export const eglSwapBuffers: (dpy: EGLDisplay, surface: EGLSurface) => EGLBoolean = EGLBase.eglSwapBuffers;

  export const eglTerminate: (dpy: EGLDisplay) => EGLBoolean = EGLBase.eglTerminate;

  export const eglWaitGL: () => EGLBoolean = EGLBase.eglWaitGL;

  export const eglWaitNative: (engine: EGLint) => EGLBoolean = EGLBase.eglWaitNative;

  export const eglBindTexImage: (dpy: EGLDisplay, surface: EGLSurface, buffer: EGLint) => EGLBoolean =
    EGLBase.eglBindTexImage;

  export const eglReleaseTexImage: (dpy: EGLDisplay, surface: EGLSurface, buffer: EGLint) => EGLBoolean =
    EGLBase.eglReleaseTexImage;

  export const eglSurfaceAttrib: (dpy: EGLDisplay, surface: EGLSurface, attribute: EGLint,
    value: EGLint) => EGLBoolean = EGLBase.eglSurfaceAttrib;

  export const eglSwapInterval: (dpy: EGLDisplay, interval: EGLint) => EGLBoolean = EGLBase.eglSwapInterval;

  export const eglBindAPI: (api: EGLApi) => EGLBoolean = EGLBase.eglBindAPI;

  export const eglQueryAPI: () => EGLApi = EGLBase.eglQueryAPI;

  export const eglCreatePbufferFromClientBuffer: (dpy: EGLDisplay, buftype: EGLBufferType, buffer: EGLClientBuffer,
    config: EGLConfig, attrib_list?: EGLint[]) => EGLSurface = EGLBase.eglCreatePbufferFromClientBuffer;

  export const eglReleaseThread: () => EGLBoolean = EGLBase.eglReleaseThread;

  export const eglWaitClient: () => EGLBoolean = EGLBase.eglWaitClient;

  export const eglGetCurrentContext: () => EGLContext = EGLBase.eglGetCurrentContext;

  export const eglCreateSync: (dpy: EGLDisplay, type: EGLSyncType, attrib_list?: EGLAttrib[]) => EGLSync =
    EGLBase.eglCreateSync;

  export const eglDestroySync: (dpy: EGLDisplay, sync: EGLSync) => EGLBoolean = EGLBase.eglDestroySync;

  export const eglClientWaitSync: (dpy: EGLDisplay, sync: EGLSync, flags: EGLint, timeout: EGLTime) => EGLint =
    EGLBase.eglClientWaitSync;

  export const eglGetSyncAttrib: (dpy: EGLDisplay, sync: EGLSync, attribute: EGLint,
    value: BigInt64Array) => EGLBoolean = EGLBase.eglGetSyncAttrib;

  export const eglCreateImage: (dpy: EGLDisplay, context: EGLContext, target: EGLImageType, buffer: EGLClientBuffer,
    attrib_list: EGLAttrib[]) => EGLImage = EGLBase.eglCreateImage;

  export const eglDestroyImage: (dpy: EGLDisplay, image: EGLImage) => EGLBoolean = EGLBase.eglDestroyImage;

  export const eglGetPlatformDisplay: (platform: EGLPlatform | EGLint, native_display: string | null,
    attrib_list?: EGLAttrib[]) => EGLDisplay = EGLBase.eglGetPlatformDisplay;

  export const eglCreatePlatformWindowSurface: (dpy: EGLDisplay, config: EGLConfig, native_window: string | null,
    attrib_list?: EGLAttrib[]) => EGLSurface = EGLBase.eglCreatePlatformWindowSurface;

  export const eglCreatePlatformPixmapSurface: (dpy: EGLDisplay, config: EGLConfig, native_pixmap: string | null,
    attrib_list?: EGLAttrib[]) => EGLSurface = EGLBase.eglCreatePlatformPixmapSurface;

  export const eglWaitSync: (dpy: EGLDisplay, sync: EGLSync, flags: EGLint) => EGLBoolean = EGLBase.eglWaitSync;

  export const EGL_NO_SURFACE: EGLSurface = null;

  export const EGL_NO_CONTEXT: EGLContext = null;

  export const EGL_NO_CONFIG: EGLConfig = null;

  export const EGL_NO_DISPLAY: EGLDisplay = null;

  export const EGL_DEFAULT_DISPLAY: EGLNativeDisplayType = null;

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

