import * as EGL from 'libegl.so';

import { EGLConfig } from './EGLConfig'
import { EGLContext } from './EGLContext';
import { EGLSurface } from './EGLSurface';
import { EGLSync } from './EGLSync'
import { NativeHelper } from '../NativeHelperr';
import { HashMap } from '@kit.ArkTS';
import { egl } from '../Index'
import { NativePointer } from '../Pointer';

export interface EGLVersion {
  major: number,
  minor: number
}

/**
 * EGLDisplay封装
 */
export class EGLDisplay implements NativePointer {
  private readonly _id: string;
  private _isInit: boolean;
  private _isTerminate: boolean;
  private _major: number;
  private _minor: number;
  private static _display_cache: HashMap<string, EGLDisplay> = new HashMap();

  private constructor(id: string, isInit?: boolean) {
    this._id = id;
    this._isInit = isInit ?? false;
    this._isTerminate = false;
    this._major = 0;
    this._minor = 0;
  }

  /**
   * 获取EGLDisplay对象
   * @param eglNativeDisplayType 输入undefined获取default display
   * @returns
   */
  static getDisplay(eglNativeDisplayType?: string): EGLDisplay | undefined {
    let display_id = EGL.eglGetDisplay(eglNativeDisplayType);
    if (!display_id) {
      return;
    }

    if (EGLDisplay._display_cache.hasKey(display_id)) {
      return EGLDisplay._display_cache.get(display_id);
    }

    let display = new EGLDisplay(display_id);
    EGLDisplay._display_cache.set(display_id, display);
    return display;
  }

  static getCurrentDisplay(): EGLDisplay | undefined {
    let display_id = EGL.eglGetCurrentDisplay();
    if (!display_id) {
      return;
    }
    if (EGLDisplay._display_cache.hasKey(display_id)) {
      return EGLDisplay._display_cache.get(display_id);
    }
    let display = new EGLDisplay(display_id, true);
    EGLDisplay._display_cache.set(display_id, display);
    return display;
  }

  static getPlatformDisplay(platform: egl.EGLPlatform, native_display?: string,
    attrib_list?: number[]): EGLDisplay | undefined {
    let display_id = EGL.eglGetPlatformDisplay(platform, native_display, attrib_list ?? [egl.EGL_NONE]);
    if (!display_id) {
      return;
    }
    if (EGLDisplay._display_cache.hasKey(display_id)) {
      return EGLDisplay._display_cache.get(display_id);
    }
    let display = new EGLDisplay(display_id, true);
    EGLDisplay._display_cache.set(display_id, display);
    return display;
  }


  /**
   * EGLDisplay的id，可以转化成native指针
   * @returns
   */
  get id() {
    this.throwIfTerminate();
    return this._id;
  }

  /**
   * 是否已经终止
   * @returns
   */
  get isTerminate() {
    return this._isTerminate;
  }

  /**
   * 是否初始化
   * @returns
   */
  get isInitialized(): boolean {
    this.throwIfTerminate();
    return this._isInit;
  }

  get major(): number {
    this.throwIfTerminate();
    if (!this._isInit) {
      this.initialize()
    }
    return this._major;
  }

  get minjor(): number {
    this.throwIfTerminate();
    if (!this._isInit) {
      this.initialize()
    }
    return this._minor;
  }

  /**
   * 比较两个EGLDisplay是否相等
   * @param value
   * @returns
   */
  equal(value: EGLDisplay): boolean {
    return value._id == this._id;
  }

  private throwIfTerminate() {
    if (this.isTerminate) {
      throw Error('EGLDisplay is Terminate');
    }
  }

  private ensureInit() {
    this.throwIfTerminate();
    if (!this._isInit) {
      this.initialize();
    }
  }

  /**
   * 调用eglInitialize,调用成功后，可以获取marjor和minjor
   * @returns EGLDisplay初始化是否成功
   */
  initialize(): boolean {
    this.throwIfTerminate();
    if (this._isInit) {
      return true;
    }

    let versions: EGLVersion = { major: 0, minor: 0 };
    let result = EGL.eglInitialize(this._id, versions);
    if (result) {
      //初始化成功，major/minor必定有值
      this._major = versions.major ?? 0;
      this._minor = versions.minor ?? 0;
    }
    this._isInit = result;
    return result;
  }

