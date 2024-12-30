import { image } from "@kit.ImageKit";


export namespace egl {

  interface EGLVersion {
    major: number;
    minjor: number;
  }

  /**

   * 创建一个OHNativeBuffer,使用完记得释放，对OHNativeBuffer的操作需要开发者实现napi
   */
  @Sendable
  class NativeBuffer {
    constructor(config: NativeBufferConfig);

    /***
     * 一定要释放
     */
    destroy(): boolean;
  }

  @Sendable
  class EGLConfig {
    private constructor();

    getConfigAttrib(dpy: EGLDisplay, attribute: EGLConfigAttribute): number | undefined;
  }

  @Sendable
  class EGLContext {
    private constructor();

    static getCurrentContext(): EGLContext | undefined;

    /**
     * eglQueryContext
     * 查询成功返回number否则undefined
     * @param attribute EGL_CONFIG_ID / EGL_CONTEXT_CLIENT_TYPE / EGL_CONTEXT_CLIENT_VERSION / EGL_RENDER_BUFFER
     */
    query(dpy: EGLDisplay, attribute: number): number | undefined;
  }

  @Sendable
  class EGLSurface {
    private constructor();

    static getCurrentSurface(readdraw: READDRAW): EGLSurface | undefined;

    /**
     * eglSurfaceAttrib
     * @param attribute EGL_MIPMAP_LEVEL / EGL_MULTISAMPLE_RESOLVE / EGL_SWAP_BEHAVIOR
     */
    setAttribute(dpy: EGLDisplay, attribute: number, value: number): boolean;

    /**
     * eglQuerySurface
     * @param attribute egl.EGLConfigAttribute
     */
    query(dpy: EGLDisplay, attribute: EGLConfigAttribute | number): number | undefined;

    /**
     * eglBindTexImage
     */
    bindTexImage(dpy: EGLDisplay, buffer: EGLConfigAttribute | number): boolean;

    /**
     * eglReleaseTexImage
     */
    releaseTexImage(dpy: EGLDisplay, buffer: EGLConfigAttribute | number): boolean;
  }

  @Sendable
  class EGLSync {
    private constructor();
  }

  @Sendable
  class EGLSyncKHR {
    private constructor()
  }

  @Sendable
  class EGLImage {
    private constructor()
  }

  @Sendable
  class EGLImageKHR {
    private constructor();
  }

  @Sendable
  class EGLDisplay {
    private constructor();

    /**
     * 获取EGLDisplay对象
     * @param eglNativeDisplayType 输入undefined获取default display
     * @returns
     */
    static getDisplay(eglNativeDisplayType?: string): EGLDisplay | undefined;

    static getCurrentDisplay(): EGLDisplay | undefined;

    static getPlatformDisplay(platform: EGLPlatform, native_display?: string,
      attrib_list?: number[]): EGLDisplay | undefined;

    /**
     * 调用eglInitialize,调用成功后，可以获取major和minjor
     * @returns EGLDisplay初始化是否成功
     */
    initialize(): EGLVersion | undefined;

    /**
     * 调用eglTerminate，终止与EGLDisplay的连接，终止连接后，调用其他方法会抛出异常
     * @returns 终止EGLDisplay是否成功。
     */
    terminate(): boolean;

    /**
     * 调用eglChooseConfig,获取EGLConfig
     * @returns 获取成功返回一个Config列表，否则undefined
     */
    chooseConfig(attrib_list: number[], count?: number): EGLConfig[] | undefined;

    /**
     * 调用eglCreateContext,获取上下文
     * @param config EGLConfig
     * @param share_context EGLContext
     * @param attrib_list EGLint[]
     * @returns
     */
    createContext(config: EGLConfig, share_context?: EGLContext, attrib_list?: number[]): EGLContext | undefined;

    /**
     * 创建surface
     * @param config EGLConfig(调用chooseConfig获取)
     * @param surfaceId 一般为NativeWindow/XComponent
     * @param attrib_list 配置表
     * @returns
     */
    createSurfaceWindow(config: EGLConfig, surfaceId: string, attrib_list?: number[]): EGLSurface | undefined;

    /**
     * 绑定线程与上下文
     * @param draw
     * @param read
     * @param context
     * @returns
     */
    makeCurrent(draw: EGLSurface | undefined, read: EGLSurface | undefined, context: EGLContext | undefined): boolean;

    /**
     * 创建离屏surface
     * @param config
     * @param attrib_list
     * @returns
     */
    createPbufferSurface(config: EGLConfig, attrib_list?: number[]): EGLSurface | undefined;

    /**
     * 销毁上下文
     * @param context
     * @returns
     */
    destroyContext(context: EGLContext): boolean;

    /**
     * 销毁surface
     * @param surface
     * @returns
     */
    destroySurface(surface: EGLSurface): boolean;

    /**
     *对应eglGetConfigs
     */
    getConfigs(count: number): EGLConfig[] | undefined;

    /**
     *eglQueryString
     */
    queryString(name: QueryStringNames): string | undefined;

    /**
     *eglSwapBuffers
     */
    swapBuffers(surface: EGLSurface): boolean;

    /**
     *eglCreateSync
     */
    createSync(type: EGLSyncType, attrib_list?: number[]): EGLSync | undefined;

    /**
     *eglDestroySync
     */
    destroySync(sync: EGLSync): boolean;

    /**
     *https://registry.khronos.org/EGL/sdk/docs/man/html/eglClientWaitSync.xhtml
     */
    clientWaitSync(sync: EGLSync, flags: number, timeout: number): number;

    /**
     * eglWaitSync
     * https://registry.khronos.org/EGL/sdk/docs/man/html/eglWaitSync.xhtml
     * @param flag must be 0?
     */
    waitSync(sync: EGLSync, flags: number): boolean;

    /**
     *https://registry.khronos.org/EGL/sdk/docs/man/html/eglGetSyncAttrib.xhtml
     * @param attribute EGL_SYNC_TYPE / EGL_SYNC_STATUS / EGL_SYNC_CONDITION
     */
    getSyncAttrib(sync: EGLSync, attribute: number): number | undefined;

    /**
     *eglSwapInterval
     */
    swapInterval(interval: number): boolean;

    /**
     * https://registry.khronos.org/EGL/sdk/docs/man/html/eglCreatePlatformPixmapSurface.xhtml
     * @param attrib_list EGL_GL_COLORSPACE / EGL_VG_ALPHA_FORMAT / EGL_VG_COLORSPACE
     */
    createPlatformPixmapSurface(config: EGLConfig, pixmap?: image.PixelMap,
      attrib_list?: number[]): EGLSurface | undefined;

    /**
     * https://registry.khronos.org/EGL/sdk/docs/man/html/eglCreatePlatformWindowSurface.xhtml
     * @param attrib_list EGL_GL_COLORSPACE / EGL_RENDER_BUFFER / EGL_VG_ALPHA_FORMAT / EGL_VG_COLORSPACE
     */
    createPlatformWindowSurface(config: EGLConfig, native_window_ptr?: string,
      attrib_list?: number[]): EGLSurface | undefined;

    /**
     *https://registry.khronos.org/EGL/sdk/docs/man/html/eglCreateImage.xhtml
     * @parm attr_list EGL_GL_TEXTURE_LEVEL / EGL_GL_TEXTURE_ZOFFSET / EGL_IMAGE?PRESERVER
     */
    createImageKHR(target: number, context: EGLContext, buffer: NativeBuffer,
      attrib_list?: number[]): EGLImageKHR | undefined;

