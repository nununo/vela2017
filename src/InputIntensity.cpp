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

using namespace std;


//--------------------------------------------------------------
void InputIntensity::calcIntensity() {
  lastBlowIntensity = dataInput->getBlowIntensity();
};

//--------------------------------------------------------------
void InputIntensity::update() {
  dataInput->update();
  calcIntensity();
}

//--------------------------------------------------------------
string InputIntensity::getTrace() {
  stringstream ss;
  
//  ss << "InputLevel:\n"
//         "  Thresholds:" + ofToString(threshold[THRESHOLD_1]) + " " + ofToString(threshold[THRESHOLD_2]) + " " + ofToString(threshold[THRESHOLD_3]) + "\n"
//         "  Current intensity: " + ofToString(getIntensity()) + "\n"
//         "  Current value: " << roundf(dataInput->getValue()*100)/100  << "\n";
  
  ss << dataInput->getTrace();
  
  return ss.str();
  
};
