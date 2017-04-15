#pragma once

#include "ofMain.h"
#include "XmlStore.h"
#include "Util.h"
#include "TraceLayer.h"
#include "InputIntensity.h"
#include "Levels.h"
#include "ClipLayers.h"
#include "HistoryLayer.h"
#include "MultiDataInput.h"

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
  void setupArduinoInput(MultiDataInput *multiDataInput, string arduinoName);
  void setupKeyboardInput(MultiDataInput *multiDataInput);
  void setupMouseInput(MultiDataInput *multiDataInput);
  void setupAutoFlickerInput(MultiDataInput *multiDataInput);
  void setupTrace();
  void outputLayerStatus();
  void setFullscreen(bool value);
  void toggleFullscreen() {setFullscreen(!bFullscreen);}
  void outputTraceInfo();
  vector<LevelSettings*> buildLevelSettingsList();
  
  XmlStore xmlStore;
  InputIntensity *inputIntensity;
  ClipLayers *clipLayers;
  TraceLayer traceLayer;
  HistoryLayer historyLayer;
  int previousIntensity;
  bool bFullscreen;
};
