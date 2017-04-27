#include "CandleApp.h"
#include "SystemTrace.h"

//--------------------------------------------------------------
void CandleApp::setup(){
  
  Config config;
  
  config.setup(XML_FILENAME);
  
  generalSettings = config.createGeneralSettings();
  
  ClipOutputSettings *clipOutputSettings = config.createClipOutputSettings();

  clipLayers = new ClipLayers(new Levels(generalSettings, clipOutputSettings, config.createLevelSettingsList()),
                              clipOutputSettings->getRotation());
  
  valueHistoriesLayer = new ValueHistoriesLayer(config.getLayerSettings("history"), 100);
  valueHistoriesLayer->setVisible(generalSettings->getShowHistory());

  inputIntensity = new InputIntensity(config.createDataInputs());

  setupTraceLayer(&config);

  ofHideCursor();
  
  ofSetVerticalSync(true);
  ofSetFrameRate(generalSettings->getFramerate());
  
  setFullscreen(generalSettings->getIsFullscreen());
  
  ofBackground(0, 0, 0);
}

//--------------------------------------------------------------
void CandleApp::update(){
  inputIntensity->update();
  clipLayers->update(inputIntensity->getBlowIntensity());
  traceLayer->update();
}

//--------------------------------------------------------------
void CandleApp::draw(){
  clipLayers->draw();
  traceLayer->draw();
  valueHistoriesLayer->draw();
}

//--------------------------------------------------------------
void CandleApp::keyPressed  (int key){
  
  switch (key) {
    case 'f':
      toggleFullscreen();
      break;
    case 't':
      traceLayer->setVisible(!traceLayer->isVisible());
      break;
    case 'd':
      outputTraceInfo();
      break;
    case 'h':
      valueHistoriesLayer->setVisible(!valueHistoriesLayer->isVisible());
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
  ofLogNotice() << traceLayer->getText();
}

//--------------------------------------------------------------
void CandleApp::setupTraceLayer(Config *config) {
  
  traceLayer = new TraceLayer(config->getLayerSettings("info"));
  traceLayer->add( new SystemTrace() );
  traceLayer->add(inputIntensity);
  traceLayer->add(clipLayers);
}
