#pragma once

#include "ofMain.h"
#include "XmlStore.h"
#include "Util.h"
#include "TraceLayer.h"
#include "Layer.h"
#include "InputLevel.h"
#include "Levels.h"
#include "Layers.h"

#define XML_FILENAME "vela.xml"

class CandleApp : public ofBaseApp {

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key) {};
    void mouseMoved(int x, int y ) {};
    void mouseDragged(int x, int y, int button) {};
		void mousePressed(int x, int y, int button) {};
		
private:
  void setupInputs();
  void outputLayerStatus();
  void checkTrigger();
  void setTrace(bool value) {bTrace = value;}
  void setFullscreen(bool value);
  void toggleTrace() {setTrace(!bTrace);}
  void toggleFullscreen() {setFullscreen(!bFullscreen);}
  
  InputLevel *inputLevel;
  Layers *layers;
  XmlStore xmlStore;
  TraceLayer traceLayer;
  int previousIntensity;
  bool bFullscreen;
  bool bTrace;
};
