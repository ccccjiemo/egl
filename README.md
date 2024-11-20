## 使用说明

---

### 下载安装

```shell
ohpm install @jemoc/egl
```

### 基础用法

```typescript

import { egl, egl10 } from '@jemoc/egl';

let attrib_list: egl.EGLAttribList =
        [egl10.EGL_SURFACE_TYPE, egl10.EGL_WINDOW_BIT,
          egl10.EGL_RED_SIZE, 8,
          egl10.EGL_GREEN_SIZE, 8,
          egl10.EGL_BLUE_SIZE, 8,
          egl10.EGL_ALPHA_SIZE, 8,
          egl10.EGL_RENDERABLE_TYPE, egl10.EGL_OPENGL_ES2_BIT,
          egl10.EGL_NONE];

let display = egl.eglGetDisplay(egl.EGL_DEFAULT_DISPLAY);

let version: egl.EGLVersion = {};
egl.eglInitialize(display, version);

//获取egl config
let configs: egl.EGLConfig[] = new Array<egl.EGLConfig>(2);
egl.eglChooseConfig(display, attrib_list, 2, configs);

let eglAttrib: egl.EGLint[] = [egl10.EGL_CONTEXT_CLIENT_VERSION, 2, egl10.EGL_NONE];

//获取egl context
let context = egl.eglCreateContext(display, configs[0], egl.EGL_NO_CONTEXT, eglAttrib);

let success = egl.eglMakeCurrent(display, egl.EGL_NO_SURFACE, egl.EGL_NO_SURFACE, context);
```
