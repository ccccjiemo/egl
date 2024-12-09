import { image } from "@kit.ImageKit";

export interface NativeBufferConfig {
  width: number;
  height: number;
  format: number;
  usage: number;
  stride: number;
}


export interface EGLVersion {
  major?: number;
  minor?: number;
}

interface EGLAttributeKeyValue {
  attribute: number;
  value?: number;
}


// export const eglCopyBuffers: (dpy: string, surface: EGLSurface, target: EGLNativePixmapType): boolean;
// export function eglCreatePbufferFromClientBuffer(dpy: string, buftype: number, buffer: EGLClientBuffer,
//   config: EGLConfig, attrib_list?: EGLAttribList): EGLSurface;
/*export function eglCreateImage(dpy: string, context: EGLContext, target: number, buffer: EGLClientBuffer,
  attrib_list: EGLAttribList): EGLImage;*/

export const eglGetDisplay: (display_id?: string) => string;

export const eglInitialize: (dpy: string, versions: EGLVersion) => boolean;

export const eglChooseConfig: (dpy: string, attrib_list: number[], config_size: number) => string[];

export const eglCreateContext: (dpy: string, config?: string, share_context?: string,
  attrib_list?: number[]) => string;

export const eglGetError: () => number;

export const eglCreateWindowSurface: (dpy: string, config: string, surfaceId: string,
  attrib_list?: number[]) => string;

export const eglMakeCurrent: (dpy: string, draw?: string, read?: string,
  context?: string) => boolean;

export const eglCreatePbufferSurface: (dpy: string, config: string, attrib_list?: number[]) => string;

export const eglDestroyContext: (dpy: string, context: string) => boolean;

export const eglDestroySurface: (dpy: string, surface: string) => boolean;

export const eglGetConfigAttrib: (dpy: string, config: string, attribute: number) => number | undefined;

/**
 * 方法调用失败会返回一个空数组
 */
export const eglGetConfigs: (dpy: string, config_size: number) => string[];

export const eglGetCurrentDisplay: () => string | undefined;

export const eglGetCurrentSurface: (readdraw: number) => string | undefined;

export const eglGetProcAddress: (procName: string) => string;

export const eglQueryContext: (dpy: string, context: string, attribute: number) => number | undefined;

export const eglQueryString: (dpy: string, name: number) => string;

export const eglQuerySurface: (dpy: string, surface: string, attribute: number) => number | undefined;

export const eglSwapBuffers: (dpy: string, surface: string) => boolean;

export const eglTerminate: (dpy: string) => boolean;

export const eglWaitGL: () => boolean;

export const eglWaitNative: (engine: number) => boolean;

export const eglBindTexImage: (dpy: string, surface: string, buffer: number) => boolean;

export const eglReleaseTexImage: (dpy: string, surface: string, buffer: number) => boolean;

export const eglSurfaceAttrib: (dpy: string, surface: string, attribute: number, value: number) => boolean;

export const eglSwapInterval: (dpy: string, interval: number) => boolean;

export const eglBindAPI: (api: number) => boolean;

export const eglQueryAPI: () => number;

export const eglReleaseThread: () => boolean

export const eglWaitClient: () => boolean;

export const eglGetCurrentContext: () => string | undefined;

export const eglCreateSync: (dpy: string, type: number, attrib_list?: number[]) => string | undefined;

export const eglDestroySync: (dpy: string, sync: string) => boolean;

export const eglClientWaitSync: (dpy: string, sync: string, flags: number, timeout: number) => number;

export const eglGetSyncAttrib: (dpy: string, sync: string, attribute: number) => number | undefined;

export const eglDestroyImage: (dpy: string, image: string) => boolean;

export const eglGetPlatformDisplay: (platform: number, native_display?: string,
  attrib_list?: number[]) => string;

export const eglCreatePlatformWindowSurface: (dpy: string, config?: string, native_window?: string,
  attrib_list?: number[]) => string | undefined;

export const eglCreatePlatformPixmapSurface: (dpy: string, config?: string, native_pixmap?: string,
  attrib_list?: number[]) => string | undefined;

export const eglWaitSync: (dpy: string, sync: string, flags: number) => boolean;

export const eglCreatePixmapSurface: (dpy: string, config: string, pixmap: image.PixelMap,
  attrib_list?: number[]) => string | undefined;

export const eglCreateImageKHR: (dpy: string, context: string, target: number, buffer: string,
  attrib_list?: number[]) => string | undefined;

export const createNativeBuffer: (options: NativeBufferConfig) => string | undefined;

export const releaseNativeBuffer: (buffer: string) => number;

export const eglCreatePbufferFromClientBuffer: (dpy: string, buftype: number, buffer: string,
  config: string, attrib_list?: number[]) => string;

export const eglCopyBuffers: (dpy: string, surface: string, target: image.PixelMap) => boolean;

export const eglDestroyImageKHR: (dpy: string, image: string) => boolean;
