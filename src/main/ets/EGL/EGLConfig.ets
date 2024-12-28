import { EGLDisplay } from "./EGLDisplay";
import { eglGetConfigAttrib } from 'libegl.so'
import { NativePointer } from "./Pointer";
import { EGLConfigAttribute } from "../constants/EGLConfigAttribute";

export class EGLConfig implements NativePointer {
  private readonly _id: string;

  constructor(id: string) {
    this._id = id;
  }

  get id(): string {
    return this._id;
  }

  getConfigAttrib(dpy: EGLDisplay, attribute: EGLConfigAttribute): number | undefined {
    return eglGetConfigAttrib(dpy.id, this._id, attribute);
  }
}

