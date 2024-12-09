## [0.2.0] - 2024-12-9

- 删除eglCreateImage(实在是不知道怎么创建EGLImage)
- 删除getWindowFromSurfaceId
- 配合上面改动，eglCreateWindowSurface的win参数改成surfaceId
- 新增eglCreateImageKHR,eglDestroyImageKHR
- 部分方法改成符合ts习惯(比如eglQueryContext,0.1版本需要传入一个Int32Array获取结果和返回true/false,
  现改成不需要传入buffer，方法调用成功返回查询值反则返回undefined)
- 新增类型EGLDisplay,EGLSurface, EGLContext,EGLConfig等
- 新增NativeBuffer，用于eglCreateImageKHR使用，target类型为EGL_NATIVE_BUFFER_OHOS,开发者可以自行实现napi来操作OHNativeBuffer
- 实现eglCreatePbufferFromClientBuffer、eglCopyBuffers、eglCreatePixmapSurface(
  模拟器查询surface类型掩码只支持window和pb,有真机的小伙伴可以帮我测试下)等方法

---

## [0.1.0] - 2024-11-22

### Added

- 新增getWindowFromSurfaceId方法。

---

## [0.0.3] - 2024-11-21

### Added

- 使用eglChooseConfig配置EGL_RENDERABLE_TYPE时，发现缺少了EGL_OPENGL_ES3_BIT_KHR！！ 添加EXT常量

---

## [0.0.2] - 2024-11-20

### Fixed

- 更改eglGetConfigAttrib、eglQueryContext、eglQuerySurface、eglGetSyncAttrib等方法可以返回复数返回值

### Info

- 合并egl10,egl

---

## [0.0.1] - 2024-11-19

### Info

- 进行基本测试

### Added

- egl模块包含egl基本方法
- egl10模块包含egl常量

---