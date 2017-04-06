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
InputIntensity::InputIntensity( IDataInput *_dataInput, float threshold1, float threshold2, float threshold3) {
  dataInput = _dataInput;
  
  threshold[THRESHOLD_1] = threshold1;
  threshold[THRESHOLD_2] = threshold2;
  threshold[THRESHOLD_3] = threshold3;
}

//--------------------------------------------------------------
void InputIntensity::calcIntensity() {

  lastValue = dataInput->getValue();
  
  if (lastValue > threshold[THRESHOLD_3])
    lastIntensity = LEVEL_3;
  else if (lastValue > threshold[THRESHOLD_2])
    lastIntensity = LEVEL_2;
  else if (lastValue > threshold[THRESHOLD_1])
    lastIntensity = LEVEL_1;
  else
    lastIntensity = LEVEL_0;
  
};

//--------------------------------------------------------------
void InputIntensity::update() {
  dataInput->update();
  calcIntensity();
}

//--------------------------------------------------------------
void InputIntensity::offsetThresholds(float diff) {
  cout << "Offsettting thresholds by " << diff << ". ";
  for (int i=THRESHOLD_1; i<=THRESHOLD_3; i++) {
    threshold[i] += diff;
    cout << i << "=" << threshold[i];
  }
  cout << endl;
};

//--------------------------------------------------------------
string InputIntensity::getTrace() {
  stringstream ss;
  
  ss << "InputLevel:\n"
         "  Thresholds:" + ofToString(threshold[THRESHOLD_1]) + " " + ofToString(threshold[THRESHOLD_2]) + " " + ofToString(threshold[THRESHOLD_3]) + "\n"
         "  Current intensity: " + ofToString(getIntensity()) + "\n"
         "  Current value: " << roundf(dataInput->getValue()*100)/100  << "\n";
  
  ss << dataInput->getTrace();
  
  return ss.str();
  
};
