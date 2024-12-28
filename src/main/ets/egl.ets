import { EGLConfig } from './EGL/EGLConfig';
import { EGLDisplay, EGLVersion } from './EGL/EGLDisplay';
import { EGLSurface } from './EGL/EGLSurface';
import { image } from '@kit.ImageKit';
import { EGLContext } from './EGL/EGLContext';
import {
  EGLBufferType,
  EGLConfigAttribute,
  EGLError,
  EGLPlatform,
  EGL_NONE,
  QueryStringNames,
  READDRAW
} from './constants/constants';
import { eglCreatePbufferFromClientBuffer as eglCreatePbufferFromClientBuffer_ } from 'libegl.so';
import { NativeBuffer } from './NativeBuffer/NativeBuffer';
import { EGLSyncType } from './constants/EGLSyncType';
import { EGLSync } from './EGL/EGLSync';
import { EGLImageKHR } from './EGL/EGLImage';
import { NativePointer } from './EGL/Pointer';

export {
  eglBindAPI,
  eglQueryAPI,
  eglReleaseThread,
  eglWaitClient,
  eglWaitNative,
  eglWaitGL,
  eglGetProcAddress,
  eglGetError } from 'libegl.so'

/**
 * 获取EGLDisplay对象 通常输入undefined来获取DefaultDisplay
 */
export function eglGetDisplay(eglNativeDisplayType?: string): EGLDisplay | undefined {
  return EGLDisplay.getDisplay(eglNativeDisplayType);
}

export function eglInitialize(dpy: EGLDisplay): EGLVersion {
  return {
    major: dpy.major,
    minor: dpy.minjor
  }
}

export function eglChooseConfig(dpy: EGLDisplay, attrib_list: number[],
  config_size: number): EGLConfig[] {
  return dpy.chooseConfig(attrib_list, config_size);
}


export function eglCreatePixmapSurface(dpy: EGLDisplay, config: EGLConfig, pixmap: image.PixelMap,
  attrib_list?: number[]): EGLSurface | undefined {
  return dpy.createPixmapSurface(config, pixmap, attrib_list);
}

export function eglCreateContext(dpy: EGLDisplay, config: EGLConfig, share_context?: EGLContext,
  attrib_list?: number[]): EGLContext | undefined {
  return dpy.createContext(config, share_context, attrib_list);
}

export function eglCreatePbufferSurface(dpy: EGLDisplay, config: EGLConfig,
  attrib_list?: number[]): EGLSurface | undefined {
  return dpy.createPbufferSurface(config, attrib_list);
}

export function eglCreateWindowSurface(dpy: EGLDisplay, config: EGLConfig, surfaceId: string,
  attrib_list?: number[]): EGLSurface | undefined {
  return dpy.createSurfaceWindow(config, surfaceId, attrib_list);
}

export function eglDestroyContext(dpy: EGLDisplay, context: EGLContext): boolean {
  return dpy.destroyContext(context);
}

export function eglDestroySurface(dpy: EGLDisplay, surface: EGLSurface): boolean {
  return dpy.destroySurface(surface);
}

export function eglGetConfigAttrib(dpy: EGLDisplay, config: EGLConfig,
  attribute: EGLConfigAttribute): number | undefined {
  return config.getConfigAttrib(dpy, attribute);
}

export function eglGetConfigs(dpy: EGLDisplay, count: number): EGLConfig[] | undefined {
  return dpy.getConfigs(count);
}

export function eglGetCurrentDisplay(): EGLDisplay | undefined {
  return EGLDisplay.getCurrentDisplay();
}

export function eglMakeCurrent(dpy: EGLDisplay, draw: EGLSurface, read: EGLSurface,
  context: EGLContext): boolean {
  return dpy.makeCurrent(draw, read, context);
}

export function eglGetCurrentSurface(readdraw: READDRAW): EGLSurface | undefined {
  return EGLSurface.getCurrentSurface(readdraw);
}


/**
 * 查询成功返回number否则undefined
 * @param attribute EGL_CONFIG_ID / EGL_CONTEXT_CLIENT_TYPE / EGL_CONTEXT_CLIENT_VERSION / EGL_RENDER_BUFFER
 */
export function eglQueryContext(dpy: EGLDisplay, context: EGLContext, attribute: number): number | undefined {
  return context.query(dpy, attribute);
}

export function eglQueryString(dpy: EGLDisplay, name: QueryStringNames): string {
  return dpy.queryString(name);
}

export function eglQuerySurface(dpy: EGLDisplay, surface: EGLSurface, attribute: number): number | undefined {
  return surface.query(dpy, attribute);
}

export function eglSwapBuffers(dpy: EGLDisplay, surface: EGLSurface): boolean {
  return dpy.swapBuffers(surface);
}

export function eglTerminate(dpy: EGLDisplay): boolean {
  return dpy.terminate();
}


