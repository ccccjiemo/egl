import { NativePointer } from "./Pointer";

export class EGLImageKHR implements NativePointer {
  private readonly _id: string;

  constructor(id: string) {
    this._id = id;
  }

  get id(): string {
    return this._id;
  }
}