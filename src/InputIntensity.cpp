//
//  InputIntensity.cpp
//  vela2017
//
//  Created by Nuno on 15/03/2017.
//
//

#include "InputIntensity.h"
#include "Util.h"

//--------------------------------------------------------------
void InputIntensity::update() {

  dataInput->update();
  
  if (dataInput->getBlowIntensity() > lastBlowIntensity)
    lastConvertedBlowIntensity = dataInput->getBlowIntensity();
  else
    lastConvertedBlowIntensity = BLOW_INTENSITY_IDLE;
  
  lastBlowIntensity = dataInput->getBlowIntensity();
}

//--------------------------------------------------------------
string InputIntensity::getTrace() {
  stringstream ss;
  
  ss << "InputLevel:\n"
  "  Last read: " + Util::blowIntensityToString(lastBlowIntensity) +
  " Last converted: " + Util::blowIntensityToString(lastConvertedBlowIntensity) + "\n";
  
  ss << dataInput->getTrace();
  
  return ss.str();
  
};
