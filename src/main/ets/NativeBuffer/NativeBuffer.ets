import { NativePointer } from "../EGL/Pointer";
import { createOHNativeBuffer, NativeBufferConfig, releaseOHNativeBuffer } from "./NativeHelperr";

export class NativeBuffer implements NativePointer {
  private readonly _id: string;

  private constructor(id: string) {
    this._id = id;
  }

  get id(): string {
    return this._id;
  }

  release(): boolean {
    return 0 == releaseOHNativeBuffer(this._id);
  }

  static createNativeBuffer(config: NativeBufferConfig): NativeBuffer | undefined {
    let buffer = createOHNativeBuffer(config);
    if (buffer) {
      return new NativeBuffer(buffer);
    }
    return;
  }
}