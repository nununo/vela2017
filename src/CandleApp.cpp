#include "CandleApp.h"
#include "MultiDataInput.h"
#include "KeyDataInput.h"
#include "AutoFlickerDataInput.h"

//--------------------------------------------------------------
void CandleApp::setup(){

  previousIntensity = 0;
  
  xmlStore.setup(XML_FILENAME);
  
  setTrace(xmlStore.getTrace());
  
  setFullscreen(xmlStore.getFullscreen());

  setupInputs();

  traceLayer.setup(inputLevel);
  
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
  
  inputLevel->update();
  
  clipLayers->update(inputLevel->getLevel());
  
  checkTrigger();
}

//--------------------------------------------------------------
void CandleApp::draw(){
  
  clipLayers->draw();
  
  // Draw trace layer
  if (bTrace) {
    float v = 0.05 * (float)ofGetWidth();
    glTranslated(v, v, 0);
    traceLayer.draw();
    glTranslated(-v, -v, 0);
  }
}

//--------------------------------------------------------------
void CandleApp::keyPressed  (int key){
  
  switch (key) {
    case 'f':
      toggleFullscreen();
      break;
    case 't':
      toggleTrace();
      break;
//    case 'c':
//      arduino.toggleAutocalibrate();
      break;
    case '+':
      inputLevel->offsetThresholds(1);
      break;
    case '-':
      inputLevel->offsetThresholds(-1);
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
void CandleApp::checkTrigger() {

//  if (arduino.getLastIntensity() > previousIntensity) {
//    // No triggers allowed in level 3 (candle was blown out)
//    if (layers.size() == 0 || layers.back()->getIntensity() < 3) {
//      addLayer();
//      cout << "Current: " << arduino.getLastIntensity() << " previous: " << previousIntensity << endl;
//    }
//  }
//  previousIntensity = arduino.getLastIntensity();
}

//--------------------------------------------------------------
void CandleApp::setupInputs() {
//  MultiDataInput *multiDataInput;
//  
//  multiDataInput = new MultiDataInput();
//
//  multiDataInput->add( new KeyDataInput() );
//
//  multiDataInput->add( new AutoFlickerDataInput(xmlStore.getAutoFlickerMinPeriod(), 1.0f) );
//
//  multiDataInput->setup();
  
  inputLevel = new InputLevel( new KeyDataInput() );

}


