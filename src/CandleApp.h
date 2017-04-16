#pragma once

#include "ofMain.h"
#include "Util.h"
#include "TraceLayer.h"
#include "InputIntensity.h"
#include "Levels.h"
#include "ClipLayers.h"
#include "HistoryLayer.h"
#include "GeneralSettings.h"

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
  void setupTrace();
  void outputLayerStatus();
  void setFullscreen(bool value);
  void toggleFullscreen() {setFullscreen(!bFullscreen);}
  void outputTraceInfo();
  
  InputIntensity *inputIntensity;
  ClipLayers *clipLayers;
  TraceLayer traceLayer;
  HistoryLayer historyLayer;
  GeneralSettings *generalSettings;
  bool bFullscreen;
};