  /**
   * 调用eglTerminate，终止与EGLDisplay的连接，终止连接后，调用其他方法会抛出异常
   * @returns 终止EGLDisplay是否成功。
   */
  terminate(): boolean {
    if (this._isTerminate) {
      return false;
    }
    if (!this._isInit) {
      return true;
    }
    let result = EGL.eglTerminate(this._id);
    this._isTerminate = result;
    return result;
  }

  /**
   * 调用eglChooseConfig,获取EGLConfig
   * @returns 获取成功返回一个Config列表，否则undefined
   */
  chooseConfig(attrib_list: number[], count?: number): EGLConfig[] {
    this.ensureInit();
    let configs: string[] = [];
    let result: EGLConfig[] = [];
    let isSuccess = EGL.eglChooseConfig(this._id, attrib_list, count ?? 1, configs);
    if (!isSuccess) {
      return result;
    }

    configs.forEach(id => {
      result.push(new EGLConfig(id));
    })
    return result;
  }

  /**
   * 调用eglCreateContext,获取上下文
   * @param config EGLConfig
   * @param share_context EGLContext
   * @param attrib_list EGLint[]
   * @returns
   */
  createContext(config: EGLConfig, share_context?: EGLContext, attrib_list?: number[]): EGLContext | undefined {
    this.ensureInit();
    let context_id = EGL.eglCreateContext(this._id, config.id, share_context?.id, attrib_list ?? [egl.EGL_NONE]);
    if (!context_id) {
      return;
    }

    let context = new EGLContext(context_id);
    return context;
  }

  /**
   * 创建surface
   * @param config EGLConfig(调用chooseConfig获取)
   * @param surfaceId 一般为NativeWindow/XComponent
   * @param attrib_list 配置表
   * @returns
   */
  createSurfaceWindow(config: EGLConfig, surfaceId: string, attrib_list?: number[]): EGLSurface | undefined {
    this.ensureInit();
    let win: string = NativeHelper.getWindowFromSurfaceId(surfaceId);
    let surface_id = EGL.eglCreateWindowSurface(this._id, config.id, win, attrib_list ?? []);
    if (!surface_id) {
      return;
    }

    let surface = new EGLSurface(surface_id);
    return surface;
  }

  /**
   * 绑定线程与上下文
   * @param draw
   * @param read
   * @param context
   * @returns
   */
  makeCurrent(draw: EGLSurface | undefined, read: EGLSurface | undefined, context: EGLContext | undefined): boolean {
    this.ensureInit();
    return EGL.eglMakeCurrent(this._id, draw?.id, read?.id, context?.id);
  }

  /**
   * 创建离屏surface
   * @param config
   * @param attrib_list
   * @returns
   */
  createPbufferSurface(config: EGLConfig, attrib_list?: number[]): EGLSurface | undefined {
    this.ensureInit();
    let surface_id = EGL.eglCreatePbufferSurface(this._id, config.id, attrib_list ?? [egl.EGL_NONE]);
    if (!surface_id) {
      return;
    }

    let surface = new EGLSurface(surface_id);
    return surface;
  }

  /**
   * 销毁上下文
   * @param context
   * @returns
   */
  destroyContext(context: EGLContext): boolean {
    this.ensureInit();
    return EGL.eglDestroyContext(this._id, context.id);
  }

  /**
   * 销毁surface
   * @param surface
   * @returns
   */
  destroySurface(surface: EGLSurface): boolean {
    this.ensureInit();
    return EGL.eglDestroySurface(this._id, surface.id);
  }


  /**
   *对应eglGetConfigs
   */
  getConfigs(count: number): EGLConfig[] | undefined {
    this.ensureInit();
    if (count < 1) {
      throw Error('getConfigs: count必须大于0');
    }
    let config_result: string[] = [];
    let configs: EGLConfig[] = [];
    if (EGL.eglGetConfigs(this._id, count, config_result)) {
      for (let i = 0; i < count; i++) {
        if (config_result[i] == undefined) {
          continue;
        }
        if (config_result[i].length == 0) {
          continue;
        }
        let config = new EGLConfig(config_result[i]);
        configs.push(config);
      }
      return configs;
    }
    return;
  }

