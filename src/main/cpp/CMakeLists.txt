# the minimum version of CMake.
cmake_minimum_required(VERSION 3.5.0)
project(myNpmLib)

set(NATIVERENDER_ROOT_PATH ${CMAKE_CURRENT_SOURCE_DIR})
add_definitions(-DEGL_EGLEXT_PROTOTYPES)
add_definitions(-DOHOS_PLATFORM)


if(DEFINED PACKAGE_FIND_FILE)
    include(${PACKAGE_FIND_FILE})
endif()

include_directories(${NATIVERENDER_ROOT_PATH}
                    ${NATIVERENDER_ROOT_PATH}/include)

add_library(egl SHARED napi_init.cpp
standard/EGLBase.cpp
ptr/Ptr.cpp
standard/EGLConfig.cpp
standard/EGLDisplay.cpp
standard/EGLContext.cpp
standard/EGLSurface.cpp
standard/EGLImage.cpp
standard/EGLImageKHR.cpp
standard/EGLSync.cpp
standard/EGLSyncKHR.cpp
standard/NativeBuffer.cpp
egl/NapiEGL.cpp)

target_link_libraries(egl PUBLIC libace_napi.z.so libEGL.so libnative_window.so libnative_buffer.so libGLESv3.so libpixelmap_ndk.z.so libpixelmap.so)