## 使用说明

---

### 下载安装

```shell
ohpm install @jemoc/egl
```

### 基础用法

```typescript

import { egl } from '@jemoc/egl';

let attrib_list: egl.EGLAttribList =
  [egl.EGL_SURFACE_TYPE, egl.EGL_WINDOW_BIT,
    egl.EGL_RED_SIZE, 8,
    egl.EGL_GREEN_SIZE, 8,
    egl.EGL_BLUE_SIZE, 8,
    egl.EGL_ALPHA_SIZE, 8,
    egl.EGL_RENDERABLE_TYPE, egl.EGL_OPENGL_ES2_BIT | egl.EGL_OPENGL_ES3_BIT_KHR,
    egl.EGL_NONE];

let display = egl.eglGetDisplay(egl.EGL_DEFAULT_DISPLAY);

let version: egl.EGLVersion = {};
egl.eglInitialize(display, version);

//获取egl config
let configs: egl.EGLConfig[] = new Array<egl.EGLConfig>(2);
egl.eglChooseConfig(display, attrib_list, 2, configs);

let eglAttrib: egl.EGLint[] = [egl.EGL_CONTEXT_CLIENT_VERSION, 2, egl.EGL_NONE];

//获取egl context
let context = egl.eglCreateContext(display, configs[0], egl.EGL_NO_CONTEXT, eglAttrib);

let success = egl.eglMakeCurrent(display, egl.EGL_NO_SURFACE, egl.EGL_NO_SURFACE, context);

//获取attribute信息
let queryAttribResult = new Int32Array(1);
egl.eglGetConfigAttrib(display, config, egl.EGL_ALPHA_SIZE, queryAttribResult);
```


---

### 可用API
| API                              | 
|----------------------------------| 
| eglChooseConfig                  |
| eglCopyBuffers                   |
| eglCreateContext                 |
| eglCreatePbufferSurface          |
| eglCreatePixmapSurface           |
| eglCreateWindowSurface           |
| eglDestroyContext                |
| eglDestroySurface                |
| eglGetConfigAttrib               |
| eglGetConfigs                    |
| eglGetCurrentDisplay             |
| eglGetCurrentSurface             |
| eglGetDisplay                    |
| eglGetError                      |
| eglGetProcAddress                |
| eglInitialize                    |
| eglMakeCurrent                   |
| eglQueryContext                  |
| eglQueryString                   |
| eglQuerySurface                  |
| eglSwapBuffers                   |
| eglTerminate                     |
| eglWaitGL                        |
| eglWaitNative                    |
| eglBindTexImage                  |
| eglReleaseTexImage               |
| eglSurfaceAttrib                 |
| eglSwapInterval                  |
| eglBindAPI                       |
| eglQueryAPI                      |
| eglCreatePbufferFromClientBuffer |
| eglReleaseThread                 |
| eglWaitClient                    |
| eglGetCurrentContext             |
| eglCreateSync                    |
| eglDestroySync                   |
| eglClientWaitSync                |
| eglGetSyncAttrib                 |
| eglCreateImage                   |
| eglDestroyImage                  |
| eglGetPlatformDisplay            |
| eglCreatePlatformWindowSurface   |
| eglCreatePlatformPixmapSurface   |
| eglWaitSync                      |
