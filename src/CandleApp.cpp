#include "CandleApp.h"
#include "SystemInfo.h"

//--------------------------------------------------------------
void CandleApp::setup(){

  Config config;
  
  config.setup(XML_FILENAME);
  
  generalSettings = config.getGeneralSettings();

  setFullscreen(generalSettings.getIsFullscreen());

  ClipOutputSettings clipOutputSettings = config.getClipOutputSettings();
  
  clipLayers = new ClipLayers(config.getLayerSettings("clip"),
                              new Levels(generalSettings,
                                         clipOutputSettings,
                                         config.createLevelSettingsList()));
  
  valueHistoriesLayer = new ValueHistoriesLayer(config.getLayerSettings("history"), config.getHistorySettings());
  
  inputIntensity = new InputIntensity(config.createDataInputs());

  setupInfoLayer(&config);

  ofHideCursor();
  
  ofSetVerticalSync(true);
  ofSetFrameRate(generalSettings.getFramerate());
  
  ofBackground(0, 0, 0);
}

//--------------------------------------------------------------
void CandleApp::update(){
  inputIntensity->update();
  clipLayers->update();
  infoLayer->update();
}

//--------------------------------------------------------------
void CandleApp::draw(){
  clipLayers->draw();
  infoLayer->draw();
  valueHistoriesLayer->draw();
}

//--------------------------------------------------------------
void CandleApp::keyPressed  (int key){
  
  switch (key) {
    case 'f':
      toggleFullscreen();
      break;
    case 't':
      infoLayer->setVisible(!infoLayer->isVisible());
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
  generalSettings.setIsFullscreen(value);
  
  if (!generalSettings.getIsFullscreen()){
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
  ofLogNotice() << infoLayer->getText();
}

//--------------------------------------------------------------
void CandleApp::setupInfoLayer(Config *config) {
  
  infoLayer = new InfoLayer(config->getLayerSettings("info"));
  infoLayer->add( new SystemInfo() );
  infoLayer->add(inputIntensity);
  infoLayer->add(clipLayers);
}
