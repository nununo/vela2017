#include "CandleApp.h"

//========================================================================
int main( ){

#ifdef TARGET_RASPBERRY_PI

  // Increase ofVideoPlayer performance in Raspberry Pi
  // together with movie->setPixelFormat(OF_PIXELS_NATIVE);
  ofGLESWindowSettings settings;
  settings.setGLESVersion(2);
  ofCreateWindow(settings);

#else

  ofSetupOpenGL(360,288,OF_WINDOW); //(1024,768,OF_WINDOW);			// <-------- setup the GL context

#endif

	ofRunApp(new CandleApp());

}
