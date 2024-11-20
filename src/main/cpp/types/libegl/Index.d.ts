type EGLSurface = string | null;

type EGLContext = string | null;

type EGLClientBuffer = string | null;

type EGLNativeDisplayType = string | null;

type EGLDisplay = string | null;

type EGLConfig = string | null;

type EGLNativeWindowType = string | null;

type EGLNativePixmapType = string | null;

type EGLint = number;

type EGLenum = number;

type EGLTime = number;

type EGLAttrib = number;

type EGLSync = string | null;

type EGLImage = string | null;

type EGLAttribList = EGLAttrib[];

export const EGL_DEFAULT_DISPLAY: EGLNativeDisplayType;

export const EGL_NO_CONTEXT: EGLContext;

export const EGL_NO_DISPLAY: EGLDisplay;

export const EGL_NO_SURFACE: EGLSurface;

export interface EGLVersion {
  major?: EGLint;
  minor?: EGLint;
}

export interface EGLAttributeKeyValue {
  attribute: EGLint;
  value?: EGLint | EGLAttrib;
}

/*
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
*/

/*

export enum EGLAttribKey {
  EGL_ALPHA_MASK_SIZE = 0x303E,
  EGL_ALPHA_SIZE = 0x3021,
  EGL_BIND_TO_TEXTURE_RGB = 0x3039,
  EGL_BIND_TO_TEXTURE_RGBA = 0x303A,
  EGL_BUFFER_SIZE = 0x3020,
  EGL_BLUE_SIZE = 0x3022,
  EGL_RED_SIZE = 0X3024,
  EGL_COLOR_BUFFER_TYPE = 0x303F,
  EGL_CONFIG_CAVEAT = 0x3027,
  EGL_CONFIG_ID = 0x3028,
  EGL_CONFORMANT = 0x3042,
  EGL_DEPTH_SIZE = 0x3025,
  EGL_GREEN_SIZE = 0x3023,
  EGL_LEVEL = 0x3029,
  EGL_LUMINANCE_SIZE = 0x303D,
  EGL_MATCH_NATIVE_PIXMAP = 0x3041,
  EGL_NATIVE_RENDERABLE = 0x302D,
  EGL_MAX_SWAP_INTERVAL = 0x303C,
  EGL_MIN_SWAP_INTERVAL = 0x303B,
  EGL_SAMPLE_BUFFERS = 0x3032,
  EGL_SAMPLES = 0x3031,
  EGL_STENCIL_SIZE = 0x3026,
  EGL_RENDERABLE_TYPE = 0x3040,
  EGL_SURFACE_TYPE = 0x3033,
  EGL_TRANSPARENT_TYPE = 0x3034,
  EGL_TRANSPARENT_RED_VALUE = 0x3037,
  EGL_TRANSPARENT_GREEN_VALUE = 0x3036,
  EGL_TRANSPARENT_BLUE_VALUE = 0x3035,
  EGL_GL_COLORSPACE = 0x309D,
  EGL_HEIGHT = 0x3056,
  EGL_LARGEST_PBUFFER = 0x3058,
  EGL_MIPMAP_TEXTURE = 0x3082,
  EGL_TEXTURE_FORMAT = 0x3080,
  EGL_TEXTURE_TARGET = 0x3081,
  EGL_VG_ALPHA_FORMAT = 0x3088,
  EGL_VG_COLORSPACE = 0x3087,
  EGL_WIDTH = 0x3057,
  EGL_SYNC_TYPE = 0x30F7,
  EGL_SYNC_STATUS = 0x30F1,
  EGL_SYNC_CONDITION = 0x30F8,
  EGL_GL_TEXTURE_LEVEL = 0x30BC,
  EGL_GL_TEXTURE_ZOFFSET = 0x30BD,
  EGL_IMAGE_PRESERVED = 0x30D2,
  EGL_RENDER_BUFFER = 0x3086,
  EGL_CONTEXT_MAJOR_VERSION = 0x3098,
  EGL_CONTEXT_MINOR_VERSION = 0x30FB,
  EGL_CONTEXT_OPENGL_PROFILE_MASK = 0x30FD,
  EGL_CONTEXT_OPENGL_DEBUG = 0x31B0,
  EGL_CONTEXT_OPENGL_FORWARD_COMPATIBLE = 0x31B1,
  EGL_CONTEXT_OPENGL_ROBUST_ACCESS = 0x31B2,
  EGL_CONTEXT_OPENGL_RESET_NOTIFICATION_STRATEGY = 0x31BD,
  EGL_CONTEXT_CLIENT_VERSION = 0x3098
}

export enum EGLAttribValue {
  EGL_DONT_CARE = -1,
  EGL_TRUE = 1,
  EGL_FALSE = 0,
  EGL_RGB_BUFFER = 0x308E,
  EGL_LUMINANCE_BUFFER = 0x308F,
  EGL_NONE = 0x3038,
  EGL_SLOW_CONFIG = 0x3050,
  EGL_NON_CONFORMANT_CONFIG = 0x3051,
  EGL_OPENGL_BIT = 0x0008,
  EGL_OPENGL_ES_BIT = 0x0001,
  EGL_OPENGL_ES2_BIT = 0x0004,
  EGL_OPENVG_BIT = 0x0002,
  EGL_MULTISAMPLE_RESOLVE_BOX_BIT = 0x0200,
  EGL_PBUFFER_BIT = 0x0001,
  EGL_PIXMAP_BIT = 0x0002,
  EGL_SWAP_BEHAVIOR_PRESERVED_BIT = 0x0400,
  EGL_VG_ALPHA_FORMAT_PRE_BIT = 0x0040,
  EGL_VG_COLORSPACE_LINEAR_BIT = 0x0020,
  EGL_WINDOW_BIT = 0x0004,
  EGL_TRANSPARENT_RGB = 0x3052,
  EGL_GL_COLORSPACE_SRGB = 0x3089,
  EGL_GL_COLORSPACE_LINEAR = 0x308A,
  EGL_NO_TEXTURE = 0x305C,
  EGL_TEXTURE_RGB = 0x305D,
  EGL_TEXTURE_RGBA = 0x305E,
  EGL_TEXTURE_2D = 0x305F,
  EGL_VG_ALPHA_FORMAT_NONPRE = 0x308B,
  EGL_VG_ALPHA_FORMAT_PRE = 0x308C,
  EGL_VG_COLORSPACE_sRGB = 0x3089,
  EGL_VG_COLORSPACE_LINEAR = 0x308A,
  EGL_SYNC_FENCE = 0x30F9,
  EGL_UNSIGNALED = 0x30F3,
  EGL_SIGNALED = 0x30F2,
  EGL_SYNC_PRIOR_COMMANDS_COMPLETE = 0x30F0,
  EGL_GL_TEXTURE_2D = 0x30B1,
  EGL_GL_TEXTURE_CUBE_MAP_POSITIVE_X = 0x30B3,
  EGL_GL_TEXTURE_CUBE_MAP_NEGATIVE_X = 0x30B4,
  EGL_GL_TEXTURE_CUBE_MAP_POSITIVE_Y = 0x30B5,
  EGL_GL_TEXTURE_CUBE_MAP_NEGATIVE_Y = 0x30B6,
  EGL_GL_TEXTURE_CUBE_MAP_POSITIVE_Z = 0x30B7,
  EGL_GL_TEXTURE_CUBE_MAP_NEGATIVE_Z = 0x30B8,
  EGL_GL_TEXTURE_3D = 0x30B2,
  EGL_GL_RENDERBUFFER = 0x30B9,
  EGL_SINGLE_BUFFER = 0x3085,
  EGL_BACK_BUFFER = 0x3084,
  EGL_CONTEXT_OPENGL_CORE_PROFILE_BIT = 0x00000001,
  EGL_CONTEXT_OPENGL_COMPATIBILITY_PROFILE_BIT = 0x00000002,
  EGL_LOSE_CONTEXT_ON_RESET = 0x31BF,
  EGL_NO_RESET_NOTIFICATION = 0x31BE,
}
*/

