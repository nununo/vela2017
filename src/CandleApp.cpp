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

}

//--------------------------------------------------------------
void CandleApp::draw(){

}

//--------------------------------------------------------------
void CandleApp::keyPressed(int key){

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

