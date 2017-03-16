#include "CandleApp.h"

//--------------------------------------------------------------
CandleApp::CandleApp( IDataInput *_dataInput) {
  inputLevel = new InputLevel( _dataInput );
};

//--------------------------------------------------------------
void CandleApp::setup(){
  // Initialize vars
  previousIntensity = 0;
  autoFlickerLastTime = ofGetElapsedTimeMillis();
  
  // Set input
  inputType = CandleApp::InputMouse;

  // Initialize XML data storage
  xmlStore.setup(XML_FILENAME);
  
  // Initialize trace
  setTrace(xmlStore.getTrace());
  
  // Initialize full screen
  setFullscreen(xmlStore.getFullscreen());

  // Configure auto flickr flag
  setAutoFlickerMinPeriod(xmlStore.getAutoFlickerMinPeriod());
  
  // Configure layers' static vars
  CandleLayer::configure(xmlStore.getOffsetX(), xmlStore.getOffsetY(), xmlStore.getZoomX(), xmlStore.getZoomY());

  // Initialize trace layer
  traceLayer.setup(inputLevel);
  
  // Initialize Arduino
  if (!arduino.setup(xmlStore.getArduinoDevice(), xmlStore.getThreshold(1), xmlStore.getThreshold(2), xmlStore.getThreshold(3), xmlStore.getMaxValue(), xmlStore.getAutocalirate()))
    cout << "Error connecting to Arduino." << endl;
  
  candleLevels = new CandleLevels(xmlStore.getDataFolder());

  // Create base layer for level 0
  baseLayer = candleLevels->getNewLayer(0, true);
  
  // Draw background
  ofBackground(0, 0, 0);
}

//--------------------------------------------------------------
void CandleApp::update(){
  
  // Update arduino value
  if (inputType == CandleApp::InputArduino)
    arduino.update();
  
  // Update base layer
  baseLayer->update();
  
  // Updates each layer
  vector<CandleLayer*>::iterator it;
  for (it = layers.begin(); it != layers.end(); it++) {
    (*it)->update();
    
    // Delete finished layers
    if (!(*it)->isPlaying()) {
      delete *it;
      layers.erase(it);
      // Ideally I wouldn't break here and go through all the layers looking for other deletable movies
      // but since deleting it destroys the iterator and the next iteration explodes... I'd have to come up
      // with a smarter code and I'm lazy.
      break;
    }
  }
  
  // Remove old first layer if top layer is already fully opaque.
  if (layers.size() > 1 && layers.back()->isOpaque()) {
    delete *layers.begin();
    layers.erase(layers.begin());
    cout << "Layer erased. " << layers.size() << " layers remain." << endl;
  }
  
  // Update current level and check for triggers
  checkTrigger();
  
  // Auto flicker
  if (autoFlickerMinPeriod > 0)
    autoFlicker();
}

//--------------------------------------------------------------
void CandleApp::draw(){
  
  // Rotate 180º
  if (xmlStore.getUpsideDown()) {
    glRotated(180, 0, 0, 1);
    glTranslated(-ofGetWidth(), -ofGetHeight(), 0);
  }
  
  // Draw base layer
  baseLayer->draw();
  
  // Draw all layers
  vector<CandleLayer*>::iterator it;
  for (it = layers.begin(); it != layers.end(); it++)
    (*it)->draw();
  
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
    case 'c':
      arduino.toggleAutocalibrate();
      break;
    case '+':
      inputLevel->offsetThresholds(1);
      break;
    case '-':
      inputLevel->offsetThresholds(-1);
      break;
    case 'i':
      if (inputType == CandleApp::InputArduino)
        inputType = CandleApp::InputMouse;
      else
        inputType = CandleApp::InputArduino;
      break;
    case 's':
      //xmlStore.save();
      break;
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
  CandleLayer *layer = candleLevels->getNewLayer(level, false);
  layers.push_back(layer);
}

//--------------------------------------------------------------
void CandleApp::autoFlicker() {
  int timeNow = ofGetElapsedTimeMillis();
  if (timeNow - autoFlickerLastTime > autoFlickerMinPeriod + ofRandomuf() * autoFlickerMinPeriod) {
    bool x = timeNow - autoFlickerLastTime > autoFlickerMinPeriod + ofRandomuf() * autoFlickerMinPeriod;
    cout << "Autoflicker: " << autoFlickerLastTime << " " << timeNow << "..." << timeNow - autoFlickerLastTime << "..." << autoFlickerMinPeriod + ofRandomuf() * autoFlickerMinPeriod << ".." << x << endl;
    addLayer(1);
    autoFlickerLastTime = timeNow;
  }
}

