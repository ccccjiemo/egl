import { EGLDisplay } from "./EGLDisplay";
import { eglGetConfigAttrib } from 'libegl.so'
import { egl } from '../Index'
import { NativePointer } from "./Pointer";

export class EGLConfig implements NativePointer {
  private readonly _id: string;

  constructor(id: string) {
    this._id = id;
  }

  get id(): string {
    return this._id;
  }

  getConfigAttrib(dpy: EGLDisplay, attribute: egl.EGLConfigAttribute): number | undefined {
    return eglGetConfigAttrib(dpy.id, this._id, attribute);
  }
}

