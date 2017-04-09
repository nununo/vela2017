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
  lastBlowIntensity = dataInput->getBlowIntensity();
}

//--------------------------------------------------------------
string InputIntensity::getTrace() {
  stringstream ss;
  
  ss << "InputLevel:\n"
  "  Current intensity: " + Util::blowIntensityToString(lastBlowIntensity) + "\n";
  
  ss << dataInput->getTrace();
  
  return ss.str();
  
};
