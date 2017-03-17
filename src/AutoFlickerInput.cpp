//
//  AutoFlickerInput.cpp
//  vela2017
//
//  Created by Nuno on 17/03/2017.
//
//

#include "AutoFlickerInput.h"
#include "ofMain.h"

//--------------------------------------------------------------
AutoFlickerInput::AutoFlickerInput(int _minPeriod, float _flickerValue) {
  minPeriod = _minPeriod;
  flickerValue = _flickerValue;
}

//--------------------------------------------------------------
void AutoFlickerInput::setup() {
  lastTime = ofGetElapsedTimeMillis();
}

//--------------------------------------------------------------
void AutoFlickerInput::update() {
  int timeNow = ofGetElapsedTimeMillis();
  if (timeNow - lastTime > minPeriod + ofRandomuf() * minPeriod) {
    bool x = timeNow - lastTime > minPeriod + ofRandomuf() * minPeriod;
    cout << "Autoflicker: " << lastTime << " " << timeNow << "..." << timeNow - lastTime << "..." << minPeriod + ofRandomuf() * minPeriod << ".." << x << endl;
    
    value = flickerValue;
    lastTime = timeNow;
  }
}