export enum EGLBoolean {
  EGL_TRUE = 1,
  EGL_FALSE = 0
}

/*export enum EGLApi {
  EGL_OPENGL_API = 0x30A2,
  EGL_OPENGL_ES_API = 0x30A0,
  EGL_OPENVG_API = 0x30A1
}*/

/*export enum EGLSyncType {
  EGL_SYNC_FENCE = 0x30F9
}*/

export enum EGLBufferType {
  EGL_OPENVG_IMAGE = 0x3096
}

/*export enum EGLImageType {
  EGL_GL_TEXTURE_2D = 0x30B1,
  EGL_GL_TEXTURE_CUBE_MAP_POSITIVE_X = 0x30B3,
  EGL_GL_TEXTURE_CUBE_MAP_NEGATIVE_X = 0x30B4,
  EGL_GL_TEXTURE_CUBE_MAP_POSITIVE_Y = 0x30B5,
  EGL_GL_TEXTURE_CUBE_MAP_NEGATIVE_Y = 0x30B6,
  EGL_GL_TEXTURE_CUBE_MAP_POSITIVE_Z = 0x30B7,
  EGL_GL_TEXTURE_CUBE_MAP_NEGATIVE_Z = 0x30B8,
  EGL_GL_TEXTURE_3D = 0x30B2,
  EGL_GL_RENDERBUFFER = 0x30B9
}*/

export function eglGetDisplay(display_id: EGLNativeDisplayType): EGLDisplay;

export function eglInitialize(dpy: EGLDisplay, versions: EGLVersion): EGLBoolean;

export function eglChooseConfig(dpy: EGLDisplay, attrib_list: EGLAttribList, config_size: EGLint,
  configs: EGLConfig[]): EGLBoolean;

