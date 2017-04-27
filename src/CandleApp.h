#pragma once

#include "ofMain.h"
#include "Util.h"
#include "TraceLayer.h"
#include "InputIntensity.h"
#include "Levels.h"
#include "ClipLayers.h"
#include "ValueHistoriesLayer.h"
#include "GeneralSettings.h"
#include "Config.h"

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
  void setupTraceLayer(Config *config);
  void outputLayerStatus();
  void setFullscreen(bool value);
  void toggleFullscreen() {setFullscreen(!generalSettings->getIsFullscreen());}
  void outputTraceInfo();
  void setupValueHistory();
  
  InputIntensity *inputIntensity;
  TraceLayer *traceLayer;
  ValueHistoriesLayer *valueHistoriesLayer;
  ClipLayers *clipLayers;
  GeneralSettings *generalSettings;
};
