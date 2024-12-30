//
// Created on 2024/12/29.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef GLTEST_EGLBASE_H
#define GLTEST_EGLBASE_H
#include "napi/native_api.h"
namespace EGLBase {
napi_value JSEGLGetDisplay(napi_env env, napi_value display_id);
napi_value JSEGLInitialize(napi_env env, napi_value dpy);
napi_value JSEGLChooseConfig(napi_env env, napi_value dpy, napi_value attrib_list, napi_value config_size);
napi_value JSEGLGetError(napi_env env);
napi_value JSEGLCreateWindowSurface(napi_env env, napi_value dpy, napi_value config, napi_value surfaceId,
                                    napi_value attrib_list);
napi_value JSEGLMakeCurrent(napi_env env, napi_value dpy, napi_value surface_draw, napi_value surface_read,
                            napi_value ctx);
napi_value JSEGLCreatePbufferSurface(napi_env env, napi_value dpy, napi_value config, napi_value attrib_list);
napi_value JSEGLDestroyContext(napi_env env, napi_value dpy, napi_value context);
napi_value JSEGLDestroySurface(napi_env env, napi_value dpy, napi_value surface);
napi_value JSEGLGetConfigAttrib(napi_env env, napi_value dpy, napi_value config, napi_value attribute);
napi_value JSEGLGetConfigs(napi_env env, napi_value dpy, napi_value config_size);
napi_value JSEGLGetCurrentDisplay(napi_env env);
napi_value JSEGLGetCurrentSurface(napi_env env, napi_value readdraw);
napi_value JSEGLGetProcAddress(napi_env env, napi_value procName);
napi_value JSEGLQueryContext(napi_env env, napi_value dpy, napi_value context, napi_value attribute);
napi_value JSEGLQueryString(napi_env env, napi_value dpy, napi_value name);
napi_value JSEGLQuerySurface(napi_env env, napi_value dpy, napi_value surface, napi_value attribute);
napi_value JSEGLSwapBuffers(napi_env env, napi_value dpy, napi_value surface);
napi_value JSEGLTerminate(napi_env env, napi_value dpy);
napi_value JSEGLWaitGL(napi_env env);
napi_value JSEGLWaitNative(napi_env env, napi_value engine);
napi_value JSEGLBindTexImage(napi_env env, napi_value dpy, napi_value surface, napi_value buffer);
napi_value JSEGLReleaseTexImage(napi_env env, napi_value dpy, napi_value surface, napi_value buffer);
napi_value JSEGLSurfaceAttrib(napi_env env, napi_value dpy, napi_value surface, napi_value attribute, napi_value value);
napi_value JSEGLSwapInterval(napi_env env, napi_value dpy, napi_value interval);
napi_value JSEGLBindAPI(napi_env env, napi_value api);
napi_value JSEGLQueryAPI(napi_env env);
napi_value JSEGLReleaseThread(napi_env env);
napi_value JSEGLWaitClient(napi_env env);
napi_value JSEGLGetCurrentContext(napi_env env);
napi_value JSEGLCreateSync(napi_env env, napi_value dpy, napi_value type, napi_value attrib_list);
napi_value JSEGLDestroySync(napi_env env, napi_value dpy, napi_value sync);
napi_value JSEGLClientWaitSync(napi_env env, napi_value dpy, napi_value sync, napi_value flags, napi_value timeout);
napi_value JSEGLGetSyncAttrib(napi_env env, napi_value dpy, napi_value sync, napi_value attribute);
napi_value JSEGLDestroyImage(napi_env env, napi_value dpy, napi_value image);
napi_value JSEGLGetPlatformDisplay(napi_env env, napi_value platform, napi_value native_display,
                                   napi_value attrib_list);
napi_value JSEGLCreatePlatformWindowSurface(napi_env env, napi_value dpy, napi_value config, napi_value native_window,
                                            napi_value attrib_list);
napi_value JSEGLCreatePlatformPixmapSurface(napi_env env, napi_value dpy, napi_value config, napi_value native_pixmap,
                                            napi_value attrib_list);
napi_value JSEGLWaitSync(napi_env env, napi_value dpy, napi_value sync, napi_value flags);
napi_value JSEGLCreatePixmapSurface(napi_env env, napi_value dpy, napi_value config, napi_value pixmap,
                                    napi_value attrib_list);
napi_value JSEGLCreateImage(napi_env env, napi_value dpy, napi_value context, napi_value target, napi_value buffer,
                            napi_value attrib_list);
napi_value JSEGLCreateImageKHR(napi_env env, napi_value dpy, napi_value context, napi_value target, napi_value buffer,
                               napi_value attrib_list);
napi_value JSEGLCreatePbufferFromClientBuffer(napi_env env, napi_value dpy, napi_value buftype, napi_value buffer,
                                              napi_value config, napi_value attrib_list);
napi_value JSEGLCopyBuffers(napi_env env, napi_value dpy, napi_value surface, napi_value target);
napi_value JSEGLDestroyImageKHR(napi_env env, napi_value dpy, napi_value image);
napi_value JSEGLCreateSyncKHR(napi_env env, napi_value dpy, napi_value type, napi_value attrib_list);
napi_value JSEGLDestroySyncKHR(napi_env env, napi_value dpy, napi_value sync);
napi_value JSEGLCreateContext(napi_env env, napi_value dpy, napi_value config, napi_value share_context, napi_value attrib_list);
} // namespace EGLBase

#endif // GLTEST_EGLBASE_H
