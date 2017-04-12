#include "CandleApp.h"
#include "MultiDataInput.h"
#include "KeyDataInput.h"
#include "MouseDataInput.h"
#include "ArduinoDataInput.h"
#include "AutoFlickerDataInput.h"
#include "SystemTrace.h"

static const string ARDUINO_MAC = "mac";
static const string ARDUINO_PI = "pi";

static const string ARDUINO_SENSOR_LEFT = "left";
static const string ARDUINO_SENSOR_RIGHT = "right";
static const string ARDUINO_SENSOR_TOP = "top";

//--------------------------------------------------------------
void CandleApp::setup(){

  previousIntensity = 0;
  
  xmlStore.setup(XML_FILENAME);
  
  Levels *levels =
    new Levels(new ClipOutputSettings(xmlStore.getVideoOffsetX(),
                                      xmlStore.getVideoOffsetY(),
                                      xmlStore.getVideoZoomX(),
                                      xmlStore.getVideoZoomY()),
               buildLevelSettingsList());

  clipLayers = new ClipLayers(levels, xmlStore.getVideoRotation());
  
  historyLayer.setVisible(xmlStore.getShowHistory());

  setupInputs();
  setupTrace();

  ofHideCursor();
  
  ofSetVerticalSync(true);
  ofSetFrameRate(xmlStore.getFramerate());
  
  setFullscreen(xmlStore.getFullscreen());
  
  ofBackground(0, 0, 0);
}

//--------------------------------------------------------------
void CandleApp::update(){
  inputIntensity->update();
  historyLayer.saveValue(inputIntensity->getBlowIntensity());
  clipLayers->update(inputIntensity->getBlowIntensity());
  traceLayer.update();
}

//--------------------------------------------------------------
void CandleApp::draw(){
  clipLayers->draw();
  traceLayer.draw();
  historyLayer.draw();
}

//--------------------------------------------------------------
void CandleApp::keyPressed  (int key){
  
  switch (key) {
    case 'f':
      toggleFullscreen();
      break;
    case 't':
      traceLayer.setVisible(!traceLayer.isVisible());
      break;
    case 'd':
      outputTraceInfo();
      break;
    case 'h':
      historyLayer.setVisible(!historyLayer.isVisible());
      break;
  }
}


//--------------------------------------------------------------
void CandleApp::setFullscreen(bool value) {
  bFullscreen = value;
  
  if (!bFullscreen){
    ofSetWindowShape(360,288); // (720,576);
    ofSetFullscreen(false);
    
    // figure out how to put the window in the center:
    int screenW = ofGetScreenWidth();
    int screenH = ofGetScreenHeight();
    ofSetWindowPosition(screenW/2-300/2, screenH/2-300/2);
    
  } else if (bFullscreen) {
    ofSetFullscreen(true);
  }
}

//--------------------------------------------------------------
void CandleApp::outputTraceInfo() {
  cout << traceLayer.getText();
}

//--------------------------------------------------------------
void CandleApp::setupInputs() {
  MultiDataInput *multiDataInput;
  ArduinoDataInput *arduinoDataInput;
  
  multiDataInput = new MultiDataInput();

  if (xmlStore.getKeyboardInputEnabled())
    multiDataInput->add( new KeyDataInput() );

  // Arduino 1 (Mac)
  if (xmlStore.getArduinoInputEnabled(ARDUINO_MAC)) {
    arduinoDataInput = new ArduinoDataInput(xmlStore.getArduinoInputDevice(ARDUINO_MAC),
                                            xmlStore.getArduinoSensorInputSettings(ARDUINO_MAC, ARDUINO_SENSOR_LEFT),
                                            xmlStore.getArduinoSensorInputSettings(ARDUINO_MAC, ARDUINO_SENSOR_RIGHT),
                                            xmlStore.getArduinoSensorInputSettings(ARDUINO_MAC, ARDUINO_SENSOR_TOP));
    if (arduinoDataInput->isEnabled())
      multiDataInput->add(arduinoDataInput);
  }

  // Arduino 2 (Raspberry PI)
  if (xmlStore.getArduinoInputEnabled(ARDUINO_PI)) {
    arduinoDataInput = new ArduinoDataInput(xmlStore.getArduinoInputDevice(ARDUINO_PI),
                                            xmlStore.getArduinoSensorInputSettings(ARDUINO_PI, ARDUINO_SENSOR_LEFT),
                                            xmlStore.getArduinoSensorInputSettings(ARDUINO_PI, ARDUINO_SENSOR_RIGHT),
                                            xmlStore.getArduinoSensorInputSettings(ARDUINO_PI, ARDUINO_SENSOR_TOP));
  if (arduinoDataInput->isEnabled())
    multiDataInput->add(arduinoDataInput);
  }

  if (xmlStore.getAutoFlickerInputEnabled())
    multiDataInput->add( new AutoFlickerDataInput(xmlStore.getAutoFlickerInputMinPeriod()) );
  
  //multiDataInput->add( new MouseDataInput() );

  inputIntensity =
    new InputIntensity(multiDataInput);

}

//--------------------------------------------------------------
void CandleApp::setupTrace() {
  traceLayer.setVisible(xmlStore.getShowTrace());
  traceLayer.add( new SystemTrace() );
  traceLayer.add(inputIntensity);
  traceLayer.add(clipLayers);
}

//--------------------------------------------------------------
vector<LevelSettings*> CandleApp::buildLevelSettingsList() {
  vector<LevelSettings*> list;
  
  for (int i=0; i<4; i++)
    list.push_back( new LevelSettings(xmlStore.getMovieFolder(i),
                                      xmlStore.getFadeInTime(i),
                                      xmlStore.getFadeOutTime(i),
                                      xmlStore.getLoop(i),
                                      xmlStore.getCanRestart(i)));
  return list;
}


