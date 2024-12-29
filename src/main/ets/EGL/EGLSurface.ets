// import { eglGetCurrentSurface, eglSurfaceAttrib, eglBindTexImage, eglReleaseTexImage, eglQuerySurface } from 'libegl.so'
// import { EGLDisplay } from './EGLDisplay';
// import { NativePointer } from './Pointer';
// import { READDRAW } from '../constants/READDRAW';
//
//
// export class EGLSurface implements NativePointer {
//   private readonly _id: string;
//
//   constructor(id: string) {
//     this._id = id;
//   }
//
//   get id(): string {
//     return this._id;
//   }
//
//   static getCurrentSurface(readdraw: READDRAW): EGLSurface | undefined {
//     let surface_id = eglGetCurrentSurface(readdraw);
//     if (!surface_id) {
//       return;
//     }
//     return new EGLSurface(surface_id);
//   }
//
//   /**
//    * eglSurfaceAttrib
//    */
//   setAttribute(dpy: EGLDisplay, attribute: number, value: number): boolean {
//     return eglSurfaceAttrib(dpy.id, this._id, attribute, value);
//   }
//
//   query(dpy: EGLDisplay, attribute: number): number | undefined {
//     return eglQuerySurface(dpy.id, this._id, attribute);
//   }
//
//
//   /**
//    * eglBindTexImage
//    */
//   bindTexImage(dpy: EGLDisplay, buffer: number): boolean {
//     return eglBindTexImage(dpy.id, this._id, buffer);
//   }
//
//   /**
//    * eglReleaseTexImage
//    */
//   releaseTexImage(dpy: EGLDisplay, buffer: number): boolean {
//     return eglReleaseTexImage(dpy.id, this._id, buffer);
//   }
// }
//
