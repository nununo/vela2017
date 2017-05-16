#include "CandleApp.h"

//========================================================================
int main( ){
  ofGLESWindowSettings settings;
  settings.setGLESVersion(2);
  
  ofCreateWindow(settings);
  
	ofRunApp(new CandleApp());
}