    destroyImageKHR(image: EGLImageKHR): boolean;

    /**
     *个人测试不报错，但是拷贝不成功
     */
    copyBuffers(surface: EGLSurface, target: image.PixelMap): boolean;

    /**
     * OHOS好像不支持pixmapsurface
     */
    createPixmapSurface(config: EGLConfig, pixmap: image.PixelMap, attrib_list?: number[]): EGLSurface | undefined;
  }

  enum NativeBufferUsage {
    CPU_READ,
    CPU_WRITE,
    MEM_DMA,
    HW_RENDER,
    HW_TEXTURE,
    CPU_READ_OFTEN,
    ALIGNMENT_512
  }

  enum NativeBufferFormat {
    CLUT8,
    CLUT1,
    CLUT4,
    RGB_565,
    RGBA_5658,
    RGBX_4444,
    RGBA_4444,
    RGB_444,
    RGBX_5551,
    RGBA_5551,
    RGB_555,
    RGBX_8888,
    RGBA_8888,
    RGB_888,
    BGR_565,
    BGRX_4444,
    BGRA_4444,
    BGRX_5551,
    BGRA_5551,
    BGRX_8888,
    BGRA_8888,
    YUV_422_I,
    YUV_422_SP,
    YCRCB_422_SP,
    YCBCR_420_SP,
    YCBCR_422_P,
    YCRCB_422_P,
    YCBCR_420_P,
    YCRCB_420_P,
    YUYV_422_PKG,
    UYVY_422_PKG,
    YVYU_422_PKG,
    VYUY_422_PKG,
    RGBA_1010102,
    YCBCR_P010,
    YCRCB_P010,
    RAW10,
    VENDER_MASK,
    BUTT
  }

  interface NativeBufferConfig {
    width: number;
    height: number;
    format: NativeBufferFormat;
    usage: NativeBufferUsage;
    stride: number;
  }

  enum EGLConfigAttribute {
    EGL_ALPHA_SIZE,
    EGL_ALPHA_MASK_SIZE,
    EGL_BIND_TO_TEXTURE_RGB,
    EGL_BIND_TO_TEXTURE_RGBA,
    EGL_BLUE_SIZE,
    EGL_BUFFER_SIZE,
    EGL_COLOR_BUFFER_TYPE,
    EGL_CONFIG_CAVEAT,
    EGL_CONFIG_ID,
    EGL_CONFORMANT,
    EGL_DEPTH_SIZE,
    EGL_GREEN_SIZE,
    EGL_LEVEL,
    EGL_LUMINANCE_SIZE,
    EGL_MAX_PBUFFER_WIDTH,
    EGL_MAX_PBUFFER_HEIGHT,
    EGL_MAX_PBUFFER_PIXELS,
    EGL_MAX_SWAP_INTERVAL,
    EGL_MIN_SWAP_INTERVAL,
    EGL_NATIVE_RENDERABLE,
    EGL_NATIVE_VISUAL_ID,
    EGL_NATIVE_VISUAL_TYPE,
    EGL_RED_SIZE,
    EGL_RENDERABLE_TYPE,
    EGL_SAMPLE_BUFFERS,
    EGL_SAMPLES,
    EGL_STENCIL_SIZE,
    EGL_SURFACE_TYPE,
    EGL_TRANSPARENT_TYPE,
    EGL_TRANSPARENT_RED_VALUE,
    EGL_TRANSPARENT_GREEN_VALUE,
    EGL_TRANSPARENT_BLUE_VALUE,
  }

  enum EGLImageType {
    EGL_GL_TEXTURE_2D,
    EGL_GL_TEXTURE_CUBE_MAP_POSITIVE_X,
    EGL_GL_TEXTURE_CUBE_MAP_NEGATIVE_X,
    EGL_GL_TEXTURE_CUBE_MAP_POSITIVE_Y,
    EGL_GL_TEXTURE_CUBE_MAP_NEGATIVE_Y,
    EGL_GL_TEXTURE_CUBE_MAP_POSITIVE_Z,
    EGL_GL_TEXTURE_CUBE_MAP_NEGATIVE_Z,
    EGL_GL_TEXTURE_3D,
    EGL_GL_RENDERBUFFER,
  }

  enum EGLError {
    EGL_SUCCESS,
    EGL_NOT_INITIALIZED,
    EGL_BAD_ACCESS,
    EGL_BAD_ALLOC,
    EGL_BAD_ATTRIBUTE,
    EGL_BAD_CONFIG,
    EGL_BAD_CONTEXT,
    EGL_BAD_CURRENT_SURFACE,
    EGL_BAD_DISPLAY,
    EGL_BAD_MATCH,
    EGL_BAD_NATIVE_PIXMAP,
    EGL_BAD_NATIVE_WINDOW,
    EGL_BAD_PARAMETER,
    EGL_BAD_SURFACE,
  }

  enum EGLApi {
    EGL_OPENGL_API,
    EGL_OPENGL_ES_API,
    EGL_OPENVG_API,
  }

  enum EGLBufferType {
    EGL_OPENVG_IMAGE,
  }

  enum EGLSyncType {
    EGL_SYNC_FENCE,
  }

  enum EGLPlatform {
    EGL_PLATFORM_X11_EXT,
    EGL_PLATFORM_X11_SCREEN_EXT,
    EGL_PLATFORM_XCB_EXT,
    EGL_PLATFORM_XCB_SCREEN_EXT,
    EGL_PLATFORM_DEVICE_EXT,
    EGL_PLATFORM_WAYLAND_EXT,
    EGL_PLATFORM_ANDROID_KHR,
    EGL_PLATFORM_OHOS_KHR,
    EGL_PLATFORM_GBM_KHR,
    EGL_PLATFORM_X11_KHR,
    EGL_PLATFORM_X11_SCREEN_KHR,
    EGL_PRESENT_OPAQUE_EXT,
    EGL_PROTECTED_CONTENT_EXT,
    EGL_PLATFORM_GBM_MESA,
    EGL_PLATFORM_SURFACELESS_MESA,
  }

  enum READDRAW {
    EGL_READ,
    EGL_DRAW,
  }

  enum QueryStringNames {
    EGL_CLIENT_APIS,
    EGL_VENDOR,
    EGL_VERSION,
    EGL_EXTENSIONS,
  }

  export const EGL_NO_SURFACE: undefined;

  export const EGL_NO_CONTEXT: undefined;

  export const EGL_NO_CONFIG: undefined;

  export const EGL_NO_DISPLAY: undefined;

  export const EGL_DEFAULT_DISPLAY: undefined;

  export const EGL_DONT_CARE: number

  export const EGL_TRUE: number

  export const EGL_FALSE: number

  export const EGL_RGB_BUFFER: number

  export const EGL_LUMINANCE_BUFFER: number

  export const EGL_NONE: number

  export const EGL_SLOW_CONFIG: number

  export const EGL_NON_CONFORMANT_CONFIG: number

  export const EGL_OPENGL_BIT: number

  export const EGL_OPENGL_ES_BIT: number

  export const EGL_OPENGL_ES2_BIT: number

  export const EGL_OPENVG_BIT: number

  export const EGL_MULTISAMPLE_RESOLVE_BOX_BIT: number

  export const EGL_MULTISAMPLE_RESOLVE_DEFAULT: number

  export const EGL_MULTISAMPLE_RESOLVE_BOX: number

  export const EGL_PBUFFER_BIT: number

  export const EGL_PIXMAP_BIT: number

