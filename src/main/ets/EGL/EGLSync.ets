import { NativePointer } from "../Pointer";

export class EGLSync implements NativePointer {
  private _id: string

  constructor(id: string) {
    this._id = id;
  }

  get id(): string {
    return this._id;
  }
}