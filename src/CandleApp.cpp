#include "CandleApp.h"
#include "SystemTrace.h"
#include "Config.h"

static const string ARDUINO_MAC = "mac";
static const string ARDUINO_PI = "pi";

static const string ARDUINO_SENSOR_LEFT = "left";
static const string ARDUINO_SENSOR_RIGHT = "right";
static const string ARDUINO_SENSOR_TOP = "top";

//--------------------------------------------------------------
void CandleApp::setup(){
  
  Config config;
  
  config.setup(XML_FILENAME);
  
  generalSettings = config.createGeneralSettings();
  
  ClipOutputSettings *clipOutputSettings = config.createClipOutputSettings();

  clipLayers = new ClipLayers(new Levels(clipOutputSettings, config.createLevelSettingsList()),
                              clipOutputSettings->getRotation());
  
  historyLayer.setVisible(generalSettings->getShowHistory());

  inputIntensity = new InputIntensity(config.createDataInputs());

  setupTrace();

  ofHideCursor();
  
  ofSetVerticalSync(true);
  ofSetFrameRate(generalSettings->getFramerate());
  
  setFullscreen(generalSettings->getIsFullscreen());
  
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
  generalSettings->setIsFullscreen(value);
  
  if (!generalSettings->getIsFullscreen()){
    ofSetWindowShape(360,288); // (720,576);
    ofSetFullscreen(false);
    
    // figure out how to put the window in the center:
    int screenW = ofGetScreenWidth();
    int screenH = ofGetScreenHeight();
    ofSetWindowPosition(screenW/2-300/2, screenH/2-300/2);
    
  } else {
    ofSetFullscreen(true);
  }
}

//--------------------------------------------------------------
void CandleApp::outputTraceInfo() {
  cout << traceLayer.getText();
}

////--------------------------------------------------------------
//void CandleApp::setupArduinoInput(MultiInput *multiInput, string arduinoName) {
//  ArduinoInput *arduinoInput;
//  
//  if (!xmlStore.getArduinoInputEnabled(arduinoName))
//    return;
//  
//  arduinoInput = new ArduinoInput(xmlStore.getArduinoInputDevice(arduinoName));
//  
//  if (!arduinoInput->isEnabled())
//    return;
//  
//  arduinoInput->addValueInput(xmlStore.getValueInput(ARDUINO_SENSOR_LEFT));
//  arduinoInput->addValueInput(xmlStore.getValueInput(ARDUINO_SENSOR_RIGHT));
//  arduinoInput->addValueInput(xmlStore.getValueInput(ARDUINO_SENSOR_TOP));
//  
//  multiInput->add(arduinoInput);
//}


//--------------------------------------------------------------
void CandleApp::setupTrace() {
  traceLayer.setVisible(generalSettings->getShowTrace());
  traceLayer.add( new SystemTrace() );
  traceLayer.add(inputIntensity);
  traceLayer.add(clipLayers);
}



