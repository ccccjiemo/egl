## 使用说明

---

### 下载安装

```shell
ohpm install @jemoc/egl
```

### 基础用法

#### 0.2.0

```typescript
//surfaceId获取
//EGLDisplay使用完后必须调用terminate，
let display = egl.EGLDisplay.getDisplay();
//let display = egl.eglGetDisplay(egl.EGL_DEFAULT_DISPLAY);
//let display = egl.eglGetDisplay();

display?.initialize();
let major = display.major;
let minor = display.minor;
//let versions = egl.eglInitialize(display);
//let major = versions.major;
//let minor = version.minor;

let attrib_list = [
  egl.EGL_SURFACE_TYPE, egl.EGL_WINDOW_BIT,
  egl.EGL_RED_SIZE, 8,
  egl.EGL_GREEN_SIZE, 8,
  egl.EGL_BLUE_SIZE, 8,
  egl.EGL_ALPHA_SIZE, 8,
  egl.EGL_RENDERABLE_TYPE, egl.EGL_OPENGL_ES2_BIT | egl.EGL_OPENGL_ES3_BIT_KHR,
  egl.EGL_NONE];

//请求数量不输入默认是1
let configs = display?.chooseConfig([
  egl.EGL_SURFACE_TYPE, egl.EGL_WINDOW_BIT,
  egl.EGL_RED_SIZE, 8,
  egl.EGL_GREEN_SIZE, 8,
  egl.EGL_BLUE_SIZE, 8,
  egl.EGL_ALPHA_SIZE, 8,
  egl.EGL_RENDERABLE_TYPE, egl.EGL_OPENGL_ES2_BIT | egl.EGL_OPENGL_ES3_BIT_KHR,
  egl.EGL_NONE], 1);
//egl.eglChooseConfig(display, attrib_list,1);

let config = configs![0];
let read_size = config.getConfigAttrib(display, egl.EGL_RED_SIZE);
//let read_size = egl.eglGetConfigAttrib(display, config, egl.EGL_RED_SIZE);

let context =
  display?.createContext(config, egl.EGL_NO_CONTEXT, [egl.EGL_CONTEXT_CLIENT_VERSION, 2, egl.EGL_NONE]);
//let context = egl.eglCreateContext(display, config, egl.EGL_NO_CONTEXT, [egl.EGL_CONTEXT_CLIENT_VERSION, 2, egl.EGL_NONE]);

let version = context?.query(display, egl.EGL_CONTEXT_CLIENT_VERSION);
let surface = display?.createSurfaceWindow(config, surfaceId);
let pixelMalHeight = surface?.query(display, egl.EGL_HEIGHT);

//绘制工作
display.swapBuffers(surface);
//egl.eglSwapBuffers(display, surface);


//0.2.0新增 
let buffer = egl.NativeBuffer.createNativeBuffer({
  width: 1000,
  height: 1000,
  usage: egl.NativeBufferUsage.HW_TEXTURE,
  stride: 4,
  format: egl.NativeBufferFormat.RGBA_8888
})
let image: egl.EGLImageKHR | undefined =
  display?.createImageKHR(egl.EGL_GL_TEXTURE_2D_KHR, context, buffer, [egl.EGL_NONE]);
buffer?.release();
display?.destroyImageKHR(image)
//OHNativeBuffer的操作需要开发者自己需求开发napi方法 buffer.id可以获取对象指针字符串，native侧将字符串转成指针
```

---

### 可用API


| api                              | 
|----------------------------------| 
| eglGetDisplay                    |
| eglInitialize                    |
| eglChooseConfig                  |
| eglGetError                      |
| eglCreateWindowSurface           |
| eglMakeCurrent                   |
| eglCreatePbufferSurface          |
| eglDestroyContext                |
| eglDestroySurface                |
| eglGetConfigAttrib               |
| eglGetConfigs                    |
| eglGetCurrentDisplay             |
| eglGetCurrentSurface             |
| eglGetProcAddress                |
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
| eglReleaseThread                 |
| eglWaitClient                    |
| eglGetCurrentContext             |
| eglCreateSync                    |
| eglDestroySync                   |
| eglClientWaitSync                |
| eglGetSyncAttrib                 |
| eglDestroyImage                  |
| eglGetPlatformDisplay            |
| eglCreatePlatformWindowSurface   |
| eglCreatePlatformPixmapSurface   |
| eglWaitSync                      |
| eglCreatePixmapSurface           |
| eglCreateImageKHR                |
| eglCreatePbufferFromClientBuffer |
| eglCopyBuffers                   |
| eglDestroyImageKHR               |
| eglCreateSyncKHR                 |
| eglDestroySyncKHR                |
| eglCreateImage                   |

