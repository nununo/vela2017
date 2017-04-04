#include "CandleApp.h"
#include "MultiDataInput.h"
#include "KeyDataInput.h"
#include "MouseDataInput.h"
#include "ArduinoDataInput.h"
#include "AutoFlickerDataInput.h"
#include "SystemTrace.h"

//--------------------------------------------------------------
void CandleApp::setup(){

  previousIntensity = 0;
  
  xmlStore.setup(XML_FILENAME);
  
  Levels *levels =
    new Levels(
               new ClipOutputSettings(xmlStore.getOffsetX(), xmlStore.getOffsetY(), xmlStore.getZoomX(), xmlStore.getZoomY()),
               xmlStore.getMovieFolder0(),
               xmlStore.getMovieFolder1(),
               xmlStore.getMovieFolder2(),
               xmlStore.getMovieFolder3());

  clipLayers = new ClipLayers(levels, xmlStore.getClipsRotation());
  
  historyLayer.setVisible(xmlStore.getHistory());

  setupInputs();
  setupTrace();

  ofSetFrameRate(50);
  setFullscreen(xmlStore.getFullscreen());
  ofBackground(0, 0, 0);
}

//--------------------------------------------------------------
void CandleApp::update(){
  inputIntensity->update();
  historyLayer.saveValue(inputIntensity->getValue());
  clipLayers->update(inputIntensity->getIntensity());
  traceLayer.update();
}

//--------------------------------------------------------------
void CandleApp::draw(){
  clipLayers->draw();
  traceLayer.draw();
  historyLayer.draw();

  if (ofGetFrameNum() % 50 == 0)
    outputTraceInfo();
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
//    case 'c':
//      arduino.toggleAutocalibrate();
      break;
    case '+':
      inputIntensity->offsetThresholds(0.01f);
      break;
    case '-':
      inputIntensity->offsetThresholds(-0.01f);
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
  
  multiDataInput = new MultiDataInput();

  multiDataInput->add( new KeyDataInput() );

//  multiDataInput->add( new ArduinoDataInput(xmlStore.getArduinoDevice(), xmlStore.getArduinoMinValue(), xmlStore.getArduinoMaxValue()) );
  
  //multiDataInput->add( new MouseDataInput() );
  
  //multiDataInput->add( new AutoFlickerDataInput(xmlStore.getAutoFlickerMinPeriod(), xmlStore.getAutoFlickerValue()) );
  
  inputIntensity = new InputIntensity( multiDataInput );

}

//--------------------------------------------------------------
void CandleApp::setupTrace() {
  traceLayer.setVisible(xmlStore.getTrace());
  traceLayer.add( new SystemTrace() );
  traceLayer.add(inputIntensity);
  traceLayer.add(clipLayers);
}


