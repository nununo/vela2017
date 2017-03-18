//
//  InputLevel.cpp
//  vela2017
//
//  Created by Nuno on 15/03/2017.
//
//

#include "InputLevel.h"
#include <iostream>
#include "ofMain.h"

using namespace std;

//--------------------------------------------------------------
InputLevel::InputLevel( IDataInput *_dataInput ) {
  dataInput = _dataInput;
  
  threshold[THRESHOLD_1] = 0.25f;
  threshold[THRESHOLD_2] = 0.50f;
  threshold[THRESHOLD_3] = 0.75f;
};

//--------------------------------------------------------------
int InputLevel::getLevel() {
  
  float value = dataInput->getValue();
  int level;
  
  if (value > threshold[THRESHOLD_3])
    level = LEVEL_3;
  else if (value > threshold[THRESHOLD_2])
    level = LEVEL_2;
  else if (value > threshold[THRESHOLD_1])
    level = LEVEL_1;
  else
    level = LEVEL_0;
  
  return level;
  
};

//--------------------------------------------------------------
void InputLevel::update() {
  dataInput->update();
}

//--------------------------------------------------------------
void InputLevel::offsetThresholds(float diff) {
  cout << "Offsettting thresholds by " << diff << ". ";
  for (int i=THRESHOLD_1; i<=THRESHOLD_3; i++) {
    threshold[i] += diff;
    cout << i << "=" << threshold[i];
  }
  cout << endl;
};

//--------------------------------------------------------------
string InputLevel::getInfo() {
  return "InputLevel:\n"
         "  Thresholds:" + ofToString(getThreshold(THRESHOLD_1)) + ofToString(getThreshold(THRESHOLD_2)) + ofToString(getThreshold(THRESHOLD_3)) + "\n";
};
