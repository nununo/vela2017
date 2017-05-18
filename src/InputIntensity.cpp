//
//  InputIntensity.cpp
//  vela2017
//
//  Created by Nuno on 15/03/2017.
//
//

#include "InputIntensity.h"
#include "Util.h"

// the static event, or any static variable, must be initialized outside of the class definition.
ofFastEvent<BlowIntensity> InputIntensity::blowIntensityChanged = ofFastEvent<BlowIntensity>();

//--------------------------------------------------------------
void InputIntensity::update() {
  input->update();
  setBlowIntensity(input->getBlowIntensity());
}

//--------------------------------------------------------------
void InputIntensity::setBlowIntensity(BlowIntensity newBlowIntensity) {
  
  if (newBlowIntensity != lastBlowIntensity)
    broadcastBlowIntensityChangedEvent(newBlowIntensity);

  lastBlowIntensity = newBlowIntensity;
}

//--------------------------------------------------------------
string InputIntensity::getTrace() {
  stringstream ss;
  
  ss << "Intensity: " + Util::blowIntensityToString(lastBlowIntensity) << endl;
  
  ss << input->getTrace();
  
  return ss.str();
};

//--------------------------------------------------------------
void InputIntensity::broadcastBlowIntensityChangedEvent(BlowIntensity blowIntensity) {
  ofNotifyEvent(blowIntensityChanged, blowIntensity);
}
