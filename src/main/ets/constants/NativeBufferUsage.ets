export enum NativeBufferUsage {
  CPU_READ = 1,
  CPU_WRITE = 1 << 1,
  MEM_DMA = 1 << 3,
  HW_RENDER = 1 << 8,
  HW_TEXTURE = 1 << 9,
  CPU_READ_OFTEN = 1 << 16,
  ALIGNMENT_512 = 1 << 18
}
