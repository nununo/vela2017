//
//  MouseDataInput.cpp
//  vela2017
//
//  Created by Nuno on 15/03/2017.
//
//

#include "MouseDataInput.h"
#include "Util.h"

//--------------------------------------------------------------
blowIntensityType MouseDataInput::getBlowIntensity() {
  return valueToBlowIntensity((float)(ofGetScreenHeight() - ofGetMouseY()) / (float)ofGetScreenHeight());
};

//--------------------------------------------------------------
blowIntensityType MouseDataInput::valueToBlowIntensity(float value) {
  if (value<0.25)
    return BLOW_INTENSITY_MIN;
  else if (value < 0.50)
    return BLOW_INTENSITY_LOW;
  else if (value < 0.75)
    return BLOW_INTENSITY_HIGH;
  else
    return BLOW_INTENSITY_BLOWOUT;
}

//--------------------------------------------------------------
string MouseDataInput::getTrace() {
  return "mouse: " + ofToString(ofGetMouseY()) + " intensity: " + Util::blowIntensityToString(getBlowIntensity()) + "\n";
}
