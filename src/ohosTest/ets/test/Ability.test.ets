import { describe, beforeAll, beforeEach, afterEach, afterAll, it, expect } from '@ohos/hypium';
import { eglGetDisplay } from 'libegl.so';
import {
  EGL_ALPHA_SIZE,
  EGL_BLUE_SIZE,
  EGL_GREEN_SIZE, EGL_NONE,
  EGL_OPENGL_ES2_BIT,
  EGL_OPENGL_ES3_BIT_KHR,
  EGL_RED_SIZE,
  EGL_RENDERABLE_TYPE,
  EGL_SURFACE_TYPE, EGL_WINDOW_BIT } from '../../../main/ets/egl';


export default function abilityTest() {
  describe('ActsAbilityTest', () => {
    // Defines a test suite. Two parameters are supported: test suite name and test suite function.
    beforeAll(() => {
      // Presets an action, which is performed only once before all test cases of the test suite start.
      // This API supports only one parameter: preset action function.
    })
    beforeEach(() => {
      // Presets an action, which is performed before each unit test case starts.
      // The number of execution times is the same as the number of test cases defined by **it**.
      // This API supports only one parameter: preset action function.
    })
    afterEach(() => {
      // Presets a clear action, which is performed after each unit test case ends.
      // The number of execution times is the same as the number of test cases defined by **it**.
      // This API supports only one parameter: clear action function.
    })
    afterAll(() => {
      // Presets a clear action, which is performed after all test cases of the test suite end.
      // This API supports only one parameter: clear action function.
    })
    it('assertContain', 0, () => {
      let display = eglGetDisplay();
      display?.initialize();
      display?.chooseConfig([
        EGL_SURFACE_TYPE, EGL_WINDOW_BIT,
        EGL_RED_SIZE, 8,
        EGL_GREEN_SIZE, 8,
        EGL_BLUE_SIZE, 8,
        EGL_ALPHA_SIZE, 8,
        EGL_RENDERABLE_TYPE, EGL_OPENGL_ES2_BIT | EGL_OPENGL_ES3_BIT_KHR,
        EGL_NONE])
      let config = display?.getConfigs(1)[0];
      let context = display?.createContext(config!, undefined);

      console.log('1');
    })
  })
}