#include "CandleApp.h"

//========================================================================
int main( ){
  ofSetupOpenGL(360,288,OF_FULLSCREEN); //(1024,768,OF_WINDOW);			// <-------- setup the GL context
	ofRunApp(new CandleApp());
}
