import { image } from "@kit.ImageKit";

export interface NativeBufferConfig {
  width: number;
  height: number;
  format: number;
  usage: number;
  stride: number;
}


export interface EGLVersion {
  major: number;
  minor: number;
}


@Sendable
export class EGLDisplay {
  private constructor()

  static getDisplay(eglNativeDisplayType?: string): EGLDisplay | undefined

  static getCurrentDisplay(): EGLDisplay | undefined

  static getPlatformDisplay(platform: number, native_display?: string,
    attrib_list?: number[]): EGLDisplay | undefined

  initialize(): EGLVersion | undefined

  terminate(): boolean

  chooseConfig(attrib_list: number[], count?: number): EGLConfig[] | undefined

  createContext(config: EGLConfig, share_context?: EGLContext, attrib_list?: number[]): EGLContext | undefined

  createWindowSurface(config: EGLConfig, surfaceId: string, attrib_list?: number[]): EGLSurface | undefined

  makeCurrent(draw: EGLSurface | undefined, read: EGLSurface | undefined, context: EGLContext | undefined): boolean

  createPbufferSurface(config: EGLConfig, attrib_list?: number[]): EGLSurface | undefined

  destroyContext(context: EGLContext): boolean

  destroySurface(surface: EGLSurface): boolean

  getConfigs(count: number): EGLConfig[] | undefined

  queryString(name: number): string | undefined

  swapBuffers(surface: EGLSurface): boolean

  createSync(type: number, attrib_list?: number[]): EGLSync | undefined

  destroySync(sync: EGLSync): boolean

  clientWaitSync(sync: EGLSync, flags: number, timeout: number): number

  waitSync(sync: EGLSync, flags: number): boolean

  getSyncAttrib(sync: EGLSync, attribute: number): number | undefined

  swapInterval(interval: number): boolean

  createPlatformPixmapSurface(config: EGLConfig, native_pixmap_ptr?: string,
    attrib_list?: number[]): EGLSurface | undefined

  createPlatformWindowSurface(config: EGLConfig, native_window_ptr?: string,
    attrib_list?: number[]): EGLSurface | undefined

  createImageKHR(target: number, context: EGLContext, buffer: NativeBuffer,
    attrib_list?: number[]): EGLImageKHR | undefined

  destroyImageKHR(image: EGLImageKHR): boolean

  copyBuffers(surface: EGLSurface, target: image.PixelMap): boolean

  createPixmapSurface(config: EGLConfig, pixmap: image.PixelMap, attrib_list?: number[]): EGLSurface | undefined
}

@Sendable
export class EGLConfig {
  private constructor()

  getConfigAttrib(dpy: EGLDisplay, attribute: number): number | undefined
}

@Sendable
export class EGLContext {
  private constructor()

  static getCurrentContext(): EGLContext | undefined

  query(dpy: EGLDisplay, attribute: number): number | undefined
}

@Sendable
export class EGLSurface {
  private constructor()

  static getCurrentSurface(readdraw: number): EGLSurface | undefined

  setAttribute(dpy: EGLDisplay, attribute: number, value: number): boolean

  query(dpy: EGLDisplay, attribute: number): number | undefined

  bindTexImage(dpy: EGLDisplay, buffer: number): boolean

  releaseTexImage(dpy: EGLDisplay, buffer: number): boolean
}

@Sendable
export class EGLImage {
  private constructor()
}

@Sendable
export class EGLImageKHR {
  private constructor()
}

@Sendable
export class EGLSync {
  private constructor()
}

@Sendable
export class EGLSyncKHR {
  private constructor()
}

@Sendable
export class NativeBuffer {
  constructor(config: NativeBufferConfig)

  destroy(): boolean
}

export function eglGetDisplay(display_id?: string): EGLDisplay | undefined;

export function eglInitialize(dpy: EGLDisplay): EGLVersion | undefined;

export function eglChooseConfig(dpy: EGLDisplay, attrib_list: number[], config_size?: number): EGLConfig[] | undefined

export function eglGetError(): number;

export function eglCreateWindowSurface(dpy: EGLDisplay, config: EGLConfig, surfaceId: string,
  attrib_list?: number[]): EGLSurface | undefined

export function eglMakeCurrent(dpy: EGLDisplay, draw: EGLSurface | undefined, read: EGLSurface | undefined,
  ctx: EGLContext): boolean;

