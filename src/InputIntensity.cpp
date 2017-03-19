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

using namespace std;

//--------------------------------------------------------------
InputIntensity::InputIntensity( IDataInput *_dataInput ) {
  dataInput = _dataInput;
  
  threshold[THRESHOLD_1] = 0.25f;
  threshold[THRESHOLD_2] = 0.50f;
  threshold[THRESHOLD_3] = 0.75f;
};

//--------------------------------------------------------------
int InputIntensity::getIntensity() {
  
  float value = dataInput->getValue();
  int intensity;
  
  if (value > threshold[THRESHOLD_3])
    intensity = LEVEL_3;
  else if (value > threshold[THRESHOLD_2])
    intensity = LEVEL_2;
  else if (value > threshold[THRESHOLD_1])
    intensity = LEVEL_1;
  else
    intensity = LEVEL_0;
  
  return intensity;
  
};

//--------------------------------------------------------------
void InputIntensity::update() {
  dataInput->update();
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
  return "InputLevel:\n"
         "  Thresholds:" + ofToString(threshold[THRESHOLD_1]) + " " + ofToString(threshold[THRESHOLD_2]) + " " + ofToString(threshold[THRESHOLD_3]) + "\n"
         "  Current intensity: " + ofToString(getIntensity()) + "\n"
         "  Current value: " + ofToString(dataInput->getValue()) + "\n";
};
