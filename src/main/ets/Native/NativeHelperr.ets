import * as module from 'libegl.so'

export namespace NativeHelper {
  export function getWindowFromSurfaceId(surfaceId: string) {
    return module.getWindowFromSurfaceId(surfaceId);
  }
}