  export const EGL_SWAP_BEHAVIOR_PRESERVED_BIT: number

  export const EGL_VG_ALPHA_FORMAT_PRE_BIT: number

  export const EGL_VG_COLORSPACE_LINEAR_BIT: number

  export const EGL_WINDOW_BIT: number

  export const EGL_TRANSPARENT_RGB: number

  export const EGL_GL_COLORSPACE_SRGB: number

  export const EGL_GL_COLORSPACE_LINEAR: number

  export const EGL_NO_TEXTURE: number

  export const EGL_TEXTURE_RGB: number

  export const EGL_TEXTURE_RGBA: number

  export const EGL_TEXTURE_2D: number

  export const EGL_VG_ALPHA_FORMAT_NONPRE: number

  export const EGL_VG_ALPHA_FORMAT_PRE: number

  export const EGL_VG_COLORSPACE_sRGB: number

  export const EGL_VG_COLORSPACE_LINEAR: number

  export const EGL_SYNC_FENCE: number

  export const EGL_UNSIGNALED: number

  export const EGL_SIGNALED: number

  export const EGL_SYNC_PRIOR_COMMANDS_COMPLETE: number

  export const EGL_GL_TEXTURE_2D: number

  export const EGL_GL_TEXTURE_CUBE_MAP_POSITIVE_X: number

  export const EGL_GL_TEXTURE_CUBE_MAP_NEGATIVE_X: number

  export const EGL_GL_TEXTURE_CUBE_MAP_POSITIVE_Y: number

  export const EGL_GL_TEXTURE_CUBE_MAP_NEGATIVE_Y: number

  export const EGL_GL_TEXTURE_CUBE_MAP_POSITIVE_Z: number

  export const EGL_GL_TEXTURE_CUBE_MAP_NEGATIVE_Z: number

  export const EGL_GL_TEXTURE_3D: number

  export const EGL_GL_RENDERBUFFER: number

  export const EGL_SINGLE_BUFFER: number

  export const EGL_BACK_BUFFER: number

  export const EGL_CONTEXT_OPENGL_CORE_PROFILE_BIT: number

  export const EGL_CONTEXT_OPENGL_COMPATIBILITY_PROFILE_BIT: number

  export const EGL_LOSE_CONTEXT_ON_RESET: number

  export const EGL_NO_RESET_NOTIFICATION: number

  //attribkey
  export const EGL_ALPHA_MASK_SIZE: number

  export const EGL_ALPHA_SIZE: number

  export const EGL_BIND_TO_TEXTURE_RGB: number

  export const EGL_BIND_TO_TEXTURE_RGBA: number

  export const EGL_BUFFER_SIZE: number

  export const EGL_BLUE_SIZE: number

  export const EGL_RED_SIZE: number

  export const EGL_COLOR_BUFFER_TYPE: number

  export const EGL_CONFIG_CAVEAT: number

  export const EGL_CONFIG_ID: number

  export const EGL_CONFORMANT: number

  export const EGL_DEPTH_SIZE: number

  export const EGL_GREEN_SIZE: number

  export const EGL_LEVEL: number

  export const EGL_LUMINANCE_SIZE: number

  export const EGL_MATCH_NATIVE_PIXMAP: number

  export const EGL_NATIVE_RENDERABLE: number

  export const EGL_MAX_SWAP_INTERVAL: number

  export const EGL_MIN_SWAP_INTERVAL: number

  export const EGL_SAMPLE_BUFFERS: number

  export const EGL_SAMPLES: number

  export const EGL_STENCIL_SIZE: number

  export const EGL_RENDERABLE_TYPE: number

  export const EGL_SURFACE_TYPE: number

  export const EGL_TRANSPARENT_TYPE: number

  export const EGL_TRANSPARENT_RED_VALUE: number

  export const EGL_TRANSPARENT_GREEN_VALUE: number

  export const EGL_TRANSPARENT_BLUE_VALUE: number

  export const EGL_GL_COLORSPACE: number

  export const EGL_HEIGHT: number

  export const EGL_LARGEST_PBUFFER: number

  export const EGL_MIPMAP_TEXTURE: number

  export const EGL_TEXTURE_FORMAT: number

  export const EGL_TEXTURE_TARGET: number

  export const EGL_VG_ALPHA_FORMAT: number

  export const EGL_VG_COLORSPACE: number

  export const EGL_WIDTH: number

  export const EGL_SYNC_TYPE: number

  export const EGL_SYNC_STATUS: number

  export const EGL_SYNC_CONDITION: number

  export const EGL_GL_TEXTURE_LEVEL: number

  export const EGL_GL_TEXTURE_ZOFFSET: number

  export const EGL_IMAGE_PRESERVED: number

  export const EGL_RENDER_BUFFER: number

  export const EGL_CONTEXT_MAJOR_VERSION: number

  export const EGL_CONTEXT_MINOR_VERSION: number

  export const EGL_CONTEXT_OPENGL_PROFILE_MASK: number

  export const EGL_CONTEXT_OPENGL_DEBUG: number

  export const EGL_CONTEXT_OPENGL_FORWARD_COMPATIBLE: number

  export const EGL_CONTEXT_OPENGL_ROBUST_ACCESS: number

  export const EGL_CONTEXT_OPENGL_RESET_NOTIFICATION_STRATEGY: number

  export const EGL_CONTEXT_CLIENT_VERSION: number

  /***
   * KHR ext
   */
  export const EGL_CL_EVENT_HANDLE_KHR: number

  export const EGL_SYNC_CL_EVENT_KHR: number

  export const EGL_SYNC_CL_EVENT_COMPLETE_KHR: number

  export const EGL_CONFORMANT_KHR: number

  export const EGL_VG_COLORSPACE_LINEAR_BIT_KHR: number

  export const EGL_VG_ALPHA_FORMAT_PRE_BIT_KHR: number

  export const EGL_CONTEXT_RELEASE_BEHAVIOR_NONE_KHR: number

  export const EGL_CONTEXT_RELEASE_BEHAVIOR_KHR: number

  export const EGL_CONTEXT_RELEASE_BEHAVIOR_FLUSH_KHR: number

  export const EGL_CONTEXT_MAJOR_VERSION_KHR: number

  export const EGL_CONTEXT_MINOR_VERSION_KHR: number

  export const EGL_CONTEXT_FLAGS_KHR: number

  export const EGL_CONTEXT_OPENGL_PROFILE_MASK_KHR: number

  export const EGL_CONTEXT_OPENGL_RESET_NOTIFICATION_STRATEGY_KHR: number

  export const EGL_NO_RESET_NOTIFICATION_KHR: number

  export const EGL_LOSE_CONTEXT_ON_RESET_KHR: number

  export const EGL_CONTEXT_OPENGL_DEBUG_BIT_KHR: number

  export const EGL_CONTEXT_OPENGL_FORWARD_COMPATIBLE_BIT_KHR: number

  export const EGL_CONTEXT_OPENGL_ROBUST_ACCESS_BIT_KHR: number

  export const EGL_CONTEXT_OPENGL_CORE_PROFILE_BIT_KHR: number

  export const EGL_CONTEXT_OPENGL_COMPATIBILITY_PROFILE_BIT_KHR: number

  export const EGL_OPENGL_ES3_BIT_KHR: number

  export const EGL_CONTEXT_OPENGL_NO_ERROR_KHR: number

  export const EGL_OBJECT_THREAD_KHR: number

  export const EGL_OBJECT_DISPLAY_KHR: number

