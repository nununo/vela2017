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
MouseInput::MouseInput(bool inverted, CalibrationSettings calibrationSettings) : DataInput("mouse") {
  input = new CalibratedValueInput(getName(),
                                   createThresholdsSettings(inverted),
                                   calibrationSettings);
};

//--------------------------------------------------------------
ThresholdsSettings MouseInput::createThresholdsSettings(bool inverted) {
  ThresholdsSettings settings;

  if (!inverted)
    settings = ThresholdsSettings(1*(float)ofGetScreenHeight()/4,
                                  2*(float)ofGetScreenHeight()/4,
                                  3*(float)ofGetScreenHeight()/4,
                                  false);
  else
    settings = ThresholdsSettings(3*(float)ofGetScreenHeight()/4,
                                  2*(float)ofGetScreenHeight()/4,
                                  1*(float)ofGetScreenHeight()/4,
                                  true);
  
  return settings;
}
