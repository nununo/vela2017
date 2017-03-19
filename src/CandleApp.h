#pragma once

#include "ofMain.h"
#include "XmlStore.h"
#include "Util.h"
#include "TraceLayer.h"
#include "InputIntensity.h"
#include "Levels.h"
#include "ClipLayers.h"

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
  void setTrace(bool value) {traceLayer.setVisible(value);}
  void setFullscreen(bool value);
  void toggleFullscreen() {setFullscreen(!bFullscreen);}
  
  InputIntensity *inputIntensity;
  ClipLayers *clipLayers;
  XmlStore xmlStore;
  TraceLayer traceLayer;
  int previousIntensity;
  bool bFullscreen;
};