  export const EGL_OBJECT_CONTEXT_KHR: number

  export const EGL_OBJECT_SURFACE_KHR: number

  export const EGL_OBJECT_IMAGE_KHR: number

  export const EGL_OBJECT_SYNC_KHR: number

  export const EGL_OBJECT_STREAM_KHR: number

  export const EGL_DEBUG_MSG_CRITICAL_KHR: number

  export const EGL_DEBUG_MSG_ERROR_KHR: number

  export const EGL_DEBUG_MSG_WARN_KHR: number

  export const EGL_DEBUG_MSG_INFO_KHR: number

  export const EGL_DEBUG_CALLBACK_KHR: number

  export const EGL_TRACK_REFERENCES_KHR: number

  export const EGL_SYNC_PRIOR_COMMANDS_COMPLETE_KHR: number

  export const EGL_SYNC_CONDITION_KHR: number

  export const EGL_SYNC_FENCE_KHR: number

  export const EGL_GL_COLORSPACE_KHR: number

  export const EGL_GL_COLORSPACE_SRGB_KHR: number

  export const EGL_GL_COLORSPACE_LINEAR_KHR: number

  export const EGL_GL_RENDERBUFFER_KHR: number

  export const EGL_GL_TEXTURE_2D_KHR: number

  export const EGL_GL_TEXTURE_LEVEL_KHR: number

  export const EGL_GL_TEXTURE_3D_KHR: number

  export const EGL_GL_TEXTURE_ZOFFSET_KHR: number

  export const EGL_GL_TEXTURE_CUBE_MAP_POSITIVE_X_KHR: number

  export const EGL_GL_TEXTURE_CUBE_MAP_NEGATIVE_X_KHR: number

  export const EGL_GL_TEXTURE_CUBE_MAP_POSITIVE_Y_KHR: number

  export const EGL_GL_TEXTURE_CUBE_MAP_NEGATIVE_Y_KHR: number

  export const EGL_GL_TEXTURE_CUBE_MAP_POSITIVE_Z_KHR: number

  export const EGL_GL_TEXTURE_CUBE_MAP_NEGATIVE_Z_KHR: number

  export const EGL_NATIVE_PIXMAP_KHR: number

  export const EGL_NO_IMAGE_KHR: null;

  export const EGL_IMAGE_PRESERVED_KHR: number

  export const EGL_READ_SURFACE_BIT_KHR: number

  export const EGL_WRITE_SURFACE_BIT_KHR: number

  export const EGL_LOCK_SURFACE_BIT_KHR: number

  export const EGL_OPTIMAL_FORMAT_BIT_KHR: number

  export const EGL_MATCH_FORMAT_KHR: number

  export const EGL_FORMAT_RGB_565_EXACT_KHR: number

  export const EGL_FORMAT_RGB_565_KHR: number

  export const EGL_FORMAT_RGBA_8888_EXACT_KHR: number

  export const EGL_FORMAT_RGBA_8888_KHR: number

  export const EGL_MAP_PRESERVE_PIXELS_KHR: number

  export const EGL_LOCK_USAGE_HINT_KHR: number

  export const EGL_BITMAP_POINTER_KHR: number

  export const EGL_BITMAP_PITCH_KHR: number

  export const EGL_BITMAP_ORIGIN_KHR: number

  export const EGL_BITMAP_PIXEL_RED_OFFSET_KHR: number

  export const EGL_BITMAP_PIXEL_GREEN_OFFSET_KHR: number

  export const EGL_BITMAP_PIXEL_BLUE_OFFSET_KHR: number

  export const EGL_BITMAP_PIXEL_ALPHA_OFFSET_KHR: number

  export const EGL_BITMAP_PIXEL_LUMINANCE_OFFSET_KHR: number

  export const EGL_LOWER_LEFT_KHR: number

  export const EGL_UPPER_LEFT_KHR: number

  export const EGL_BITMAP_PIXEL_SIZE_KHR: number

  export const EGL_MUTABLE_RENDER_BUFFER_BIT_KHR: number

  export const EGL_NO_CONFIG_KHR: number;

  export const EGL_BUFFER_AGE_KHR: number

  export const EGL_PLATFORM_ANDROID_KHR: number

  export const EGL_PLATFORM_GBM_KHR: number

  export const EGL_PLATFORM_OHOS_KHR: number

  export const EGL_PLATFORM_WAYLAND_KHR: number

  export const EGL_PLATFORM_X11_KHR: number

  export const EGL_PLATFORM_X11_SCREEN_KHR: number

  export const EGL_SYNC_STATUS_KHR: number

  export const EGL_SIGNALED_KHR: number

  export const EGL_UNSIGNALED_KHR: number

  export const EGL_TIMEOUT_EXPIRED_KHR: number

  export const EGL_CONDITION_SATISFIED_KHR: number

  export const EGL_SYNC_TYPE_KHR: number

  export const EGL_SYNC_REUSABLE_KHR: number

  export const EGL_SYNC_FLUSH_COMMANDS_BIT_KHR: number

  export const EGL_FOREVER_KHR: number;

  export const EGL_NO_SYNC_KHR: number;

  export const EGL_NO_STREAM_KHR: number;

  export const EGL_CONSUMER_LATENCY_USEC_KHR: number

  export const EGL_PRODUCER_FRAME_KHR: number

  export const EGL_CONSUMER_FRAME_KHR: number

  export const EGL_STREAM_STATE_KHR: number

  export const EGL_STREAM_STATE_CREATED_KHR: number

  export const EGL_STREAM_STATE_CONNECTING_KHR: number

  export const EGL_STREAM_STATE_EMPTY_KHR: number

  export const EGL_STREAM_STATE_NEW_FRAME_AVAILABLE_KHR: number

  export const EGL_STREAM_STATE_OLD_FRAME_AVAILABLE_KHR: number

  export const EGL_STREAM_STATE_DISCONNECTED_KHR: number

  export const EGL_BAD_STREAM_KHR: number

  export const EGL_BAD_STATE_KHR: number

  export const EGL_STREAM_FIFO_LENGTH_KHR: number

  export const EGL_STREAM_TIME_NOW_KHR: number

  export const EGL_STREAM_TIME_CONSUMER_KHR: number

  export const EGL_STREAM_TIME_PRODUCER_KHR: number

  export const EGL_STREAM_BIT_KHR: number

  export const EGL_NATIVE_BUFFER_USAGE_ANDROID: number

  export const EGL_NATIVE_BUFFER_USAGE_PROTECTED_BIT_ANDROID: number

  export const EGL_NATIVE_BUFFER_USAGE_RENDERBUFFER_BIT_ANDROID: number

  export const EGL_NATIVE_BUFFER_USAGE_TEXTURE_BIT_ANDROID: number

  export const EGL_FRAMEBUFFER_TARGET_ANDROID: number

  export const EGL_FRONT_BUFFER_AUTO_REFRESH_ANDROID: number

  export const EGL_TIMESTAMP_PENDING_ANDROID: number

  export const EGL_TIMESTAMP_INVALID_ANDROID: number

  export const EGL_TIMESTAMPS_ANDROID: number

  export const EGL_COMPOSITE_DEADLINE_ANDROID: number

  export const EGL_COMPOSITE_INTERVAL_ANDROID: number

  export const EGL_COMPOSITE_TO_PRESENT_LATENCY_ANDROID: number

  export const EGL_REQUESTED_PRESENT_TIME_ANDROID: number

  export const EGL_RENDERING_COMPLETE_TIME_ANDROID: number

