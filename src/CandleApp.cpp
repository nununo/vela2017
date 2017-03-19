#include "CandleApp.h"
#include "MultiDataInput.h"
#include "KeyDataInput.h"
#include "MouseDataInput.h"
#include "AutoFlickerDataInput.h"

//--------------------------------------------------------------
void CandleApp::setup(){

  previousIntensity = 0;
  
  xmlStore.setup(XML_FILENAME);
  
  traceLayer.setVisible(xmlStore.getTrace());
  
  setFullscreen(xmlStore.getFullscreen());

  setupInputs();
  
  Levels *levels =
    new Levels(
               new ClipOutputSettings(xmlStore.getOffsetX(), xmlStore.getOffsetY(), xmlStore.getZoomX(), xmlStore.getZoomY()),
               xmlStore.getDataFolder());

  clipLayers = new ClipLayers(levels, xmlStore.getClipsRotation());
  
  // Draw background
  ofBackground(0, 0, 0);
}

//--------------------------------------------------------------
void CandleApp::update(){
  
  inputIntensity->update();
  
  historyLayer.saveValue(inputIntensity->getValue());
  
  clipLayers->update(inputIntensity->getIntensity());

  traceLayer.update(inputIntensity->getTrace() + clipLayers->getTrace());

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
    case 'h':
      historyLayer.setVisible(!historyLayer.isVisible());
      break;
//    case 'c':
//      arduino.toggleAutocalibrate();
      break;
    case '+':
      inputIntensity->offsetThresholds(1);
      break;
    case '-':
      inputIntensity->offsetThresholds(-1);
      break;
//    case 's':
      //xmlStore.save();
//      break;
  }
}


//--------------------------------------------------------------
void CandleApp::setFullscreen(bool value) {
  bFullscreen = value;
  
  if (!bFullscreen){
    ofSetWindowShape(720,576);
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
void CandleApp::setupInputs() {
  MultiDataInput *multiDataInput;
  
  multiDataInput = new MultiDataInput();

  multiDataInput->add( new KeyDataInput() );

  multiDataInput->add( new MouseDataInput() );
  
//  multiDataInput->add( new AutoFlickerDataInput(xmlStore.getAutoFlickerMinPeriod(), 1.0f) );
  
  inputIntensity = new InputIntensity( multiDataInput );

}


