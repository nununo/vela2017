//
//  MouseInput.cpp
//  vela2017
//
//  Created by Nuno on 15/03/2017.
//
//

#include "MouseInput.h"

//--------------------------------------------------------------
MouseInput::MouseInput(bool inverted, bool calibrated) {
  if (!inverted)
    valueInput = new ValueInput("mouse",
                                1*(float)ofGetScreenHeight()/4,
                                2*(float)ofGetScreenHeight()/4,
                                3*(float)ofGetScreenHeight()/4,
                                false,
                                calibrated);
  else
    valueInput = new ValueInput("mouseInverted",
                                3*(float)ofGetScreenHeight()/4,
                                2*(float)ofGetScreenHeight()/4,
                                1*(float)ofGetScreenHeight()/4,
                                true,
                                calibrated);
};