  export const EGL_COMPOSITION_LATCH_TIME_ANDROID: number

  export const EGL_FIRST_COMPOSITION_START_TIME_ANDROID: number

  export const EGL_LAST_COMPOSITION_START_TIME_ANDROID: number

  export const EGL_FIRST_COMPOSITION_GPU_FINISHED_TIME_ANDROID: number

  export const EGL_DISPLAY_PRESENT_TIME_ANDROID: number

  export const EGL_DEQUEUE_READY_TIME_ANDROID: number

  export const EGL_READS_DONE_TIME_ANDROID: number

  export const EGL_NATIVE_BUFFER_ANDROID: number

  export const EGL_SYNC_NATIVE_FENCE_ANDROID: number

  export const EGL_SYNC_NATIVE_FENCE_FD_ANDROID: number

  export const EGL_RECORDABLE_ANDROID: number

  export const EGL_D3D9_DEVICE_ANGLE: number

  export const EGL_D3D11_DEVICE_ANGLE: number

  export const EGL_FIXED_SIZE_ANGLE: number

  export const EGL_COLOR_COMPONENT_TYPE_UNSIGNED_INTEGER_ARM: number

  export const EGL_COLOR_COMPONENT_TYPE_INTEGER_ARM: number

  export const EGL_DISCARD_SAMPLES_ARM: number

  export const EGL_FRONT_BUFFER_EXT: number

  export const EGL_BUFFER_AGE_EXT: number

  export const EGL_SYNC_CLIENT_EXT: number

  export const EGL_SYNC_CLIENT_SIGNAL_EXT: number

  export const EGL_PRIMARY_COMPOSITOR_CONTEXT_EXT: number

  export const EGL_EXTERNAL_REF_ID_EXT: number

  export const EGL_COMPOSITOR_DROP_NEWEST_FRAME_EXT: number

  export const EGL_COMPOSITOR_KEEP_NEWEST_FRAME_EXT: number

  export const EGL_CONFIG_SELECT_GROUP_EXT: number

  export const EGL_CONTEXT_OPENGL_ROBUST_ACCESS_EXT: number

  export const EGL_CONTEXT_OPENGL_RESET_NOTIFICATION_STRATEGY_EXT: number

  export const EGL_NO_RESET_NOTIFICATION_EXT: number

  export const EGL_LOSE_CONTEXT_ON_RESET_EXT: number

  export const EGL_NO_DEVICE_EXT: number;

  export const EGL_BAD_DEVICE_EXT: number

  export const EGL_DEVICE_EXT: number

  export const EGL_DRM_DEVICE_FILE_EXT: number

  export const EGL_DRM_MASTER_FD_EXT: number

  export const EGL_DRM_RENDER_NODE_FILE_EXT: number

  export const EGL_OPENWF_DEVICE_ID_EXT: number

  export const EGL_OPENWF_DEVICE_EXT: number

  export const EGL_DEVICE_UUID_EXT: number

  export const EGL_DRIVER_UUID_EXT: number

  export const EGL_DRIVER_NAME_EXT: number

  export const EGL_RENDERER_EXT: number

  export const EGL_GL_COLORSPACE_BT2020_LINEAR_EXT: number

  export const EGL_GL_COLORSPACE_BT2020_PQ_EXT: number

  export const EGL_GL_COLORSPACE_DISPLAY_P3_EXT: number

  export const EGL_GL_COLORSPACE_DISPLAY_P3_LINEAR_EXT: number

  export const EGL_GL_COLORSPACE_DISPLAY_P3_PASSTHROUGH_EXT: number

  export const EGL_GL_COLORSPACE_SCRGB_EXT: number

  export const EGL_GL_COLORSPACE_SCRGB_LINEAR_EXT: number

  export const EGL_LINUX_DMA_BUF_EXT: number

  export const EGL_LINUX_DRM_FOURCC_EXT: number

  export const EGL_DMA_BUF_PLANE0_FD_EXT: number

  export const EGL_DMA_BUF_PLANE0_OFFSET_EXT: number

  export const EGL_DMA_BUF_PLANE0_PITCH_EXT: number

  export const EGL_DMA_BUF_PLANE1_FD_EXT: number

  export const EGL_DMA_BUF_PLANE1_OFFSET_EXT: number

  export const EGL_DMA_BUF_PLANE1_PITCH_EXT: number

  export const EGL_DMA_BUF_PLANE2_FD_EXT: number

  export const EGL_DMA_BUF_PLANE2_OFFSET_EXT: number

  export const EGL_DMA_BUF_PLANE2_PITCH_EXT: number

  export const EGL_YUV_COLOR_SPACE_HINT_EXT: number

  export const EGL_SAMPLE_RANGE_HINT_EXT: number

  export const EGL_YUV_CHROMA_HORIZONTAL_SITING_HINT_EXT: number

  export const EGL_YUV_CHROMA_VERTICAL_SITING_HINT_EXT: number

  export const EGL_ITU_REC601_EXT: number

  export const EGL_ITU_REC709_EXT: number

  export const EGL_ITU_REC2020_EXT: number

  export const EGL_YUV_FULL_RANGE_EXT: number

  export const EGL_YUV_NARROW_RANGE_EXT: number

  export const EGL_YUV_CHROMA_SITING_0_EXT: number

  export const EGL_YUV_CHROMA_SITING_0_5_EXT: number

  export const EGL_DMA_BUF_PLANE3_FD_EXT: number

  export const EGL_DMA_BUF_PLANE3_OFFSET_EXT: number

  export const EGL_DMA_BUF_PLANE3_PITCH_EXT: number

  export const EGL_DMA_BUF_PLANE0_MODIFIER_LO_EXT: number

  export const EGL_DMA_BUF_PLANE0_MODIFIER_HI_EXT: number

  export const EGL_DMA_BUF_PLANE1_MODIFIER_LO_EXT: number

  export const EGL_DMA_BUF_PLANE1_MODIFIER_HI_EXT: number

  export const EGL_DMA_BUF_PLANE2_MODIFIER_LO_EXT: number

  export const EGL_DMA_BUF_PLANE2_MODIFIER_HI_EXT: number

  export const EGL_DMA_BUF_PLANE3_MODIFIER_LO_EXT: number

  export const EGL_DMA_BUF_PLANE3_MODIFIER_HI_EXT: number

  export const EGL_GL_COLORSPACE_DEFAULT_EXT: number

  export const EGL_IMPORT_SYNC_TYPE_EXT: number

  export const EGL_IMPORT_IMPLICIT_SYNC_EXT: number

  export const EGL_IMPORT_EXPLICIT_SYNC_EXT: number

  export const EGL_MULTIVIEW_VIEW_COUNT_EXT: number

  export const EGL_NO_OUTPUT_LAYER_EXT: number;

  export const EGL_NO_OUTPUT_PORT_EXT: number;

  export const EGL_BAD_OUTPUT_LAYER_EXT: number

  export const EGL_BAD_OUTPUT_PORT_EXT: number

  export const EGL_SWAP_INTERVAL_EXT: number

  export const EGL_DRM_CRTC_EXT: number

  export const EGL_DRM_PLANE_EXT: number

  export const EGL_DRM_CONNECTOR_EXT: number

  export const EGL_OPENWF_PIPELINE_ID_EXT: number

  export const EGL_OPENWF_PORT_ID_EXT: number

  export const EGL_COLOR_COMPONENT_TYPE_EXT: number

