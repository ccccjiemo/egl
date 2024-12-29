import { image } from "@kit.ImageKit";


declare namespace egl {

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
    chooseConfig(attrib_list: number[], count?: number): EGLConfig[];

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
     * 模拟器不支持pixmap,有真机大佬帮我测试下吗
     */
    createPixmapSurface(config: EGLConfig, pixmap: image.PixelMap, attrib_list?: number[]): EGLSurface | undefined;
  }

  enum NativeBufferUsage {
    CPU_READ = 1,
    CPU_WRITE = 1 << 1,
    MEM_DMA = 1 << 3,
    HW_RENDER = 1 << 8,
    HW_TEXTURE = 1 << 9,
    CPU_READ_OFTEN = 1 << 16,
    ALIGNMENT_512 = 1 << 18
  }

  enum NativeBufferFormat {
    CLUT8 = 0,
    CLUT1 = 1,
    CLUT4 = 2,
    RGB_565 = 3,
    RGBA_5658 = 4,
    RGBX_4444 = 5,
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
    VENDER_MASK = 0x7FFF0000,
    BUTT = 0x7fffffff
  }

  interface NativeBufferConfig {
    width: number;
    height: number;
    format: NativeBufferFormat;
    usage: NativeBufferUsage;
    stride: number;
  }

  enum EGLConfigAttribute {
    EGL_ALPHA_SIZE = 0x3021,
    EGL_ALPHA_MASK_SIZE = 0x303E,
    EGL_BIND_TO_TEXTURE_RGB = 0x3039,
    EGL_BIND_TO_TEXTURE_RGBA = 0x303A,
    EGL_BLUE_SIZE = 0x3022,
    EGL_BUFFER_SIZE = 0x3020,
    EGL_COLOR_BUFFER_TYPE = 0x303F,
    EGL_CONFIG_CAVEAT = 0x3027,
    EGL_CONFIG_ID = 0x3028,
    EGL_CONFORMANT = 0x3042,
    EGL_DEPTH_SIZE = 0x3025,
    EGL_GREEN_SIZE = 0x3023,
    EGL_LEVEL = 0x3029,
    EGL_LUMINANCE_SIZE = 0x303D,
    EGL_MAX_PBUFFER_WIDTH = 0x302C,
    EGL_MAX_PBUFFER_HEIGHT = 0x302A,
    EGL_MAX_PBUFFER_PIXELS = 0x302B,
    EGL_MAX_SWAP_INTERVAL = 0x303C,
    EGL_MIN_SWAP_INTERVAL = 0x303B,
    EGL_NATIVE_RENDERABLE = 0x302D,
    EGL_NATIVE_VISUAL_ID = 0x302E,
    EGL_NATIVE_VISUAL_TYPE = 0x302F,
    EGL_RED_SIZE = 0x3024,
    EGL_RENDERABLE_TYPE = 0x3040,
    EGL_SAMPLE_BUFFERS = 0x3032,
    EGL_SAMPLES = 0x3031,
    EGL_STENCIL_SIZE = 0x3026,
    EGL_SURFACE_TYPE = 0x3033,
    EGL_TRANSPARENT_TYPE = 0x3034,
    EGL_TRANSPARENT_RED_VALUE = 0x3037,
    EGL_TRANSPARENT_GREEN_VALUE = 0x3036,
    EGL_TRANSPARENT_BLUE_VALUE = 0x3035,
  }

  enum EGLImageType {
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

  enum EGLError {
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

  enum EGLApi {
    EGL_OPENGL_API = 0x30A2,
    EGL_OPENGL_ES_API = 0x30A0,
    EGL_OPENVG_API = 0x30A1
  }

  enum EGLBufferType {
    EGL_OPENVG_IMAGE = 0x3096
  }

  enum EGLSyncType {
    EGL_SYNC_FENCE = 0x30F9
  }

  enum EGLPlatform {
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

  enum READDRAW {
    EGL_READ = 0x305A,
    EGL_DRAW = 0x3059
  }

  enum QueryStringNames {
    EGL_CLIENT_APIS = 0x308D,
    EGL_VENDOR = 0x3053,
    EGL_VERSION = 0x3054,
    EGL_EXTENSIONS = 0x3055
  }

  export const EGL_NO_SURFACE: undefined;

  export const EGL_NO_CONTEXT: undefined;

  export const EGL_NO_CONFIG: undefined;

  export const EGL_NO_DISPLAY: undefined;

  export const EGL_DEFAULT_DISPLAY: undefined;

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

  export const EGL_MULTISAMPLE_RESOLVE_DEFAULT = 0x309A;

  export const EGL_MULTISAMPLE_RESOLVE_BOX = 0x309B;

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

  export const EGL_SYNC_FENCE = EGLSyncType.EGL_SYNC_FENCE;

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
  export const EGL_ALPHA_MASK_SIZE = EGLConfigAttribute.EGL_ALPHA_MASK_SIZE;

  export const EGL_ALPHA_SIZE = EGLConfigAttribute.EGL_ALPHA_SIZE;

  export const EGL_BIND_TO_TEXTURE_RGB = EGLConfigAttribute.EGL_BIND_TO_TEXTURE_RGB;

  export const EGL_BIND_TO_TEXTURE_RGBA = EGLConfigAttribute.EGL_BIND_TO_TEXTURE_RGBA;

  export const EGL_BUFFER_SIZE = EGLConfigAttribute.EGL_BUFFER_SIZE;

  export const EGL_BLUE_SIZE = EGLConfigAttribute.EGL_BLUE_SIZE;

  export const EGL_RED_SIZE = EGLConfigAttribute.EGL_RED_SIZE;

  export const EGL_COLOR_BUFFER_TYPE = EGLConfigAttribute.EGL_COLOR_BUFFER_TYPE;

  export const EGL_CONFIG_CAVEAT = EGLConfigAttribute.EGL_CONFIG_CAVEAT;

  export const EGL_CONFIG_ID = EGLConfigAttribute.EGL_CONFIG_ID;

  export const EGL_CONFORMANT = EGLConfigAttribute.EGL_CONFORMANT;

  export const EGL_DEPTH_SIZE = EGLConfigAttribute.EGL_DEPTH_SIZE;

  export const EGL_GREEN_SIZE = EGLConfigAttribute.EGL_GREEN_SIZE;

  export const EGL_LEVEL = EGLConfigAttribute.EGL_LEVEL;

  export const EGL_LUMINANCE_SIZE = EGLConfigAttribute.EGL_LUMINANCE_SIZE;

  export const EGL_MATCH_NATIVE_PIXMAP = 0x3041;

  export const EGL_NATIVE_RENDERABLE = EGLConfigAttribute.EGL_NATIVE_RENDERABLE;

  export const EGL_MAX_SWAP_INTERVAL = EGLConfigAttribute.EGL_MAX_SWAP_INTERVAL;

  export const EGL_MIN_SWAP_INTERVAL = EGLConfigAttribute.EGL_MIN_SWAP_INTERVAL;

  export const EGL_SAMPLE_BUFFERS = EGLConfigAttribute.EGL_SAMPLE_BUFFERS;

  export const EGL_SAMPLES = EGLConfigAttribute.EGL_SAMPLES;

  export const EGL_STENCIL_SIZE = EGLConfigAttribute.EGL_STENCIL_SIZE;

  export const EGL_RENDERABLE_TYPE = EGLConfigAttribute.EGL_RENDERABLE_TYPE;

  export const EGL_SURFACE_TYPE = EGLConfigAttribute.EGL_SURFACE_TYPE;

  export const EGL_TRANSPARENT_TYPE = EGLConfigAttribute.EGL_TRANSPARENT_TYPE;

  export const EGL_TRANSPARENT_RED_VALUE = EGLConfigAttribute.EGL_TRANSPARENT_RED_VALUE;

  export const EGL_TRANSPARENT_GREEN_VALUE = EGLConfigAttribute.EGL_TRANSPARENT_GREEN_VALUE;

  export const EGL_TRANSPARENT_BLUE_VALUE = EGLConfigAttribute.EGL_TRANSPARENT_BLUE_VALUE;

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

  /***
   * KHR ext
   */
  export const EGL_CL_EVENT_HANDLE_KHR = 0x309C;

  export const EGL_SYNC_CL_EVENT_KHR = 0x30FE;

  export const EGL_SYNC_CL_EVENT_COMPLETE_KHR = 0x30FF;

  export const EGL_CONFORMANT_KHR = 0x3042;

  export const EGL_VG_COLORSPACE_LINEAR_BIT_KHR = 0x0020;

  export const EGL_VG_ALPHA_FORMAT_PRE_BIT_KHR = 0x0040;

  export const EGL_CONTEXT_RELEASE_BEHAVIOR_NONE_KHR = 0;

  export const EGL_CONTEXT_RELEASE_BEHAVIOR_KHR = 0x2097;

  export const EGL_CONTEXT_RELEASE_BEHAVIOR_FLUSH_KHR = 0x2098;

  export const EGL_CONTEXT_MAJOR_VERSION_KHR = 0x3098;

  export const EGL_CONTEXT_MINOR_VERSION_KHR = 0x30FB;

  export const EGL_CONTEXT_FLAGS_KHR = 0x30FC;

  export const EGL_CONTEXT_OPENGL_PROFILE_MASK_KHR = 0x30FD;

  export const EGL_CONTEXT_OPENGL_RESET_NOTIFICATION_STRATEGY_KHR = 0x31BD;

  export const EGL_NO_RESET_NOTIFICATION_KHR = 0x31BE;

  export const EGL_LOSE_CONTEXT_ON_RESET_KHR = 0x31BF;

  export const EGL_CONTEXT_OPENGL_DEBUG_BIT_KHR = 0x00000001;

  export const EGL_CONTEXT_OPENGL_FORWARD_COMPATIBLE_BIT_KHR = 0x00000002;

  export const EGL_CONTEXT_OPENGL_ROBUST_ACCESS_BIT_KHR = 0x00000004;

  export const EGL_CONTEXT_OPENGL_CORE_PROFILE_BIT_KHR = 0x00000001;

  export const EGL_CONTEXT_OPENGL_COMPATIBILITY_PROFILE_BIT_KHR = 0x00000002;

  export const EGL_OPENGL_ES3_BIT_KHR = 0x00000040;

  export const EGL_CONTEXT_OPENGL_NO_ERROR_KHR = 0x31B3;

  export const EGL_OBJECT_THREAD_KHR = 0x33B0;

  export const EGL_OBJECT_DISPLAY_KHR = 0x33B1;

  export const EGL_OBJECT_CONTEXT_KHR = 0x33B2;

  export const EGL_OBJECT_SURFACE_KHR = 0x33B3;

  export const EGL_OBJECT_IMAGE_KHR = 0x33B4;

  export const EGL_OBJECT_SYNC_KHR = 0x33B5;

  export const EGL_OBJECT_STREAM_KHR = 0x33B6;

  export const EGL_DEBUG_MSG_CRITICAL_KHR = 0x33B9;

  export const EGL_DEBUG_MSG_ERROR_KHR = 0x33BA;

  export const EGL_DEBUG_MSG_WARN_KHR = 0x33BB;

  export const EGL_DEBUG_MSG_INFO_KHR = 0x33BC;

  export const EGL_DEBUG_CALLBACK_KHR = 0x33B8;

  export const EGL_TRACK_REFERENCES_KHR = 0x3352;

  export const EGL_SYNC_PRIOR_COMMANDS_COMPLETE_KHR = 0x30F0;

  export const EGL_SYNC_CONDITION_KHR = 0x30F8;

  export const EGL_SYNC_FENCE_KHR = 0x30F9;

  export const EGL_GL_COLORSPACE_KHR = 0x309D;

  export const EGL_GL_COLORSPACE_SRGB_KHR = 0x3089;

  export const EGL_GL_COLORSPACE_LINEAR_KHR = 0x308A;

  export const EGL_GL_RENDERBUFFER_KHR = 0x30B9;

  export const EGL_GL_TEXTURE_2D_KHR = 0x30B1;

  export const EGL_GL_TEXTURE_LEVEL_KHR = 0x30BC;

  export const EGL_GL_TEXTURE_3D_KHR = 0x30B2;

  export const EGL_GL_TEXTURE_ZOFFSET_KHR = 0x30BD;

  export const EGL_GL_TEXTURE_CUBE_MAP_POSITIVE_X_KHR = 0x30B3;

  export const EGL_GL_TEXTURE_CUBE_MAP_NEGATIVE_X_KHR = 0x30B4;

  export const EGL_GL_TEXTURE_CUBE_MAP_POSITIVE_Y_KHR = 0x30B5;

  export const EGL_GL_TEXTURE_CUBE_MAP_NEGATIVE_Y_KHR = 0x30B6;

  export const EGL_GL_TEXTURE_CUBE_MAP_POSITIVE_Z_KHR = 0x30B7;

  export const EGL_GL_TEXTURE_CUBE_MAP_NEGATIVE_Z_KHR = 0x30B8;

  export const EGL_NATIVE_PIXMAP_KHR = 0x30B0;

  export const EGL_NO_IMAGE_KHR: null;

  export const EGL_IMAGE_PRESERVED_KHR = 0x30D2;

  export const EGL_READ_SURFACE_BIT_KHR = 0x0001;

  export const EGL_WRITE_SURFACE_BIT_KHR = 0x0002;

  export const EGL_LOCK_SURFACE_BIT_KHR = 0x0080;

  export const EGL_OPTIMAL_FORMAT_BIT_KHR = 0x0100;

  export const EGL_MATCH_FORMAT_KHR = 0x3043;

  export const EGL_FORMAT_RGB_565_EXACT_KHR = 0x30C0;

  export const EGL_FORMAT_RGB_565_KHR = 0x30C1;

  export const EGL_FORMAT_RGBA_8888_EXACT_KHR = 0x30C2;

  export const EGL_FORMAT_RGBA_8888_KHR = 0x30C3;

  export const EGL_MAP_PRESERVE_PIXELS_KHR = 0x30C4;

  export const EGL_LOCK_USAGE_HINT_KHR = 0x30C5;

  export const EGL_BITMAP_POINTER_KHR = 0x30C6;

  export const EGL_BITMAP_PITCH_KHR = 0x30C7;

  export const EGL_BITMAP_ORIGIN_KHR = 0x30C8;

  export const EGL_BITMAP_PIXEL_RED_OFFSET_KHR = 0x30C9;

  export const EGL_BITMAP_PIXEL_GREEN_OFFSET_KHR = 0x30CA;

  export const EGL_BITMAP_PIXEL_BLUE_OFFSET_KHR = 0x30CB;

  export const EGL_BITMAP_PIXEL_ALPHA_OFFSET_KHR = 0x30CC;

  export const EGL_BITMAP_PIXEL_LUMINANCE_OFFSET_KHR = 0x30CD;

  export const EGL_LOWER_LEFT_KHR = 0x30CE;

  export const EGL_UPPER_LEFT_KHR = 0x30CF;

  export const EGL_BITMAP_PIXEL_SIZE_KHR = 0x3110;

  export const EGL_MUTABLE_RENDER_BUFFER_BIT_KHR = 0x1000;

  export const EGL_NO_CONFIG_KHR: number;

  export const EGL_BUFFER_AGE_KHR = 0x313D;

  export const EGL_PLATFORM_ANDROID_KHR = 0x3141;

  export const EGL_PLATFORM_GBM_KHR = 0x31D7;

  export const EGL_PLATFORM_OHOS_KHR = 0x34E0;

  export const EGL_PLATFORM_WAYLAND_KHR = 0x31D8;

  export const EGL_PLATFORM_X11_KHR = 0x31D5;

  export const EGL_PLATFORM_X11_SCREEN_KHR = 0x31D6;

  export const EGL_SYNC_STATUS_KHR = 0x30F1;

  export const EGL_SIGNALED_KHR = 0x30F2;

  export const EGL_UNSIGNALED_KHR = 0x30F3;

  export const EGL_TIMEOUT_EXPIRED_KHR = 0x30F5;

  export const EGL_CONDITION_SATISFIED_KHR = 0x30F6;

  export const EGL_SYNC_TYPE_KHR = 0x30F7;

  export const EGL_SYNC_REUSABLE_KHR = 0x30FA;

  export const EGL_SYNC_FLUSH_COMMANDS_BIT_KHR = 0x0001;

  export const EGL_FOREVER_KHR: number;

  export const EGL_NO_SYNC_KHR: number;

  export const EGL_NO_STREAM_KHR: number;

  export const EGL_CONSUMER_LATENCY_USEC_KHR = 0x3210;

  export const EGL_PRODUCER_FRAME_KHR = 0x3212;

  export const EGL_CONSUMER_FRAME_KHR = 0x3213;

  export const EGL_STREAM_STATE_KHR = 0x3214;

  export const EGL_STREAM_STATE_CREATED_KHR = 0x3215;

  export const EGL_STREAM_STATE_CONNECTING_KHR = 0x3216;

  export const EGL_STREAM_STATE_EMPTY_KHR = 0x3217;

  export const EGL_STREAM_STATE_NEW_FRAME_AVAILABLE_KHR = 0x3218;

  export const EGL_STREAM_STATE_OLD_FRAME_AVAILABLE_KHR = 0x3219;

  export const EGL_STREAM_STATE_DISCONNECTED_KHR = 0x321A;

  export const EGL_BAD_STREAM_KHR = 0x321B;

  export const EGL_BAD_STATE_KHR = 0x321C;

  export const EGL_STREAM_FIFO_LENGTH_KHR = 0x31FC;

  export const EGL_STREAM_TIME_NOW_KHR = 0x31FD;

  export const EGL_STREAM_TIME_CONSUMER_KHR = 0x31FE;

  export const EGL_STREAM_TIME_PRODUCER_KHR = 0x31FF;

  export const EGL_STREAM_BIT_KHR = 0x0800;

  export const EGL_NATIVE_BUFFER_USAGE_ANDROID = 0x3143;

  export const EGL_NATIVE_BUFFER_USAGE_PROTECTED_BIT_ANDROID = 0x00000001;

  export const EGL_NATIVE_BUFFER_USAGE_RENDERBUFFER_BIT_ANDROID = 0x00000002;

  export const EGL_NATIVE_BUFFER_USAGE_TEXTURE_BIT_ANDROID = 0x00000004;

  export const EGL_FRAMEBUFFER_TARGET_ANDROID = 0x3147;

  export const EGL_FRONT_BUFFER_AUTO_REFRESH_ANDROID = 0x314C;

  export const EGL_TIMESTAMP_PENDING_ANDROID = 2;

  export const EGL_TIMESTAMP_INVALID_ANDROID = 1;

  export const EGL_TIMESTAMPS_ANDROID = 0x3430;

  export const EGL_COMPOSITE_DEADLINE_ANDROID = 0x3431;

  export const EGL_COMPOSITE_INTERVAL_ANDROID = 0x3432;

  export const EGL_COMPOSITE_TO_PRESENT_LATENCY_ANDROID = 0x3433;

  export const EGL_REQUESTED_PRESENT_TIME_ANDROID = 0x3434;

  export const EGL_RENDERING_COMPLETE_TIME_ANDROID = 0x3435;

  export const EGL_COMPOSITION_LATCH_TIME_ANDROID = 0x3436;

  export const EGL_FIRST_COMPOSITION_START_TIME_ANDROID = 0x3437;

  export const EGL_LAST_COMPOSITION_START_TIME_ANDROID = 0x3438;

  export const EGL_FIRST_COMPOSITION_GPU_FINISHED_TIME_ANDROID = 0x3439;

  export const EGL_DISPLAY_PRESENT_TIME_ANDROID = 0x343A;

  export const EGL_DEQUEUE_READY_TIME_ANDROID = 0x343B;

  export const EGL_READS_DONE_TIME_ANDROID = 0x343C;

  export const EGL_NATIVE_BUFFER_ANDROID = 0x3140;

  export const EGL_SYNC_NATIVE_FENCE_ANDROID = 0x3144;

  export const EGL_SYNC_NATIVE_FENCE_FD_ANDROID = 0x3145;

  export const EGL_RECORDABLE_ANDROID = 0x3142;

  export const EGL_D3D9_DEVICE_ANGLE = 0x33A0;

  export const EGL_D3D11_DEVICE_ANGLE = 0x33A1;

  export const EGL_FIXED_SIZE_ANGLE = 0x3201;

  export const EGL_COLOR_COMPONENT_TYPE_UNSIGNED_INTEGER_ARM = 0x3287;

  export const EGL_COLOR_COMPONENT_TYPE_INTEGER_ARM = 0x3288;

  export const EGL_DISCARD_SAMPLES_ARM = 0x3286;

  export const EGL_FRONT_BUFFER_EXT = 0x3464;

  export const EGL_BUFFER_AGE_EXT = 0x313D;

  export const EGL_SYNC_CLIENT_EXT = 0x3364;

  export const EGL_SYNC_CLIENT_SIGNAL_EXT = 0x3365;

  export const EGL_PRIMARY_COMPOSITOR_CONTEXT_EXT = 0x3460;

  export const EGL_EXTERNAL_REF_ID_EXT = 0x3461;

  export const EGL_COMPOSITOR_DROP_NEWEST_FRAME_EXT = 0x3462;

  export const EGL_COMPOSITOR_KEEP_NEWEST_FRAME_EXT = 0x3463;

  export const EGL_CONFIG_SELECT_GROUP_EXT = 0x34C0;

  export const EGL_CONTEXT_OPENGL_ROBUST_ACCESS_EXT = 0x30BF;

  export const EGL_CONTEXT_OPENGL_RESET_NOTIFICATION_STRATEGY_EXT = 0x3138;

  export const EGL_NO_RESET_NOTIFICATION_EXT = 0x31BE;

  export const EGL_LOSE_CONTEXT_ON_RESET_EXT = 0x31BF;

  export const EGL_NO_DEVICE_EXT: number;

  export const EGL_BAD_DEVICE_EXT = 0x322B;

  export const EGL_DEVICE_EXT = 0x322C;

  export const EGL_DRM_DEVICE_FILE_EXT = 0x3233;

  export const EGL_DRM_MASTER_FD_EXT = 0x333C;

  export const EGL_DRM_RENDER_NODE_FILE_EXT = 0x3377;

  export const EGL_OPENWF_DEVICE_ID_EXT = 0x3237;

  export const EGL_OPENWF_DEVICE_EXT = 0x333D;

  export const EGL_DEVICE_UUID_EXT = 0x335C;

  export const EGL_DRIVER_UUID_EXT = 0x335D;

  export const EGL_DRIVER_NAME_EXT = 0x335E;

  export const EGL_RENDERER_EXT = 0x335F;

  export const EGL_GL_COLORSPACE_BT2020_LINEAR_EXT = 0x333F;

  export const EGL_GL_COLORSPACE_BT2020_PQ_EXT = 0x3340;

  export const EGL_GL_COLORSPACE_DISPLAY_P3_EXT = 0x3363;

  export const EGL_GL_COLORSPACE_DISPLAY_P3_LINEAR_EXT = 0x3362;

  export const EGL_GL_COLORSPACE_DISPLAY_P3_PASSTHROUGH_EXT = 0x3490;

  export const EGL_GL_COLORSPACE_SCRGB_EXT = 0x3351;

  export const EGL_GL_COLORSPACE_SCRGB_LINEAR_EXT = 0x3350;

  export const EGL_LINUX_DMA_BUF_EXT = 0x3270;

  export const EGL_LINUX_DRM_FOURCC_EXT = 0x3271;

  export const EGL_DMA_BUF_PLANE0_FD_EXT = 0x3272;

  export const EGL_DMA_BUF_PLANE0_OFFSET_EXT = 0x3273;

  export const EGL_DMA_BUF_PLANE0_PITCH_EXT = 0x3274;

  export const EGL_DMA_BUF_PLANE1_FD_EXT = 0x3275;

  export const EGL_DMA_BUF_PLANE1_OFFSET_EXT = 0x3276;

  export const EGL_DMA_BUF_PLANE1_PITCH_EXT = 0x3277;

  export const EGL_DMA_BUF_PLANE2_FD_EXT = 0x3278;

  export const EGL_DMA_BUF_PLANE2_OFFSET_EXT = 0x3279;

  export const EGL_DMA_BUF_PLANE2_PITCH_EXT = 0x327A;

  export const EGL_YUV_COLOR_SPACE_HINT_EXT = 0x327B;

  export const EGL_SAMPLE_RANGE_HINT_EXT = 0x327C;

  export const EGL_YUV_CHROMA_HORIZONTAL_SITING_HINT_EXT = 0x327D;

  export const EGL_YUV_CHROMA_VERTICAL_SITING_HINT_EXT = 0x327E;

  export const EGL_ITU_REC601_EXT = 0x327F;

  export const EGL_ITU_REC709_EXT = 0x3280;

  export const EGL_ITU_REC2020_EXT = 0x3281;

  export const EGL_YUV_FULL_RANGE_EXT = 0x3282;

  export const EGL_YUV_NARROW_RANGE_EXT = 0x3283;

  export const EGL_YUV_CHROMA_SITING_0_EXT = 0x3284;

  export const EGL_YUV_CHROMA_SITING_0_5_EXT = 0x3285;

  export const EGL_DMA_BUF_PLANE3_FD_EXT = 0x3440;

  export const EGL_DMA_BUF_PLANE3_OFFSET_EXT = 0x3441;

  export const EGL_DMA_BUF_PLANE3_PITCH_EXT = 0x3442;

  export const EGL_DMA_BUF_PLANE0_MODIFIER_LO_EXT = 0x3443;

  export const EGL_DMA_BUF_PLANE0_MODIFIER_HI_EXT = 0x3444;

  export const EGL_DMA_BUF_PLANE1_MODIFIER_LO_EXT = 0x3445;

  export const EGL_DMA_BUF_PLANE1_MODIFIER_HI_EXT = 0x3446;

  export const EGL_DMA_BUF_PLANE2_MODIFIER_LO_EXT = 0x3447;

  export const EGL_DMA_BUF_PLANE2_MODIFIER_HI_EXT = 0x3448;

  export const EGL_DMA_BUF_PLANE3_MODIFIER_LO_EXT = 0x3449;

  export const EGL_DMA_BUF_PLANE3_MODIFIER_HI_EXT = 0x344A;

  export const EGL_GL_COLORSPACE_DEFAULT_EXT = 0x314D;

  export const EGL_IMPORT_SYNC_TYPE_EXT = 0x3470;

  export const EGL_IMPORT_IMPLICIT_SYNC_EXT = 0x3471;

  export const EGL_IMPORT_EXPLICIT_SYNC_EXT = 0x3472;

  export const EGL_MULTIVIEW_VIEW_COUNT_EXT = 0x3134;

  export const EGL_NO_OUTPUT_LAYER_EXT: number;

  export const EGL_NO_OUTPUT_PORT_EXT: number;

  export const EGL_BAD_OUTPUT_LAYER_EXT = 0x322D;

  export const EGL_BAD_OUTPUT_PORT_EXT = 0x322E;

  export const EGL_SWAP_INTERVAL_EXT = 0x322F;

  export const EGL_DRM_CRTC_EXT = 0x3234;

  export const EGL_DRM_PLANE_EXT = 0x3235;

  export const EGL_DRM_CONNECTOR_EXT = 0x3236;

  export const EGL_OPENWF_PIPELINE_ID_EXT = 0x3238;

  export const EGL_OPENWF_PORT_ID_EXT = 0x3239;

  export const EGL_COLOR_COMPONENT_TYPE_EXT = 0x3339;

  export const EGL_COLOR_COMPONENT_TYPE_FIXED_EXT = 0x333A;

  export const EGL_COLOR_COMPONENT_TYPE_FLOAT_EXT = 0x333B;

  export const EGL_PLATFORM_DEVICE_EXT = EGLPlatform.EGL_PLATFORM_DEVICE_EXT;

  export const EGL_PLATFORM_WAYLAND_EXT = EGLPlatform.EGL_PLATFORM_WAYLAND_EXT;

  export const EGL_PLATFORM_X11_EXT = EGLPlatform.EGL_PLATFORM_X11_EXT;

  export const EGL_PLATFORM_X11_SCREEN_EXT = EGLPlatform.EGL_PLATFORM_X11_SCREEN_EXT;

  export const EGL_PLATFORM_XCB_EXT = EGLPlatform.EGL_PLATFORM_XCB_EXT;

  export const EGL_PLATFORM_XCB_SCREEN_EXT = EGLPlatform.EGL_PLATFORM_XCB_SCREEN_EXT;

  export const EGL_PRESENT_OPAQUE_EXT = 0x31DF;

  export const EGL_PROTECTED_CONTENT_EXT = 0x32C0;

  export const EGL_CTA861_3_MAX_CONTENT_LIGHT_LEVEL_EXT = 0x3360;

  export const EGL_CTA861_3_MAX_FRAME_AVERAGE_LEVEL_EXT = 0x3361;

  export const EGL_SMPTE2086_DISPLAY_PRIMARY_RX_EXT = 0x3341;

  export const EGL_SMPTE2086_DISPLAY_PRIMARY_RY_EXT = 0x3342;

  export const EGL_SMPTE2086_DISPLAY_PRIMARY_GX_EXT = 0x3343;

  export const EGL_SMPTE2086_DISPLAY_PRIMARY_GY_EXT = 0x3344;

  export const EGL_SMPTE2086_DISPLAY_PRIMARY_BX_EXT = 0x3345;

  export const EGL_SMPTE2086_DISPLAY_PRIMARY_BY_EXT = 0x3346;

  export const EGL_SMPTE2086_WHITE_POINT_X_EXT = 0x3347;

  export const EGL_SMPTE2086_WHITE_POINT_Y_EXT = 0x3348;

  export const EGL_SMPTE2086_MAX_LUMINANCE_EXT = 0x3349;

  export const EGL_SMPTE2086_MIN_LUMINANCE_EXT = 0x334A;

  export const EGL_METADATA_SCALING_EXT = 50000;

  export const EGL_SURFACE_COMPRESSION_EXT = 0x34B0;

  export const EGL_SURFACE_COMPRESSION_PLANE1_EXT = 0x328E;

  export const EGL_SURFACE_COMPRESSION_PLANE2_EXT = 0x328F;

  export const EGL_SURFACE_COMPRESSION_FIXED_RATE_NONE_EXT = 0x34B1;

  export const EGL_SURFACE_COMPRESSION_FIXED_RATE_DEFAULT_EXT = 0x34B2;

  export const EGL_SURFACE_COMPRESSION_FIXED_RATE_1BPC_EXT = 0x34B4;

  export const EGL_SURFACE_COMPRESSION_FIXED_RATE_2BPC_EXT = 0x34B5;

  export const EGL_SURFACE_COMPRESSION_FIXED_RATE_3BPC_EXT = 0x34B6;

  export const EGL_SURFACE_COMPRESSION_FIXED_RATE_4BPC_EXT = 0x34B7;

  export const EGL_SURFACE_COMPRESSION_FIXED_RATE_5BPC_EXT = 0x34B8;

  export const EGL_SURFACE_COMPRESSION_FIXED_RATE_6BPC_EXT = 0x34B9;

  export const EGL_SURFACE_COMPRESSION_FIXED_RATE_7BPC_EXT = 0x34BA;

  export const EGL_SURFACE_COMPRESSION_FIXED_RATE_8BPC_EXT = 0x34BB;

  export const EGL_SURFACE_COMPRESSION_FIXED_RATE_9BPC_EXT = 0x34BC;

  export const EGL_SURFACE_COMPRESSION_FIXED_RATE_10BPC_EXT = 0x34BD;

  export const EGL_SURFACE_COMPRESSION_FIXED_RATE_11BPC_EXT = 0x34BE;

  export const EGL_SURFACE_COMPRESSION_FIXED_RATE_12BPC_EXT = 0x34BF;

  export const EGL_YUV_ORDER_EXT = 0x3301;

  export const EGL_YUV_NUMBER_OF_PLANES_EXT = 0x3311;

  export const EGL_YUV_SUBSAMPLE_EXT = 0x3312;

  export const EGL_YUV_DEPTH_RANGE_EXT = 0x3317;

  export const EGL_YUV_CSC_STANDARD_EXT = 0x330A;

  export const EGL_YUV_PLANE_BPP_EXT = 0x331A;

  export const EGL_YUV_BUFFER_EXT = 0x3300;

  export const EGL_YUV_ORDER_YUV_EXT = 0x3302;

  export const EGL_YUV_ORDER_YVU_EXT = 0x3303;

  export const EGL_YUV_ORDER_YUYV_EXT = 0x3304;

  export const EGL_YUV_ORDER_UYVY_EXT = 0x3305;

  export const EGL_YUV_ORDER_YVYU_EXT = 0x3306;

  export const EGL_YUV_ORDER_VYUY_EXT = 0x3307;

  export const EGL_YUV_ORDER_AYUV_EXT = 0x3308;

  export const EGL_YUV_SUBSAMPLE_4_2_0_EXT = 0x3313;

  export const EGL_YUV_SUBSAMPLE_4_2_2_EXT = 0x3314;

  export const EGL_YUV_SUBSAMPLE_4_4_4_EXT = 0x3315;

  export const EGL_YUV_DEPTH_RANGE_LIMITED_EXT = 0x3318;

  export const EGL_YUV_DEPTH_RANGE_FULL_EXT = 0x3319;

  export const EGL_YUV_CSC_STANDARD_601_EXT = 0x330B;

  export const EGL_YUV_CSC_STANDARD_709_EXT = 0x330C;

  export const EGL_YUV_CSC_STANDARD_2020_EXT = 0x330D;

  export const EGL_YUV_PLANE_BPP_0_EXT = 0x331B;

  export const EGL_YUV_PLANE_BPP_8_EXT = 0x331C;

  export const EGL_YUV_PLANE_BPP_10_EXT = 0x331D;

  export const EGL_CLIENT_PIXMAP_POINTER_HI = 0x8F74;

  export const EGL_COLOR_FORMAT_HI = 0x8F70;

  export const EGL_COLOR_RGB_HI = 0x8F71;

  export const EGL_COLOR_RGBA_HI = 0x8F72;

  export const EGL_COLOR_ARGB_HI = 0x8F73;

  export const EGL_CONTEXT_PRIORITY_LEVEL_IMG = 0x3100;

  export const EGL_CONTEXT_PRIORITY_HIGH_IMG = 0x3101;

  export const EGL_CONTEXT_PRIORITY_MEDIUM_IMG = 0x3102;

  export const EGL_CONTEXT_PRIORITY_LOW_IMG = 0x3103;

  export const EGL_DRM_BUFFER_FORMAT_MESA = 0x31D0;

  export const EGL_DRM_BUFFER_USE_MESA = 0x31D1;

  export const EGL_DRM_BUFFER_FORMAT_ARGB32_MESA = 0x31D2;

  export const EGL_DRM_BUFFER_MESA = 0x31D3;

  export const EGL_DRM_BUFFER_STRIDE_MESA = 0x31D4;

  export const EGL_DRM_BUFFER_USE_SCANOUT_MESA = 0x00000001;

  export const EGL_DRM_BUFFER_USE_SHARE_MESA = 0x00000002;

  export const EGL_DRM_BUFFER_USE_CURSOR_MESA = 0x00000004;

  export const EGL_PLATFORM_GBM_MESA = 0x31D7;

  export const EGL_PLATFORM_SURFACELESS_MESA = 0x31DD;

  export const EGL_Y_INVERTED_NOK = 0x307F;

  export const EGL_AUTO_STEREO_NV = 0x3136;

  export const EGL_CONTEXT_PRIORITY_REALTIME_NV = 0x3357;

  export const EGL_COVERAGE_BUFFERS_NV = 0x30E0;

  export const EGL_COVERAGE_SAMPLES_NV = 0x30E1;

  export const EGL_COVERAGE_SAMPLE_RESOLVE_NV = 0x3131;

  export const EGL_COVERAGE_SAMPLE_RESOLVE_DEFAULT_NV = 0x3132;

  export const EGL_COVERAGE_SAMPLE_RESOLVE_NONE_NV = 0x3133;

  export const EGL_CUDA_EVENT_HANDLE_NV = 0x323B;

  export const EGL_SYNC_CUDA_EVENT_NV = 0x323C;

  export const EGL_SYNC_CUDA_EVENT_COMPLETE_NV = 0x323D;

  export const EGL_DEPTH_ENCODING_NV = 0x30E2;

  export const EGL_DEPTH_ENCODING_NONE_NV = 0;

  export const EGL_DEPTH_ENCODING_NONLINEAR_NV = 0x30E3;

  export const EGL_CUDA_DEVICE_NV = 0x323A;

  export const EGL_POST_SUB_BUFFER_SUPPORTED_NV = 0x30BE;

  export const EGL_QUADRUPLE_BUFFER_NV = 0x3231;

  export const EGL_GENERATE_RESET_ON_VIDEO_MEMORY_PURGE_NV = 0x334C;

  export const EGL_STREAM_CONSUMER_IMAGE_NV = 0x3373;

  export const EGL_STREAM_IMAGE_ADD_NV = 0x3374;

  export const EGL_STREAM_IMAGE_REMOVE_NV = 0x3375;

  export const EGL_STREAM_IMAGE_AVAILABLE_NV = 0x3376;

  export const EGL_YUV_PLANE0_TEXTURE_UNIT_NV = 0x332C;

  export const EGL_YUV_PLANE1_TEXTURE_UNIT_NV = 0x332D;

  export const EGL_YUV_PLANE2_TEXTURE_UNIT_NV = 0x332E;

  export const EGL_STREAM_CROSS_DISPLAY_NV = 0x334E;

  export const EGL_STREAM_CROSS_OBJECT_NV = 0x334D;

  export const EGL_STREAM_CROSS_PARTITION_NV = 0x323F;

  export const EGL_STREAM_CROSS_PROCESS_NV = 0x3245;

  export const EGL_STREAM_CROSS_SYSTEM_NV = 0x334F;

  export const EGL_STREAM_DMA_NV = 0x3371;

  export const EGL_STREAM_DMA_SERVER_NV = 0x3372;

  export const EGL_PENDING_FRAME_NV = 0x3329;

  export const EGL_STREAM_TIME_PENDING_NV = 0x332A;

  export const EGL_STREAM_FIFO_SYNCHRONOUS_NV = 0x3336;

  export const EGL_PRODUCER_MAX_FRAME_HINT_NV = 0x3337;

  export const EGL_CONSUMER_MAX_FRAME_HINT_NV = 0x3338;

  export const EGL_PRODUCER_METADATA_NV = 0x3253;

  export const EGL_CONSUMER_METADATA_NV = 0x3254;

  export const EGL_PENDING_METADATA_NV = 0x3328;

  export const EGL_METADATA0_SIZE_NV = 0x3255;

  export const EGL_METADATA1_SIZE_NV = 0x3256;

  export const EGL_METADATA2_SIZE_NV = 0x3257;

  export const EGL_METADATA3_SIZE_NV = 0x3258;

  export const EGL_METADATA0_TYPE_NV = 0x3259;

  export const EGL_METADATA1_TYPE_NV = 0x325A;

  export const EGL_METADATA2_TYPE_NV = 0x325B;

  export const EGL_METADATA3_TYPE_NV = 0x325C;

  export const EGL_STREAM_FRAME_ORIGIN_X_NV = 0x3366;

  export const EGL_STREAM_FRAME_ORIGIN_Y_NV = 0x3367;

  export const EGL_STREAM_FRAME_MAJOR_AXIS_NV = 0x3368;

  export const EGL_CONSUMER_AUTO_ORIENTATION_NV = 0x3369;

  export const EGL_PRODUCER_AUTO_ORIENTATION_NV = 0x336A;

  export const EGL_LEFT_NV = 0x336B;

  export const EGL_RIGHT_NV = 0x336C;

  export const EGL_TOP_NV = 0x336D;

  export const EGL_BOTTOM_NV = 0x336E;

  export const EGL_X_AXIS_NV = 0x336F;

  export const EGL_Y_AXIS_NV = 0x3370;

  export const EGL_STREAM_STATE_INITIALIZING_NV = 0x3240;

  export const EGL_STREAM_TYPE_NV = 0x3241;

  export const EGL_STREAM_PROTOCOL_NV = 0x3242;

  export const EGL_STREAM_ENDPOINT_NV = 0x3243;

  export const EGL_STREAM_LOCAL_NV = 0x3244;

  export const EGL_STREAM_PRODUCER_NV = 0x3247;

  export const EGL_STREAM_CONSUMER_NV = 0x3248;

  export const EGL_STREAM_PROTOCOL_FD_NV = 0x3246;

  export const EGL_SUPPORT_RESET_NV = 0x3334;

  export const EGL_SUPPORT_REUSE_NV = 0x3335;

  export const EGL_STREAM_PROTOCOL_SOCKET_NV = 0x324B;

  export const EGL_SOCKET_HANDLE_NV = 0x324C;

  export const EGL_SOCKET_TYPE_NV = 0x324D;

  export const EGL_SOCKET_TYPE_INET_NV = 0x324F;

  export const EGL_SOCKET_TYPE_UNIX_NV = 0x324E;

  export const EGL_SYNC_NEW_FRAME_NV = 0x321F;

  export const EGL_SYNC_PRIOR_COMMANDS_COMPLETE_NV = 0x30E6;

  export const EGL_SYNC_STATUS_NV = 0x30E7;

  export const EGL_SIGNALED_NV = 0x30E8;

  export const EGL_UNSIGNALED_NV = 0x30E9;

  export const EGL_SYNC_FLUSH_COMMANDS_BIT_NV = 0x0001;

  export const EGL_FOREVER_NV = 0xFFFFFFFFFFFFFFFF;

  export const EGL_ALREADY_SIGNALED_NV = 0x30EA;

  export const EGL_TIMEOUT_EXPIRED_NV = 0x30EB;

  export const EGL_CONDITION_SATISFIED_NV = 0x30EC;

  export const EGL_SYNC_TYPE_NV = 0x30ED;

  export const EGL_SYNC_CONDITION_NV = 0x30EE;

  export const EGL_SYNC_FENCE_NV = 0x30EF;

  export const EGL_TRIPLE_BUFFER_NV = 0x3230;

  export const EGL_NATIVE_BUFFER_OHOS = 0x34E1;

  export const EGL_NATIVE_BUFFER_TIZEN = 0x32A0;

  export const EGL_NATIVE_SURFACE_TIZEN = 0x32A1;

  export const EGL_WAYLAND_BUFFER_WL = 0x31D5;

  export const EGL_WAYLAND_PLANE_WL = 0x31D6;

  export const EGL_TEXTURE_Y_U_V_WL = 0x31D7;

  export const EGL_TEXTURE_Y_UV_WL = 0x31D8;

  export const EGL_TEXTURE_Y_XUXV_WL = 0x31D9;

  export const EGL_TEXTURE_EXTERNAL_WL = 0x31DA;

  export const EGL_WAYLAND_Y_INVERTED_WL = 0x31DB;

  export const EGL_DRAW = READDRAW.EGL_DRAW;

  export const EGL_READ = READDRAW.EGL_READ;

  export const EGL_MAX_PBUFFER_WIDTH = EGLConfigAttribute.EGL_MAX_PBUFFER_WIDTH;

  export const EGL_MAX_PBUFFER_HEIGHT = EGLConfigAttribute.EGL_MAX_PBUFFER_HEIGHT;

  export const EGL_MAX_PBUFFER_PIXELS = EGLConfigAttribute.EGL_MAX_PBUFFER_PIXELS;

  export const EGL_NATIVE_VISUAL_ID = EGLConfigAttribute.EGL_NATIVE_VISUAL_ID;

  export const EGL_NATIVE_VISUAL_TYPE = EGLConfigAttribute.EGL_NATIVE_VISUAL_TYPE;

  export const EGL_CLIENT_APIS = QueryStringNames.EGL_CLIENT_APIS;

  export const EGL_VENDOR = QueryStringNames.EGL_VENDOR;

  export const EGL_VERSION = QueryStringNames.EGL_VERSION;

  export const EGL_EXTENSIONS = QueryStringNames.EGL_EXTENSIONS;

  export const EGL_CORE_NATIVE_ENGINE = 0x305B;

  export const EGL_FOREVER = -1;

  export const EGL_TIMEOUT_EXPIRED = 0x30F5;

  export const EGL_CONDITION_SATISFIED = 0x30F6;

  export const EGL_SYNC_FLUSH_COMMANDS_BIT = 0x0001;

  export const EGL_MIPMAP_LEVEL = 0x3083;

  export const EGL_MULTISAMPLE_RESOLVE = 0x3099;

  export const EGL_SWAP_BEHAVIOR = 0x3093;

  export const EGL_BUFFER_DESTROYED = 0x3095;

  export const EGL_DISPLAY_SCALING = 10000;

  export const EGL_UNKNOWN = -1;

  export const EGL_SUCCESS = EGLError.EGL_SUCCESS;

  export const EGL_NOT_INITIALIZED = EGLError.EGL_NOT_INITIALIZED;

  export const EGL_BAD_ACCESS = EGLError.EGL_BAD_ACCESS;

  export const EGL_BAD_ALLOC = EGLError.EGL_BAD_ALLOC;

  export const EGL_BAD_ATTRIBUTE = EGLError.EGL_BAD_ATTRIBUTE;

  export const EGL_BAD_CONFIG = EGLError.EGL_BAD_CONFIG;

  export const EGL_BAD_CONTEXT = EGLError.EGL_BAD_CONTEXT;

  export const EGL_BAD_CURRENT_SURFACE = EGLError.EGL_BAD_CURRENT_SURFACE;

  export const EGL_BAD_DISPLAY = EGLError.EGL_BAD_DISPLAY;

  export const EGL_BAD_MATCH = EGLError.EGL_BAD_MATCH;

  export const EGL_BAD_NATIVE_PIXMAP = EGLError.EGL_BAD_NATIVE_PIXMAP;

  export const EGL_BAD_NATIVE_WINDOW = EGLError.EGL_BAD_NATIVE_WINDOW;

  export const EGL_BAD_PARAMETER = EGLError.EGL_BAD_PARAMETER;

  export const EGL_BAD_SURFACE = EGLError.EGL_BAD_SURFACE;

  export const EGL_OPENGL_API = EGLApi.EGL_OPENGL_API;

  export const EGL_OPENGL_ES_API = EGLApi.EGL_OPENGL_ES_API;

  export const EGL_OPENVG_API = EGLApi.EGL_OPENVG_API;

  export const EGL_OPENVG_IMAGE = EGLBufferType.EGL_OPENVG_IMAGE;

  export const EGL_CONTEXT_CLIENT_TYPE = 0x3097;

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

}