export function eglBindTexImage(dpy: EGLDisplay, surface: EGLSurface, buffer: number): boolean {
  return surface.bindTexImage(dpy, buffer);
}

export function eglReleaseTexImage(dpy: EGLDisplay, surface: EGLSurface, buffer: number): boolean {
  return surface.releaseTexImage(dpy, buffer);
}

export function eglCreatePbufferFromClientBuffer(dpy: EGLDisplay, buftype: EGLBufferType, buffer: NativeBuffer,
  config: EGLConfig, attrib_list?: number[]) {
  return eglCreatePbufferFromClientBuffer_(dpy.id, buftype, buffer.id, config.id, attrib_list ?? [EGL_NONE]);
}


/*

  export const eglCreateImage: (dpy: EGLDisplay, context: EGLContext, target: EGLImageType, buffer: EGLClientBuffer,
    attrib_list: EGLAttrib[]) => EGLImage = exports.eglCreateImage;

  export const eglDestroyImage: (dpy: EGLDisplay, image: EGLImage) => EGLBoolean = exports.eglDestroyImage;

  */

/**
 *https://registry.khronos.org/EGL/sdk/docs/man/html/eglSurfaceAttrib.xhtml
 * @param attribute EGL_MIPMAP_LEVEL / EGL_MULTISAMPLE_RESOLVE / EGL_SWAP_BEHAVIOR
 */
export function eglSurfaceAttrib(dpy: EGLDisplay, surface: EGLSurface, attribute: number,
  value: number): boolean {
  return surface.setAttribute(dpy, attribute, value);
}

export function eglSwapInterval(dpy: EGLDisplay, interval: number): boolean {
  return dpy.swapInterval(interval);
}


export function eglGetCurrentContext(): EGLContext | undefined {
  return EGLContext.getCurrentContext();
}

export function eglCreateSync(dpy: EGLDisplay, type: EGLSyncType, attrib_list?: number[]): EGLSync | undefined {
  return dpy.createSync(type, attrib_list);
}

export function eglDestroySync(dpy: EGLDisplay, sync: EGLSync): boolean {
  return dpy.destroySync(sync);
}

/**
 * https://registry.khronos.org/EGL/sdk/docs/man/html/eglClientWaitSync.xhtml
 */
export function eglClientWaitSync(dpy: EGLDisplay, sync: EGLSync, flags: number, timeout: number): number {
  return dpy.clientWaitSync(sync, flags, timeout);
}

export function eglGetSyncAttrib(dpy: EGLDisplay, sync: EGLSync, attribute: number): number | undefined {
  return dpy.getSyncAttrib(sync, attribute);
}


export function eglGetPlatformDisplay(platform: EGLPlatform, native_display?: string,
  attrib_list?: number[]): EGLDisplay | undefined {
  return EGLDisplay.getPlatformDisplay(platform, native_display, attrib_list);
}

/**
 * https://registry.khronos.org/EGL/sdk/docs/man/html/eglCreatePlatformWindowSurface.xhtml
 * @param attrib_list EGL_GL_COLORSPACE / EGL_RENDER_BUFFER / EGL_VG_ALPHA_FORMAT / EGL_VG_COLORSPACE
 */
export function eglCreatePlatformWindowSurface(dpy: EGLDisplay, config: EGLConfig, native_window?: string,
  attrib_list?: number[]): EGLSurface | undefined {
  return dpy.createPlatformWindowSurface(config, native_window, attrib_list);
}

/**
 * https://registry.khronos.org/EGL/sdk/docs/man/html/eglCreatePlatformPixmapSurface.xhtml
 * @param attrib_list EGL_GL_COLORSPACE / EGL_VG_ALPHA_FORMAT / EGL_VG_COLORSPACE
 */
export function eglCreatePlatformPixmapSurface(dpy: EGLDisplay, config: EGLConfig, native_pixmap?: string,
  attrib_list?: number[]): EGLSurface | undefined {
  return dpy.createPlatformPixmapSurface(config, native_pixmap, attrib_list);
}

export function eglWaitSync(dpy: EGLDisplay, sync: EGLSync, flags: number): boolean {
  return dpy.waitSync(sync, flags);
}

/**
 *传入PixelMap，eglGetError不报错，但赋值失败
 */
export function eglCopyBuffers(dpy: EGLDisplay, surface: EGLSurface, target: image.PixelMap): boolean {
  return dpy.copyBuffers(surface, target);
}

export function eglCreateImageKHR(dpy: EGLDisplay, context: EGLContext, target: number, buffer: NativePointer,
  attrib_list?: number[]): EGLImageKHR | undefined {
  return dpy.createImageKHR(target, context, buffer, attrib_list);
}

export function eglDestroyImageKHR(dpy: EGLDisplay, context: EGLContext, target: number, buffer: NativePointer,
  attrib_list?: number[]): EGLImageKHR | undefined {
  return dpy.createImageKHR(target, context, buffer, attrib_list);
}