  export const EGL_COLOR_COMPONENT_TYPE_FIXED_EXT: number

  export const EGL_COLOR_COMPONENT_TYPE_FLOAT_EXT: number

  export const EGL_PLATFORM_DEVICE_EXT: number

  export const EGL_PLATFORM_WAYLAND_EXT: number

  export const EGL_PLATFORM_X11_EXT: number

  export const EGL_PLATFORM_X11_SCREEN_EXT: number

  export const EGL_PLATFORM_XCB_EXT: number

  export const EGL_PLATFORM_XCB_SCREEN_EXT: number

  export const EGL_PRESENT_OPAQUE_EXT: number

  export const EGL_PROTECTED_CONTENT_EXT: number

  export const EGL_CTA861_3_MAX_CONTENT_LIGHT_LEVEL_EXT: number

  export const EGL_CTA861_3_MAX_FRAME_AVERAGE_LEVEL_EXT: number

  export const EGL_SMPTE2086_DISPLAY_PRIMARY_RX_EXT: number

  export const EGL_SMPTE2086_DISPLAY_PRIMARY_RY_EXT: number

  export const EGL_SMPTE2086_DISPLAY_PRIMARY_GX_EXT: number

  export const EGL_SMPTE2086_DISPLAY_PRIMARY_GY_EXT: number

  export const EGL_SMPTE2086_DISPLAY_PRIMARY_BX_EXT: number

  export const EGL_SMPTE2086_DISPLAY_PRIMARY_BY_EXT: number

  export const EGL_SMPTE2086_WHITE_POINT_X_EXT: number

  export const EGL_SMPTE2086_WHITE_POINT_Y_EXT: number

  export const EGL_SMPTE2086_MAX_LUMINANCE_EXT: number

  export const EGL_SMPTE2086_MIN_LUMINANCE_EXT: number

  export const EGL_METADATA_SCALING_EXT: number

  export const EGL_SURFACE_COMPRESSION_EXT: number

  export const EGL_SURFACE_COMPRESSION_PLANE1_EXT: number

  export const EGL_SURFACE_COMPRESSION_PLANE2_EXT: number

  export const EGL_SURFACE_COMPRESSION_FIXED_RATE_NONE_EXT: number

  export const EGL_SURFACE_COMPRESSION_FIXED_RATE_DEFAULT_EXT: number

  export const EGL_SURFACE_COMPRESSION_FIXED_RATE_1BPC_EXT: number

  export const EGL_SURFACE_COMPRESSION_FIXED_RATE_2BPC_EXT: number

  export const EGL_SURFACE_COMPRESSION_FIXED_RATE_3BPC_EXT: number

  export const EGL_SURFACE_COMPRESSION_FIXED_RATE_4BPC_EXT: number

  export const EGL_SURFACE_COMPRESSION_FIXED_RATE_5BPC_EXT: number

  export const EGL_SURFACE_COMPRESSION_FIXED_RATE_6BPC_EXT: number

  export const EGL_SURFACE_COMPRESSION_FIXED_RATE_7BPC_EXT: number

  export const EGL_SURFACE_COMPRESSION_FIXED_RATE_8BPC_EXT: number

  export const EGL_SURFACE_COMPRESSION_FIXED_RATE_9BPC_EXT: number

  export const EGL_SURFACE_COMPRESSION_FIXED_RATE_10BPC_EXT: number

  export const EGL_SURFACE_COMPRESSION_FIXED_RATE_11BPC_EXT: number

  export const EGL_SURFACE_COMPRESSION_FIXED_RATE_12BPC_EXT: number

  export const EGL_YUV_ORDER_EXT: number

  export const EGL_YUV_NUMBER_OF_PLANES_EXT: number

  export const EGL_YUV_SUBSAMPLE_EXT: number

  export const EGL_YUV_DEPTH_RANGE_EXT: number

  export const EGL_YUV_CSC_STANDARD_EXT: number

  export const EGL_YUV_PLANE_BPP_EXT: number

  export const EGL_YUV_BUFFER_EXT: number

  export const EGL_YUV_ORDER_YUV_EXT: number

  export const EGL_YUV_ORDER_YVU_EXT: number

  export const EGL_YUV_ORDER_YUYV_EXT: number

  export const EGL_YUV_ORDER_UYVY_EXT: number

  export const EGL_YUV_ORDER_YVYU_EXT: number

  export const EGL_YUV_ORDER_VYUY_EXT: number

  export const EGL_YUV_ORDER_AYUV_EXT: number

  export const EGL_YUV_SUBSAMPLE_4_2_0_EXT: number

  export const EGL_YUV_SUBSAMPLE_4_2_2_EXT: number

  export const EGL_YUV_SUBSAMPLE_4_4_4_EXT: number

  export const EGL_YUV_DEPTH_RANGE_LIMITED_EXT: number

  export const EGL_YUV_DEPTH_RANGE_FULL_EXT: number

  export const EGL_YUV_CSC_STANDARD_601_EXT: number

  export const EGL_YUV_CSC_STANDARD_709_EXT: number

  export const EGL_YUV_CSC_STANDARD_2020_EXT: number

  export const EGL_YUV_PLANE_BPP_0_EXT: number

  export const EGL_YUV_PLANE_BPP_8_EXT: number

  export const EGL_YUV_PLANE_BPP_10_EXT: number

  export const EGL_CLIENT_PIXMAP_POINTER_HI: number

  export const EGL_COLOR_FORMAT_HI: number

  export const EGL_COLOR_RGB_HI: number

  export const EGL_COLOR_RGBA_HI: number

  export const EGL_COLOR_ARGB_HI: number

  export const EGL_CONTEXT_PRIORITY_LEVEL_IMG: number

  export const EGL_CONTEXT_PRIORITY_HIGH_IMG: number

  export const EGL_CONTEXT_PRIORITY_MEDIUM_IMG: number

  export const EGL_CONTEXT_PRIORITY_LOW_IMG: number

  export const EGL_DRM_BUFFER_FORMAT_MESA: number

  export const EGL_DRM_BUFFER_USE_MESA: number

  export const EGL_DRM_BUFFER_FORMAT_ARGB32_MESA: number

  export const EGL_DRM_BUFFER_MESA: number

  export const EGL_DRM_BUFFER_STRIDE_MESA: number

  export const EGL_DRM_BUFFER_USE_SCANOUT_MESA: number

  export const EGL_DRM_BUFFER_USE_SHARE_MESA: number

  export const EGL_DRM_BUFFER_USE_CURSOR_MESA: number

  export const EGL_PLATFORM_GBM_MESA: number

  export const EGL_PLATFORM_SURFACELESS_MESA: number

  export const EGL_Y_INVERTED_NOK: number

  export const EGL_AUTO_STEREO_NV: number

  export const EGL_CONTEXT_PRIORITY_REALTIME_NV: number

  export const EGL_COVERAGE_BUFFERS_NV: number

  export const EGL_COVERAGE_SAMPLES_NV: number

  export const EGL_COVERAGE_SAMPLE_RESOLVE_NV: number

  export const EGL_COVERAGE_SAMPLE_RESOLVE_DEFAULT_NV: number

  export const EGL_COVERAGE_SAMPLE_RESOLVE_NONE_NV: number

  export const EGL_CUDA_EVENT_HANDLE_NV: number

  export const EGL_SYNC_CUDA_EVENT_NV: number

  export const EGL_SYNC_CUDA_EVENT_COMPLETE_NV: number

  export const EGL_DEPTH_ENCODING_NV: number

