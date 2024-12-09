import { eglGetCurrentContext, eglQueryContext } from 'libegl.so'
import { EGLDisplay } from './EGLDisplay';
import { NativePointer } from '../Pointer';

export class EGLContext implements NativePointer {
  private _id: string;

  constructor(id: string) {
    this._id = id;
  }

  get id(): string {
    return this._id;
  }

  static getCurrentContext(): EGLContext | undefined {
    let context_id = eglGetCurrentContext();
    if (!context_id) {
      return;
    }
    let context = new EGLContext(context_id);
    return context;
  }

  /**
   * eglQueryContext
   * 查询成功返回number否则undefined
   * @param attribute EGL_CONFIG_ID / EGL_CONTEXT_CLIENT_TYPE / EGL_CONTEXT_CLIENT_VERSION / EGL_RENDER_BUFFER
   */
  query(dpy: EGLDisplay, attribute: number): number | undefined {
    let temp = new Int32Array(1);
    if (!eglQueryContext(dpy.id, this._id, attribute, temp)) {
      return;
    }

    return temp[0];
  }
}