  /**
   *eglQueryString
   */
  queryString(name: egl.QueryStringNames): string {
    this.ensureInit();
    return EGL.eglQueryString(this._id, name);
  }

  /**
   *eglSwapBuffers
   */
  swapBuffers(surface: EGLSurface): boolean {
    this.ensureInit();
    return EGL.eglSwapBuffers(this._id, surface.id);
  }

  /**
   *eglCreateSync
   */
  createSync(type: egl.EGLSyncType, attrib_list?: number[]): EGLSync | undefined {
    this.ensureInit();
    let sync_id = EGL.eglCreateSync(this._id, type, attrib_list ?? [egl.EGL_NONE]);
    if (!sync_id) {
      return;
    }
    let sync = new EGLSync(sync_id);
    return sync;
  }

  /**
   *eglDestroySync
   */
  destroySync(sync: EGLSync): boolean {
    this.ensureInit();
    return EGL.eglDestroySync(this._id, sync.id);
  }

  /**
   *https://registry.khronos.org/EGL/sdk/docs/man/html/eglClientWaitSync.xhtml
   */
  clientWaitSync(sync: EGLSync, flags: number, timeout: number): number {
    this.ensureInit();
    return EGL.eglClientWaitSync(this._id, sync.id, flags, timeout);
  }

  /**
   * eglWaitSync
   * https://registry.khronos.org/EGL/sdk/docs/man/html/eglWaitSync.xhtml
   * @param flag must be 0?
   */
  waitSync(sync: EGLSync, flags: number): boolean {
    this.ensureInit();
    return EGL.eglWaitSync(this._id, sync.id, flags);
  }

  /**
   *https://registry.khronos.org/EGL/sdk/docs/man/html/eglGetSyncAttrib.xhtml
   * @param attribute EGL_SYNC_TYPE / EGL_SYNC_STATUS / EGL_SYNC_CONDITION
   */
  getSyncAttrib(sync: EGLSync, attribute: number): number | undefined {
    this.ensureInit();
    let temp = new BigInt64Array(1);
    if (EGL.eglGetSyncAttrib(this._id, sync.id, attribute, temp)) {
      return Number(temp[0]);
    }
    return;
  }

  /**
   *eglSwapInterval
   */
  swapInterval(interval: number): boolean {
    this.ensureInit();
    return EGL.eglSwapInterval(this._id, interval);
  }

  /**
   * https://registry.khronos.org/EGL/sdk/docs/man/html/eglCreatePlatformPixmapSurface.xhtml
   * @param attrib_list EGL_GL_COLORSPACE / EGL_VG_ALPHA_FORMAT / EGL_VG_COLORSPACE
   */
  createPlatformPixmapSurface(config: EGLConfig, native_pixmap_ptr?: string,
    attrib_list?: number[]): EGLSurface | undefined {
    this.ensureInit();
    let surface_id =
      EGL.eglCreatePlatformPixmapSurface(this._id, config.id, native_pixmap_ptr, attrib_list ?? [egl.EGL_NONE]);
    if (!surface_id) {
      return;
    }

    return new EGLSurface(surface_id);
  }

  /**
   * https://registry.khronos.org/EGL/sdk/docs/man/html/eglCreatePlatformWindowSurface.xhtml
   * @param attrib_list EGL_GL_COLORSPACE / EGL_RENDER_BUFFER / EGL_VG_ALPHA_FORMAT / EGL_VG_COLORSPACE
   */
  createPlatformWindowSurface(config: EGLConfig, native_window_ptr?: string,
    attrib_list?: number[]): EGLSurface | undefined {
    this.ensureInit();
    let surface_id =
      EGL.eglCreatePlatformWindowSurface(this._id, config.id, native_window_ptr, attrib_list ?? [egl.EGL_NONE]);
    if (!surface_id) {
      return;
    }
    return new EGLSurface(surface_id);
  }

  /**
   *https://registry.khronos.org/EGL/sdk/docs/man/html/eglCreateImage.xhtml
   * @parm attr_list EGL_GL_TEXTURE_LEVEL / EGL_GL_TEXTURE_ZOFFSET / EGL_IMAGE?PRESERVER
   */
  createImage(context: EGLContext, target: egl.EGLImageType, attrib_list?: number[]) {

  }
}