  export const EGL_DEPTH_ENCODING_NONE_NV: number

  export const EGL_DEPTH_ENCODING_NONLINEAR_NV: number

  export const EGL_CUDA_DEVICE_NV: number

  export const EGL_POST_SUB_BUFFER_SUPPORTED_NV: number

  export const EGL_QUADRUPLE_BUFFER_NV: number

  export const EGL_GENERATE_RESET_ON_VIDEO_MEMORY_PURGE_NV: number

  export const EGL_STREAM_CONSUMER_IMAGE_NV: number

  export const EGL_STREAM_IMAGE_ADD_NV: number

  export const EGL_STREAM_IMAGE_REMOVE_NV: number

  export const EGL_STREAM_IMAGE_AVAILABLE_NV: number

  export const EGL_YUV_PLANE0_TEXTURE_UNIT_NV: number

  export const EGL_YUV_PLANE1_TEXTURE_UNIT_NV: number

  export const EGL_YUV_PLANE2_TEXTURE_UNIT_NV: number

  export const EGL_STREAM_CROSS_DISPLAY_NV: number

  export const EGL_STREAM_CROSS_OBJECT_NV: number

  export const EGL_STREAM_CROSS_PARTITION_NV: number

  export const EGL_STREAM_CROSS_PROCESS_NV: number

  export const EGL_STREAM_CROSS_SYSTEM_NV: number

  export const EGL_STREAM_DMA_NV: number

  export const EGL_STREAM_DMA_SERVER_NV: number

  export const EGL_PENDING_FRAME_NV: number

  export const EGL_STREAM_TIME_PENDING_NV: number

  export const EGL_STREAM_FIFO_SYNCHRONOUS_NV: number

  export const EGL_PRODUCER_MAX_FRAME_HINT_NV: number

  export const EGL_CONSUMER_MAX_FRAME_HINT_NV: number

  export const EGL_PRODUCER_METADATA_NV: number

  export const EGL_CONSUMER_METADATA_NV: number

  export const EGL_PENDING_METADATA_NV: number

  export const EGL_METADATA0_SIZE_NV: number

  export const EGL_METADATA1_SIZE_NV: number

  export const EGL_METADATA2_SIZE_NV: number

  export const EGL_METADATA3_SIZE_NV: number

  export const EGL_METADATA0_TYPE_NV: number

  export const EGL_METADATA1_TYPE_NV: number

  export const EGL_METADATA2_TYPE_NV: number

  export const EGL_METADATA3_TYPE_NV: number

  export const EGL_STREAM_FRAME_ORIGIN_X_NV: number

  export const EGL_STREAM_FRAME_ORIGIN_Y_NV: number

  export const EGL_STREAM_FRAME_MAJOR_AXIS_NV: number

  export const EGL_CONSUMER_AUTO_ORIENTATION_NV: number

  export const EGL_PRODUCER_AUTO_ORIENTATION_NV: number

  export const EGL_LEFT_NV: number

  export const EGL_RIGHT_NV: number

  export const EGL_TOP_NV: number

  export const EGL_BOTTOM_NV: number

  export const EGL_X_AXIS_NV: number

  export const EGL_Y_AXIS_NV: number

  export const EGL_STREAM_STATE_INITIALIZING_NV: number

  export const EGL_STREAM_TYPE_NV: number

  export const EGL_STREAM_PROTOCOL_NV: number

  export const EGL_STREAM_ENDPOINT_NV: number

  export const EGL_STREAM_LOCAL_NV: number

  export const EGL_STREAM_PRODUCER_NV: number

  export const EGL_STREAM_CONSUMER_NV: number

  export const EGL_STREAM_PROTOCOL_FD_NV: number

  export const EGL_SUPPORT_RESET_NV: number

  export const EGL_SUPPORT_REUSE_NV: number

  export const EGL_STREAM_PROTOCOL_SOCKET_NV: number

  export const EGL_SOCKET_HANDLE_NV: number

  export const EGL_SOCKET_TYPE_NV: number

  export const EGL_SOCKET_TYPE_INET_NV: number

  export const EGL_SOCKET_TYPE_UNIX_NV: number

  export const EGL_SYNC_NEW_FRAME_NV: number

  export const EGL_SYNC_PRIOR_COMMANDS_COMPLETE_NV: number

  export const EGL_SYNC_STATUS_NV: number

  export const EGL_SIGNALED_NV: number

  export const EGL_UNSIGNALED_NV: number

  export const EGL_SYNC_FLUSH_COMMANDS_BIT_NV: number

  export const EGL_FOREVER_NV: number

  export const EGL_ALREADY_SIGNALED_NV: number

  export const EGL_TIMEOUT_EXPIRED_NV: number

  export const EGL_CONDITION_SATISFIED_NV: number

  export const EGL_SYNC_TYPE_NV: number

  export const EGL_SYNC_CONDITION_NV: number

  export const EGL_SYNC_FENCE_NV: number

  export const EGL_TRIPLE_BUFFER_NV: number

  export const EGL_NATIVE_BUFFER_OHOS: number

  export const EGL_NATIVE_BUFFER_TIZEN: number

  export const EGL_NATIVE_SURFACE_TIZEN: number

  export const EGL_WAYLAND_BUFFER_WL: number

  export const EGL_WAYLAND_PLANE_WL: number

  export const EGL_TEXTURE_Y_U_V_WL: number

  export const EGL_TEXTURE_Y_UV_WL: number

  export const EGL_TEXTURE_Y_XUXV_WL: number

  export const EGL_TEXTURE_EXTERNAL_WL: number

  export const EGL_WAYLAND_Y_INVERTED_WL: number

  export const EGL_DRAW: number

  export const EGL_READ: number

  export const EGL_MAX_PBUFFER_WIDTH: number

  export const EGL_MAX_PBUFFER_HEIGHT: number

  export const EGL_MAX_PBUFFER_PIXELS: number

  export const EGL_NATIVE_VISUAL_ID: number

  export const EGL_NATIVE_VISUAL_TYPE: number

  export const EGL_CLIENT_APIS: number

  export const EGL_VENDOR: number

  export const EGL_VERSION: number

  export const EGL_EXTENSIONS: number

  export const EGL_CORE_NATIVE_ENGINE: number

  export const EGL_FOREVER: number

  export const EGL_TIMEOUT_EXPIRED: number

  export const EGL_CONDITION_SATISFIED: number

  export const EGL_SYNC_FLUSH_COMMANDS_BIT: number

  export const EGL_MIPMAP_LEVEL: number

  export const EGL_MULTISAMPLE_RESOLVE: number

  export const EGL_SWAP_BEHAVIOR: number

  export const EGL_BUFFER_DESTROYED: number

  export const EGL_DISPLAY_SCALING: number

  export const EGL_UNKNOWN: number

  export const EGL_SUCCESS: number

  export const EGL_NOT_INITIALIZED: number

  export const EGL_BAD_ACCESS: number

  export const EGL_BAD_ALLOC: number

  export const EGL_BAD_ATTRIBUTE: number

  export const EGL_BAD_CONFIG: number

  export const EGL_BAD_CONTEXT: number

  export const EGL_BAD_CURRENT_SURFACE: number

  export const EGL_BAD_DISPLAY: number

  export const EGL_BAD_MATCH: number

  export const EGL_BAD_NATIVE_PIXMAP: number

  export const EGL_BAD_NATIVE_WINDOW: number

  export const EGL_BAD_PARAMETER: number

  export const EGL_BAD_SURFACE: number