export function eglCreatePbufferSurface(dpy: EGLDisplay, config: EGLConfig,
  attrib_list?: number[]): EGLSurface | undefined

export function eglDestroyContext(dpy: EGLDisplay, context: EGLContext): boolean

export function eglDestroySurface(dpy: EGLDisplay, surface: EGLSurface): boolean

export function eglGetConfigAttrib(dpy: EGLDisplay, config: EGLConfig, attribute: number): number | undefined

export function eglGetConfigs(dpy: EGLDisplay, config_size?: number): EGLConfig[] | undefined

export function eglGetCurrentDisplay(): EGLDisplay | undefined

export function eglGetCurrentSurface(readdraw: number): EGLSurface | undefined

export function eglGetProcAddress(procName: string): string | undefined

export function eglQueryContext(dpy: EGLDisplay, context: EGLContext, attribute: number): number | undefined

export function eglQueryString(dpy: EGLDisplay, name: number): string | undefined

export function eglQuerySurface(dpy: EGLDisplay, surface: EGLSurface, attribute: number): number | undefined

export function eglSwapBuffers(dpy: EGLDisplay, surface: EGLSurface): boolean

export function eglTerminate(dpy: EGLDisplay): boolean

export function eglWaitGL(): boolean

export function eglWaitNative(engine: number): boolean

export function eglBindTexImage(dpy: EGLDisplay, surface: EGLSurface, buffer: number): boolean

export function eglReleaseTexImage(dpy: EGLDisplay, surface: EGLSurface, buffer: number): boolean

export function eglSurfaceAttrib(dpy: EGLDisplay, surface: EGLSurface, attribute: number, value: number): boolean

export function eglSwapInterval(dpy: EGLDisplay, interval: number): boolean

export function eglBindAPI(api: number): boolean

export function eglQueryAPI(): number

export function eglReleaseThread(): boolean

export function eglWaitClient(): boolean

export function eglGetCurrentContext(): EGLContext | undefined

export function eglCreateSync(dpy: EGLDisplay, type: number, attrib_list?: number[]): EGLSync | undefined

export function eglDestroySync(dpy: EGLDisplay, sync: EGLSync): boolean

export function eglClientWaitSync(dpy: EGLDisplay, sync: EGLSync, flags: number, timeout: number): number

export function eglGetSyncAttrib(dpy: EGLDisplay, sync: EGLSync, attribute: number): number | undefined

export function eglCreateImage(dpy: EGLDisplay, context: EGLContext, target: number, buffer: NativeBuffer,
  attrib_list?: number[]): EGLImage | undefined

export function eglDestroyImage(dpy: EGLDisplay, image: EGLImage): boolean

export function eglGetPlatformDisplay(platform: number, native_display?: string,
  attrib_list?: number[]): EGLDisplay | undefined

export function eglCreatePlatformWindowSurface(dpy: EGLDisplay, config: EGLConfig, native_window?: string,
  attrib_list?: number[]): EGLSurface | undefined

export function eglCreatePlatformPixmapSurface(dpy: EGLDisplay, config: EGLConfig, native_pixmap: PixelMap,
  attrib_list?: number[]): EGLSurface | undefined

export function eglWaitSync(dpy: EGLDisplay, sync: EGLSync, flags: number): boolean

export function eglCreatePixmapSurface(dpy: EGLDisplay, config: EGLConfig, pixmap: PixelMap,
  attrib_list?: number[]): EGLSurface | undefined

export function eglCreateImageKHR(dpy: EGLDisplay, context: EGLContext, target: number, buffer: NativeBuffer,
  attrib_list?: number[]): EGLImageKHR | undefined

export function eglCreatePbufferFromClientBuffer(dpy: EGLDisplay, buftype: number, buffer: NativeBuffer,
  config: EGLConfig, attrib_list?: number[]): EGLSurface | undefined

export function eglCopyBuffers(dpy: EGLDisplay, surface: EGLSurface, target: PixelMap): boolean

export function eglDestroyImageKHR(dpy: EGLDisplay, image: EGLImageKHR): boolean

export function eglCreateSyncKHR(dpy: EGLDisplay, type: number, attrib_list?: number[]): EGLSyncKHR | undefined

export function eglDestroySyncKHR(dpy: EGLDisplay, sync: EGLSyncKHR): boolean

export function eglCreateContext(dpy: EGLDisplay, config: EGLConfig, share_context: EGLContext | undefined,
  attrib_list?: number[]): EGLContext | undefined