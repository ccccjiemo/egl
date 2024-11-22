## [0.0.1] - 2024-11-19

### Info
- 进行基本测试

### Added
- egl模块包含egl基本方法
- egl10模块包含egl常量

---

## [0.0.2] - 2024-11-20

### Fixed
- 更改eglGetConfigAttrib、eglQueryContext、eglQuerySurface、eglGetSyncAttrib等方法可以返回复数返回值

### Info

- 合并egl10,egl

---

## [0.0.3] - 2024-11-21

### Added

- 使用eglChooseConfig配置EGL_RENDERABLE_TYPE时，发现缺少了EGL_OPENGL_ES3_BIT_KHR！！ 添加EXT常量

---
## [0.1.0] - 2024-11-22

### Added

- 新增getWindowFromSurfaceId方法。