export function eglCreateContext(dpy: EGLDisplay, config: EGLConfig, share_context: EGLContext,
  attrib_list: EGLint[]): EGLContext;

export function eglGetError(): EGLint;

export function eglCreateWindowSurface(dpy: EGLDisplay, config: EGLConfig, win: EGLNativeWindowType,
  attrib_list?: EGLint[]): EGLSurface;

export function eglMakeCurrent(dpy: EGLDisplay, draw: EGLSurface, read: EGLSurface, context: EGLContext): EGLBoolean;

export function eglCreatePbufferSurface(dpy: EGLDisplay, config: EGLConfig, attrib_list?: EGLAttribList): EGLSurface;

export function eglCopyBuffers(dpy: EGLDisplay, surface: EGLSurface, target: EGLNativePixmapType): EGLBoolean;

export function eglDestroyContext(dpy: EGLDisplay, context: EGLContext): EGLBoolean;

export function eglDestroySurface(dpy: EGLDisplay, surface: EGLSurface): EGLBoolean;

export function eglGetConfigAttrib(dpy: EGLDisplay, config: EGLConfig, attribute: EGLint,
  value: Int32Array): EGLBoolean;

export function eglGetConfigs(dpy: EGLDisplay, config_size: EGLint, configs: EGLConfig[]): EGLBoolean;

export function eglGetCurrentDisplay(): EGLDisplay;

export function eglGetCurrentSurface(readdraw: EGLint): EGLSurface;

export function eglGetProcAddress(procName: string): string;

export function eglQueryContext(dpy: EGLDisplay, context: EGLContext, attribute: EGLint, value: Int32Array): EGLBoolean;

export function eglQueryString(dpy: EGLDisplay, name: EGLint): string;

export function eglQuerySurface(dpy: EGLDisplay, surface: EGLSurface, attribute: EGLint, value: Int32Array): EGLBoolean;

export function eglSwapBuffers(dpy: EGLDisplay, surface: EGLSurface): EGLBoolean;

export function eglTerminate(dpy: EGLDisplay): EGLBoolean;

export function eglWaitGL(): EGLBoolean;

export function eglWaitNative(engine: EGLint): EGLBoolean;

export function eglBindTexImage(dpy: EGLDisplay, surface: EGLSurface, buffer: EGLint): EGLBoolean;

export function eglReleaseTexImage(dpy: EGLDisplay, surface: EGLSurface, buffer: EGLint): EGLBoolean;

export function eglSurfaceAttrib(dpy: EGLDisplay, surface: EGLSurface, attribute: EGLint, value: EGLint): EGLBoolean;

export function eglSwapInterval(dpy: EGLDisplay, interval: EGLint): EGLBoolean;

export function eglBindAPI(api: number): EGLBoolean;

export function eglQueryAPI(): number;

export function eglCreatePbufferFromClientBuffer(dpy: EGLDisplay, buftype: EGLenum, buffer: EGLClientBuffer,
  config: EGLConfig, attrib_list?: EGLAttribList): EGLSurface;

export function eglReleaseThread(): EGLBoolean

export function eglWaitClient(): EGLBoolean;

export function eglGetCurrentContext(): EGLContext;

export function eglCreateSync(dpy: EGLDisplay, type: EGLenum, attrib_list?: EGLAttribList): EGLSync;

export function eglDestroySync(dpy: EGLDisplay, sync: EGLSync): EGLBoolean;

export function eglClientWaitSync(dpy: EGLDisplay, sync: EGLSync, flags: EGLint, timeout: EGLTime): EGLint;

export function eglGetSyncAttrib(dpy: EGLDisplay, sync: EGLSync, attribute: EGLint, value: BigInt64Array): EGLBoolean;

export function eglCreateImage(dpy: EGLDisplay, context: EGLContext, target: EGLint, buffer: EGLClientBuffer,
  attrib_list: EGLAttribList): EGLImage;

export function eglDestroyImage(dpy: EGLDisplay, image: EGLImage): EGLBoolean;

export function eglGetPlatformDisplay(platform: EGLenum, native_display: string | null,
  attrib_list?: EGLAttribList): EGLDisplay;

export function eglCreatePlatformWindowSurface(dpy: EGLDisplay, config: EGLConfig, native_window: string | null,
  attrib_list?: EGLAttribList): EGLSurface;

export function eglCreatePlatformPixmapSurface(dpy: EGLDisplay, config: EGLConfig, native_pixmap: string | null,
  attrib_list?: EGLAttribList): EGLSurface;

export function eglWaitSync(dpy: EGLDisplay, sync: EGLSync, flags: EGLint): EGLBoolean;

export function eglCreatePixmapSurface(dpy: EGLDisplay, config: EGLConfig, pixmap: EGLNativePixmapType,
  attrib_list?: EGLAttribList): EGLSurface;



