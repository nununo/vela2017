#include "ofMain.h"
#include "CandleApp.h"
#include "MouseInput.h"
#include "CalibratedInput.h"

//========================================================================
int main( ){
	ofSetupOpenGL(1024,768,OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
  CalibratedInput *calibratedInput = new CalibratedInput( new MouseInput() );
  
	ofRunApp(new CandleApp( calibratedInput ));

}
