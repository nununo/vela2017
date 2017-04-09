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
AutoFlickerDataInput::AutoFlickerDataInput(int _minPeriod) {
  minPeriod = _minPeriod;
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
blowIntensityType AutoFlickerDataInput::getBlowIntensity() {
  if (isFlickerTime) {
    isFlickerTime = false;
    return BLOW_INTENSITY_LOW;
  } else
    return BLOW_INTENSITY_MIN;
}

//--------------------------------------------------------------
string AutoFlickerDataInput::getTrace() {
  stringstream ss;

  ss << "Auto Flicker input: min period: " << minPeriod << " lastTime: " << lastTime << "\n";

  return ss.str();
}
