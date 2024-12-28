import * as lib from 'libegl.so'

export enum NativeBufferUsage {
  CPU_READ = 1,
  CPU_WRITE = 1 << 1,
  MEM_DMA = 1 << 3,
  HW_RENDER = 1 << 8,
  HW_TEXTURE = 1 << 9,
  CPU_READ_OFTEN = 1 << 16,
  ALIGNMENT_512 = 1 << 18
}

export enum NativeBufferFormat {
  CLUT8 = 0,
  CLUT1 = 1,
  CLUT4 = 2,
  RGB_565 = 3,
  RGBA_5658 = 4,
  RGBX_4444 = 5,
  RGBA_4444,
  RGB_444,
  RGBX_5551,
  RGBA_5551,
  RGB_555,
  RGBX_8888,
  RGBA_8888,
  RGB_888,
  BGR_565,
  BGRX_4444,
  BGRA_4444,
  BGRX_5551,
  BGRA_5551,
  BGRX_8888,
  BGRA_8888,
  YUV_422_I,
  YUV_422_SP,
  YCRCB_422_SP,
  YCBCR_420_SP,
  YCBCR_422_P,
  YCRCB_422_P,
  YCBCR_420_P,
  YCRCB_420_P,
  YUYV_422_PKG,
  UYVY_422_PKG,
  YVYU_422_PKG,
  VYUY_422_PKG,
  RGBA_1010102,
  YCBCR_P010,
  YCRCB_P010,
  RAW10,
  VENDER_MASK = 0x7FFF0000,
  BUTT = 0x7fffffff
}



// export function getWindowFromSurfaceId(surfaceId: string) {
//   return lib.getWindowFromSurfaceId(surfaceId);
// }

export function createOHNativeBuffer(config: lib.NativeBufferConfig): string | undefined {
  return lib.createNativeBuffer(config);
}

export function releaseOHNativeBuffer(buffer: string): number {
  return lib.releaseNativeBuffer(buffer);
}

