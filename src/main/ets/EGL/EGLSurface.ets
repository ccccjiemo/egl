import { eglGetCurrentSurface, eglSurfaceAttrib, eglBindTexImage, eglReleaseTexImage } from 'libegl.so'
import { EGLDisplay } from './EGLDisplay';
import { egl } from '../Index'
import { NativePointer } from '../Pointer';


export class EGLSurface implements NativePointer {
  private readonly _id: string;

  constructor(id: string) {
    this._id = id;
  }

  get id(): string {
    return this._id;
  }

  static getCurrentSurface(readdraw: egl.READDRAW): EGLSurface | undefined {
    let surface_id = eglGetCurrentSurface(readdraw);
    if (!surface_id) {
      return;
    }
    return new EGLSurface(surface_id);
  }

  /**
   * eglSurfaceAttrib
   */
  setAttribute(dpy: EGLDisplay, attribute: number, value: number): boolean {
    return eglSurfaceAttrib(dpy.id, this._id, attribute, value);
  }


  /**
   * eglBindTexImage
   */
  bindTexImage(dpy: EGLDisplay, buffer: number): boolean {
    return eglBindTexImage(dpy.id, this._id, buffer);
  }

  /**
   * eglReleaseTexImage
   */
  releaseTexImage(dpy: EGLDisplay, buffer: number): boolean {
    return eglReleaseTexImage(dpy.id, this._id, buffer);
  }
}

