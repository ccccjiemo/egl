import { hilog } from '@kit.PerformanceAnalysisKit';
import { describe, beforeAll, beforeEach, afterEach, afterAll, it, expect } from '@ohos/hypium';
import * as EGL from 'libegl.so';

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
      // Defines a test case. This API supports three parameters: test case name, filter parameter, and test case function.
      hilog.info(0x0000, 'testTag', '%{public}s', 'it begin');
      let a = 'abc';
      let b = 'b';
      // Defines a variety of assertion methods, which are used to declare expected boolean conditions.
      expect(a).assertContain(b);
      expect(a).assertEqual(a);

      hilog.info(0x0000, 'testTag', '%{public}s', 'test eglGetDisplay start');
      let display1 = EGL.eglGetDisplay(EGL.EGL_DEFAULT_DISPLAY);
      let display2 = EGL.eglGetDisplay(EGL.EGL_DEFAULT_DISPLAY);
      let display3 = EGL.eglGetDisplay('11111111111');
      expect(display1).assertEqual(display2);
      expect(display3).assertUndefined();
      hilog.info(0x0000, 'testTag', '%{public}s', 'test eglGetDisplay end');

      hilog.info(0x0000, 'testTag', '%{public}s', 'test eglInitialize start');
      let versions1: EGL.EGLVersion = {};
      let versions2: EGL.EGLVersion = {};
      EGL.eglInitialize(display1, versions1);
      EGL.eglInitialize(display3, versions2);
      expect(versions1.major != 0 && versions1.minor!= 0).assertTrue();
      expect(versions2.major == 0 && versions2.minor == 0) .assertTrue();
      hilog.info(0x0000, 'testTag', '%{public}s', 'test eglInitialize end');

    })
  })
}