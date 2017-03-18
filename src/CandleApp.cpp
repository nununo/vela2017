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
  
  // Configure layers' static vars
  Clip::configure(xmlStore.getOffsetX(), xmlStore.getOffsetY(), xmlStore.getZoomX(), xmlStore.getZoomY());

  // Initialize trace layer
  traceLayer.setup(inputLevel);
  
  levels = new Levels(xmlStore.getDataFolder());

  // Create base layer for level 0
  baseLayer = new Layer(0, levels->getRandomClip(0));
  
  // Draw background
  ofBackground(0, 0, 0);
}

//--------------------------------------------------------------
void CandleApp::update(){
  
  inputLevel->update();
  
  baseLayer->update();
  
  layers.update();
  
  checkTrigger();
}

//--------------------------------------------------------------
void CandleApp::draw(){
  
  // Rotate 180º
  if (xmlStore.getUpsideDown()) {
    glRotated(180, 0, 0, 1);
    glTranslated(-ofGetWidth(), -ofGetHeight(), 0);
  }
  
  baseLayer->draw();
  
  layers.draw();
  
  // Reset rotation
  if (xmlStore.getUpsideDown()) {
    glTranslated(ofGetWidth(), ofGetHeight(), 0);
    glRotated(-180, 0, 0, 1);
  }
  
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
  } else if (bFullscreen == 1) {
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
void CandleApp::addLayer(int level) {
  layers.push( new Layer(level, levels->getRandomClip(level)) );
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


