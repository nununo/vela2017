//
//  InputIntensity.cpp
//  vela2017
//
//  Created by Nuno on 15/03/2017.
//
//

#include "InputIntensity.h"
#include <iostream>
#include "ofMain.h"
#include <sstream>
#include "Util.h"

using namespace std;

//--------------------------------------------------------------
void InputIntensity::update() {

  dataInput->update();
  
  if (dataInput->getBlowIntensity() > lastBlowIntensity)
    lastConvertedBlowIntensity = dataInput->getBlowIntensity();
  else
    lastConvertedBlowIntensity = BLOW_INTENSITY_MIN;
  
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
