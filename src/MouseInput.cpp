//
//  MouseInput.cpp
//  vela2017
//
//  Created by Nuno on 15/03/2017.
//
//

#include "MouseInput.h"

//--------------------------------------------------------------
MouseInput::MouseInput(bool inverted, CalibrationSettings *calibrationSettings) : DataInput("mouse") {
  if (!inverted)
    calibratedValueInput =
      new CalibratedValueInput("mouse",
                               Thresholds(1*(float)ofGetScreenHeight()/4,
                                          2*(float)ofGetScreenHeight()/4,
                                          3*(float)ofGetScreenHeight()/4),
                               false,
                               calibrationSettings);
  else
    calibratedValueInput =
      new CalibratedValueInput("mouseInverted",
                               Thresholds(3*(float)ofGetScreenHeight()/4,
                                          2*(float)ofGetScreenHeight()/4,
                                          1*(float)ofGetScreenHeight()/4),
                               true,
                               calibrationSettings);
};