//
// /**
//  * CLUT8 format
//  * @since 12
//  */
// NATIVEBUFFER_PIXEL_FMT_CLUT8 = 0,
// /**
//  * CLUT1 format
//  * @since 12
//  */
// NATIVEBUFFER_PIXEL_FMT_CLUT1,
// /**
//  * CLUT4 format
//  * @since 12
//  */
// NATIVEBUFFER_PIXEL_FMT_CLUT4,
// NATIVEBUFFER_PIXEL_FMT_RGB_565 = 3,               /// < RGB565 format */
// NATIVEBUFFER_PIXEL_FMT_RGBA_5658,                 /// < RGBA5658 format */
// NATIVEBUFFER_PIXEL_FMT_RGBX_4444,                 /// < RGBX4444 format */
// NATIVEBUFFER_PIXEL_FMT_RGBA_4444,                 /// < RGBA4444 format */
// NATIVEBUFFER_PIXEL_FMT_RGB_444,                   /// < RGB444 format */
// NATIVEBUFFER_PIXEL_FMT_RGBX_5551,                 /// < RGBX5551 format */
// NATIVEBUFFER_PIXEL_FMT_RGBA_5551,                 /// < RGBA5551 format */
// NATIVEBUFFER_PIXEL_FMT_RGB_555,                   /// < RGB555 format */
// NATIVEBUFFER_PIXEL_FMT_RGBX_8888,                 /// < RGBX8888 format */
// NATIVEBUFFER_PIXEL_FMT_RGBA_8888,                 /// < RGBA8888 format */
// NATIVEBUFFER_PIXEL_FMT_RGB_888,                   /// < RGB888 format */
// NATIVEBUFFER_PIXEL_FMT_BGR_565,                   /// < BGR565 format */
// NATIVEBUFFER_PIXEL_FMT_BGRX_4444,                 /// < BGRX4444 format */
// NATIVEBUFFER_PIXEL_FMT_BGRA_4444,                 /// < BGRA4444 format */
// NATIVEBUFFER_PIXEL_FMT_BGRX_5551,                 /// < BGRX5551 format */
// NATIVEBUFFER_PIXEL_FMT_BGRA_5551,                 /// < BGRA5551 format */
// NATIVEBUFFER_PIXEL_FMT_BGRX_8888,                 /// < BGRX8888 format */
// NATIVEBUFFER_PIXEL_FMT_BGRA_8888,                 /// < BGRA8888 format */
// /**
//  * YUV422 interleaved format
//  * @since 12
//  */
// NATIVEBUFFER_PIXEL_FMT_YUV_422_I,
// /**
//  * YCBCR422 semi-plannar format
//  * @since 12
//  */
// NATIVEBUFFER_PIXEL_FMT_YCBCR_422_SP,
// /**
//  * YCRCB422 semi-plannar format
//  * @since 12
//  */
// NATIVEBUFFER_PIXEL_FMT_YCRCB_422_SP,
// /**
//  * YCBCR420 semi-plannar format
//  * @since 12
//  */
// NATIVEBUFFER_PIXEL_FMT_YCBCR_420_SP,
// /**
//  * YCRCB420 semi-plannar format
//  * @since 12
//  */
// NATIVEBUFFER_PIXEL_FMT_YCRCB_420_SP,
// /**
//  * YCBCR422 plannar format
//  * @since 12
//  */
// NATIVEBUFFER_PIXEL_FMT_YCBCR_422_P,
// /**
//  * YCRCB422 plannar format
//  * @since 12
//  */
// NATIVEBUFFER_PIXEL_FMT_YCRCB_422_P,
// /**
//  * YCBCR420 plannar format
//  * @since 12
//  */
// NATIVEBUFFER_PIXEL_FMT_YCBCR_420_P,
// /**
//  * YCRCB420 plannar format
//  * @since 12
//  */
// NATIVEBUFFER_PIXEL_FMT_YCRCB_420_P,
// /**
//  * YUYV422 packed format
//  * @since 12
//  */
// NATIVEBUFFER_PIXEL_FMT_YUYV_422_PKG,
// /**
//  * UYVY422 packed format
//  * @since 12
//  */
// NATIVEBUFFER_PIXEL_FMT_UYVY_422_PKG,
// /**
//  * YVYU422 packed format
//  * @since 12
//  */
// NATIVEBUFFER_PIXEL_FMT_YVYU_422_PKG,
// /**
//  * VYUY422 packed format
//  * @since 12
//  */
// NATIVEBUFFER_PIXEL_FMT_VYUY_422_PKG,
// /**
//  * RGBA_1010102 packed format
//  * @since 12
//  */
// NATIVEBUFFER_PIXEL_FMT_RGBA_1010102,
// /**
//  * YCBCR420 semi-planar 10bit packed format
//  * @since 12
//  */
// NATIVEBUFFER_PIXEL_FMT_YCBCR_P010,
// /**
//  * YCRCB420 semi-planar 10bit packed format
//  * @since 12
//  */
// NATIVEBUFFER_PIXEL_FMT_YCRCB_P010,
// /**
//  * Raw 10bit packed format
//  * @since 12
//  */
// NATIVEBUFFER_PIXEL_FMT_RAW10,
// /**
//  * vender mask format
//  * @since 12
//  */
// NATIVEBUFFER_PIXEL_FMT_VENDER_MASK = 0X7FFF0000,
// NATIVEBUFFER_PIXEL_FMT_BUTT = 0X7FFFFFFF

/*NATIVEBUFFER_USAGE_CPU_READ = (1ULL << 0),        /// < CPU read buffer */
/*
NATIVEBUFFER_USAGE_CPU_WRITE = (1ULL << 1),       /// < CPU write memory */
/*
NATIVEBUFFER_USAGE_MEM_DMA = (1ULL << 3),         /// < Direct memory access (DMA) buffer */
/*
NATIVEBUFFER_USAGE_HW_RENDER = (1ULL << 8),       /// < For GPU write case */
/*
NATIVEBUFFER_USAGE_HW_TEXTURE = (1ULL << 9),      /// < For GPU read case */
/*
NATIVEBUFFER_USAGE_CPU_READ_OFTEN = (1ULL << 16), /// < Often be mapped for direct CPU reads */
/*
NATIVEBUFFER_USAGE_ALIGNMENT_512 = (1ULL << 18)*/