//
//  AutoFlickerInput.cpp
//  vela2017
//
//  Created by Nuno on 17/03/2017.
//
//

#include "AutoFlickerInput.h"
#include "InputIntensity.h"

//--------------------------------------------------------------
AutoFlickerInput::AutoFlickerInput(int _minPeriod) : DataInput("autoFlicker") {
  minPeriod = _minPeriod;
  isFlickerTime = false;
  lastTime = ofGetElapsedTimeMillis();
  
  ofAddListener(InputIntensity::blowIntensityChanged , this, &AutoFlickerInput::onBlowIntensityChanged);
}

//--------------------------------------------------------------
AutoFlickerInput::~AutoFlickerInput()  {
  ofRemoveListener(InputIntensity::blowIntensityChanged, this, &AutoFlickerInput::onBlowIntensityChanged);
}

//--------------------------------------------------------------
void AutoFlickerInput::update() {
  if (minPeriod > 0) {
    
    int timeNow = ofGetElapsedTimeMillis();
    
    isFlickerTime = (timeNow - lastTime > minPeriod + ofRandomuf() * minPeriod);

    if (isFlickerTime) {

      lastTime = timeNow;

      ofLogNotice() << "Autoflicker: " << lastTime << " " << timeNow << "..."
                    << timeNow - lastTime << "..." << minPeriod + ofRandomuf() * minPeriod;
    }
  }
}

//--------------------------------------------------------------
BlowIntensity AutoFlickerInput::getBlowIntensity() {
  if (isFlickerTime) {
    return BlowIntensity::LOW;
  } else
    return BlowIntensity::IDLE;
}

//--------------------------------------------------------------
void AutoFlickerInput::onBlowIntensityChanged(BlowIntensity &e) {
  // Since there was activity from the inputs, we restart the timer
  int timeNow = ofGetElapsedTimeMillis();
  if (timeNow - lastTime > 100) // To avoid resetting itself since the autoflicker intensity will also trigger this event
    lastTime = timeNow;
  
}

//--------------------------------------------------------------
string AutoFlickerInput::getTrace() {
  stringstream ss;

  ss << getName() << ": min period: " << minPeriod << " lastTime: " << lastTime;

  return ss.str();
}
