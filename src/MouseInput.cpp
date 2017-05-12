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
  input = new CalibratedValueInput(getName(),
                                   createThresholds(inverted),
                                   calibrationSettings);
};

//--------------------------------------------------------------
Thresholds MouseInput::createThresholds(bool inverted) {
  Thresholds thresholds;

  if (!inverted)
    thresholds = Thresholds(1*(float)ofGetScreenHeight()/4,
                            2*(float)ofGetScreenHeight()/4,
                            3*(float)ofGetScreenHeight()/4,
                            false);
  else
    thresholds = Thresholds(3*(float)ofGetScreenHeight()/4,
                            2*(float)ofGetScreenHeight()/4,
                            1*(float)ofGetScreenHeight()/4,
                            true);
  
  return thresholds;
}
