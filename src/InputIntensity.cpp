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
ofEvent<BlowIntensity> InputIntensity::blowIntensityChanged = ofEvent<BlowIntensity>();

//--------------------------------------------------------------
void InputIntensity::update() {
  input->update();
  setBlowIntensity(input->getBlowIntensity());
}

//--------------------------------------------------------------
void InputIntensity::setBlowIntensity(BlowIntensity newBlowIntensity) {
  BlowIntensity newConvertedBlowIntensity;
  BlowIntensity lastConvertedBlowIntensityCopy;
  
  if (newBlowIntensity > lastBlowIntensity)
    newConvertedBlowIntensity = input->getBlowIntensity();
  else
    newConvertedBlowIntensity = BlowIntensity::IDLE;
  
  lastBlowIntensity = newBlowIntensity;

  lastConvertedBlowIntensityCopy = lastConvertedBlowIntensity;
  lastConvertedBlowIntensity = newConvertedBlowIntensity;
  
  if (newConvertedBlowIntensity != lastConvertedBlowIntensityCopy) {
    broadcastBlowIntensityChangedEvent();
  }
}

//--------------------------------------------------------------
string InputIntensity::getTrace() {
  stringstream ss;
  
  ss << "InputLevel:\n"
  "  Last read: " + Util::blowIntensityToString(lastBlowIntensity) +
  " Last converted: " + Util::blowIntensityToString(lastConvertedBlowIntensity) << endl;
  
  ss << input->getTrace();
  
  return ss.str();
};

//--------------------------------------------------------------
void InputIntensity::broadcastBlowIntensityChangedEvent() {
  ofNotifyEvent(blowIntensityChanged, lastConvertedBlowIntensity);
}
