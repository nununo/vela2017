#include "CandleApp.h"

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
  traceLayer.setup(&arduino);
  
  // Initialize Arduino
  if (!arduino.setup(xmlStore.getArduinoDevice(), xmlStore.getThreshold(1), xmlStore.getThreshold(2), xmlStore.getThreshold(3), xmlStore.getMaxValue(), xmlStore.getAutocalirate()))
    cout << "Error connecting to Arduino." << endl;
  
  // Read files in this folder
  ofDirectory oDir;
  //oDir.setVerbose(false);
  int nFiles = oDir.listDir(xmlStore.getDataFolder());
  
  // Load movies into vector
  for(int i = 0; i < nFiles; i++){
    cout << "Loading level " << i << " from " << oDir.getPath(i) << endl;
    CandleLevel *level = new CandleLevel(i, oDir.getPath(i));
    levels.push_back(level);
  }
  cout << levels.size() << " levels loaded." << endl;
  
  // Create base layer for level 0
  baseLayer = levels[0]->getNewLayer(true);
  
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
      arduino.offsetThresholds(1);
      break;
    case '-':
      arduino.offsetThresholds(-1);
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
void CandleApp::keyReleased(int key){

}

//--------------------------------------------------------------
void CandleApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void CandleApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void CandleApp::mousePressed(int x, int y, int button){
//  if (inputType == CandleApp::InputMouse)
//    arduino.setValue(x);
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
  
  if (arduino.getLastIntensity() > previousIntensity) {
    // No triggers allowed in level 3 (candle was blown out)
    if (layers.size() == 0 || layers.back()->getIntensity() < 3) {
      addLayer();
      cout << "Current: " << arduino.getLastIntensity() << " previous: " << previousIntensity << endl;
    }
  }
  previousIntensity = arduino.getLastIntensity();
}

//--------------------------------------------------------------
void CandleApp::addLayer(int intensity) {
  CandleLayer *layer = levels[intensity]->getNewLayer(false);
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