  export const EGL_OPENGL_API: number

  export const EGL_OPENGL_ES_API: number

  export const EGL_OPENVG_API: number

  export const EGL_OPENVG_IMAGE: number

  export const EGL_CONTEXT_CLIENT_TYPE: number

  /**
   * 获取EGLDisplay对象 通常输入undefined来获取DefaultDisplay
   */
  export function eglGetDisplay(eglNativeDisplayType?: string): EGLDisplay | undefined;

  export function eglInitialize(dpy: EGLDisplay): EGLVersion | undefined

  export function eglChooseConfig(dpy: EGLDisplay, attrib_list: number[],
    config_size: number): EGLConfig[] | undefined;

  export function eglCreatePixmapSurface(dpy: EGLDisplay, config: EGLConfig, pixmap: image.PixelMap,
    attrib_list?: number[]): EGLSurface | undefined;

  export function eglCreateContext(dpy: EGLDisplay, config: EGLConfig, share_context?: EGLContext,
    attrib_list?: number[]): EGLContext | undefined;

  export function eglCreatePbufferSurface(dpy: EGLDisplay, config: EGLConfig,
    attrib_list?: number[]): EGLSurface | undefined;

  export function eglCreateWindowSurface(dpy: EGLDisplay, config: EGLConfig, surfaceId: string,
    attrib_list?: number[]): EGLSurface | undefined;

  export function eglDestroyContext(dpy: EGLDisplay, context: EGLContext): boolean;

  export function eglDestroySurface(dpy: EGLDisplay, surface: EGLSurface): boolean;

  export function eglGetConfigAttrib(dpy: EGLDisplay, config: EGLConfig,
    attribute: EGLConfigAttribute): number | undefined;

  export function eglGetConfigs(dpy: EGLDisplay, count: number): EGLConfig[] | undefined;

  export function eglGetCurrentDisplay(): EGLDisplay | undefined;

  export function eglMakeCurrent(dpy: EGLDisplay, draw: EGLSurface | undefined, read: EGLSurface | undefined,
    context: EGLContext): boolean;

  export function eglGetCurrentSurface(readdraw: READDRAW): EGLSurface | undefined;

  export function eglGetError(): EGLError;

  /**
   *在arkTs中没啥用，只能用来判断有没有某个方法
   */
  export function eglGetProcAddress(procName: string): string | undefined;

  /**
   * 查询成功返回number否则undefined
   * @param attribute EGL_CONFIG_ID / EGL_CONTEXT_CLIENT_TYPE / EGL_CONTEXT_CLIENT_VERSION / EGL_RENDER_BUFFER
   */
  export function eglQueryContext(dpy: EGLDisplay, context: EGLContext, attribute: number): number | undefined;

  export function eglQueryString(dpy: EGLDisplay, name: QueryStringNames): string;

  export function eglQuerySurface(dpy: EGLDisplay, surface: EGLSurface, attribute: number): number | undefined;

  export function eglSwapBuffers(dpy: EGLDisplay, surface: EGLSurface): boolean;

  export function eglTerminate(dpy: EGLDisplay): boolean;

  export function eglWaitGL(): boolean;

  /**
   * 参数engine必须是EGL_CORE_NATIVE_ENGINE(https://registry.khronos.org/EGL/sdk/docs/man/html/eglWaitNative.xhtml)
   * @param engine EGL_CORE_NATIVE_ENGINE
   */
  export function eglWaitNative(engine: number): boolean;

  export function eglBindTexImage(dpy: EGLDisplay, surface: EGLSurface, buffer: number): boolean;

  export function eglReleaseTexImage(dpy: EGLDisplay, surface: EGLSurface, buffer: number): boolean;

  export function eglCreatePbufferFromClientBuffer(dpy: EGLDisplay, buftype: number, buffer: NativeBuffer,
    config: EGLConfig, attrib_list?: number[]): EGLSurface | undefined

  /**
   *https://registry.khronos.org/EGL/sdk/docs/man/html/eglSurfaceAttrib.xhtml
   * @param attribute EGL_MIPMAP_LEVEL / EGL_MULTISAMPLE_RESOLVE / EGL_SWAP_BEHAVIOR
   */
  function eglSurfaceAttrib(dpy: EGLDisplay, surface: EGLSurface, attribute: number,
    value: number): boolean;

  export function eglSwapInterval(dpy: EGLDisplay, interval: number): boolean;

  export function eglBindAPI(api: EGLApi): boolean;

  export function eglQueryAPI(): EGLApi;

  export function eglReleaseThread(): boolean;

  export function eglWaitClient(): boolean;

  export function eglGetCurrentContext(): EGLContext | undefined;

  export function eglCreateSync(dpy: EGLDisplay, type: EGLSyncType, attrib_list?: number[]): EGLSync | undefined;

  export function eglDestroySync(dpy: EGLDisplay, sync: EGLSync): boolean;

  /**
   * https://registry.khronos.org/EGL/sdk/docs/man/html/eglClientWaitSync.xhtml
   */
  export function eglClientWaitSync(dpy: EGLDisplay, sync: EGLSync, flags: number, timeout: number): number;

  export function eglGetSyncAttrib(dpy: EGLDisplay, sync: EGLSync, attribute: number): number | undefined;

  export function eglGetPlatformDisplay(platform: EGLPlatform, native_display?: string,
    attrib_list?: number[]): EGLDisplay | undefined;

  /**
   * https://registry.khronos.org/EGL/sdk/docs/man/html/eglCreatePlatformWindowSurface.xhtml
   * @param attrib_list EGL_GL_COLORSPACE / EGL_RENDER_BUFFER / EGL_VG_ALPHA_FORMAT / EGL_VG_COLORSPACE
   */
  export function eglCreatePlatformWindowSurface(dpy: EGLDisplay, config: EGLConfig, native_window?: string,
    attrib_list?: number[]): EGLSurface | undefined;

  /**
   * https://registry.khronos.org/EGL/sdk/docs/man/html/eglCreatePlatformPixmapSurface.xhtml
   * @param attrib_list EGL_GL_COLORSPACE / EGL_VG_ALPHA_FORMAT / EGL_VG_COLORSPACE
   */
  export function eglCreatePlatformPixmapSurface(dpy: EGLDisplay, config: EGLConfig, pixmap: image.PixelMap,
    attrib_list?: number[]): EGLSurface | undefined;

  export function eglWaitSync(dpy: EGLDisplay, sync: EGLSync, flags: number): boolean;

  /**
   *传入PixelMap，eglGetError不报错，但copy失败
   */
  export function eglCopyBuffers(dpy: EGLDisplay, surface: EGLSurface, target: image.PixelMap): boolean;

  export function eglCreateImageKHR(dpy: EGLDisplay, context: EGLContext, target: number, buffer: NativeBuffer,
    attrib_list?: number[]): EGLImageKHR | undefined;

  export function eglDestroyImageKHR(dpy: EGLDisplay, image: EGLImageKHR): boolean


  export function eglDestroyImage(dpy: EGLDisplay, image: EGLImage): boolean

  export function eglCreateSyncKHR(dpy: EGLDisplay, type: number, attrib_list?: number[]): EGLSyncKHR | undefined

  export function eglDestroySyncKHR(dpy: EGLDisplay, sync: EGLSyncKHR): boolean

  export function eglCreateContext(dpy: EGLDisplay, config: EGLConfig, share_context: EGLContext | undefined,
    attrib_list?: number[]): EGLContext | undefined
}