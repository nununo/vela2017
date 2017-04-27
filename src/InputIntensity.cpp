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

  input->update();
  
  if (input->getBlowIntensity() > lastBlowIntensity)
    lastConvertedBlowIntensity = input->getBlowIntensity();
  else
    lastConvertedBlowIntensity = BLOW_INTENSITY_IDLE;
  
  lastBlowIntensity = input->getBlowIntensity();
}

//--------------------------------------------------------------
string InputIntensity::getTrace() {
  stringstream ss;
  
  ss << "InputLevel:\n"
  "  Last read: " + Util::blowIntensityToString(lastBlowIntensity) +
  " Last converted: " + Util::blowIntensityToString(lastConvertedBlowIntensity) + "\n";
  
  ss << input->getTrace();
  
  return ss.str();
  
};
