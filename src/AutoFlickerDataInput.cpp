//
//  AutoFlickerDataInput.cpp
//  vela2017
//
//  Created by Nuno on 17/03/2017.
//
//

#include "AutoFlickerDataInput.h"
#include "ofMain.h"
#include <sstream>

//--------------------------------------------------------------
AutoFlickerDataInput::AutoFlickerDataInput(int _minPeriod, float _flickerValue) {
  minPeriod = _minPeriod;
  flickerValue = _flickerValue;
  isFlickerTime = false;
  lastTime = ofGetElapsedTimeMillis();
}

//--------------------------------------------------------------
void AutoFlickerDataInput::update() {
  if (minPeriod > 0) {
    
    int timeNow = ofGetElapsedTimeMillis();
    
    isFlickerTime = timeNow - lastTime > minPeriod + ofRandomuf() * minPeriod;

    if (isFlickerTime) {

      lastTime = timeNow;

      cout << "Autoflicker: " << lastTime << " " << timeNow << "..." << timeNow - lastTime << "..." << minPeriod + ofRandomuf() * minPeriod << endl;
    }
  }
}

//--------------------------------------------------------------
float AutoFlickerDataInput::getValue() {
  float value;
  
  if (isFlickerTime) {
    isFlickerTime = false;
    value = flickerValue;
  } else
    value = 0.0f;
  
  return value;
}

//--------------------------------------------------------------
string AutoFlickerDataInput::getTrace() {
  stringstream ss;

  ss << "Auto Flicker input: min period: " << minPeriod << " value: " << flickerValue << " lastTime: " << lastTime << "\n";

  return ss.str();
}
