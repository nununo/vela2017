//
//  MouseInput.cpp
//  vela2017
//
//  Created by Nuno on 15/03/2017.
//
//

#include "MouseInput.h"
#include "CalibratedValueInput.h"


//--------------------------------------------------------------
MouseInput::MouseInput(bool inverted, CalibrationSettings *calibrationSettings) : DataInput("mouse") {
  
  if (calibrationSettings)
    input = new CalibratedValueInput(buildName(inverted, true),
                                     getThresholds(inverted),
                                     inverted,
                                     calibrationSettings);
  else
    input = new ValueInput(buildName(inverted, false),
                           getThresholds(inverted),
                           inverted);
};

//--------------------------------------------------------------
Thresholds MouseInput::getThresholds(bool inverted) {
  Thresholds thresholds;

  if (!inverted)
    thresholds = Thresholds(1*(float)ofGetScreenHeight()/4,
                            2*(float)ofGetScreenHeight()/4,
                            3*(float)ofGetScreenHeight()/4);
  else
    thresholds = Thresholds(3*(float)ofGetScreenHeight()/4,
                            2*(float)ofGetScreenHeight()/4,
                            1*(float)ofGetScreenHeight()/4);
  
  return thresholds;
}

//--------------------------------------------------------------
string MouseInput::buildName(bool inverted, bool calibrated) {
  string name = "mouse";
  if (inverted)
    name = name + "Inverted";
  if (calibrated)
    name = name + "Calibrated";
  return name;
}
