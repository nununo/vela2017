//
//  MouseInput.cpp
//  vela2017
//
//  Created by Nuno on 15/03/2017.
//
//

#include "MouseInput.h"
#include "Util.h"

//--------------------------------------------------------------
MouseInput::MouseInput(bool inverted) {
  if (!inverted)
    valueInput = new ValueInput("mouse",
                                0,
                                1*(float)ofGetScreenHeight()/4,
                                2*(float)ofGetScreenHeight()/4,
                                3*(float)ofGetScreenHeight()/4,
                                false);
  else
    valueInput = new ValueInput("mouseInverted",
                                ofGetScreenHeight(),
                                3*(float)ofGetScreenHeight()/4,
                                2*(float)ofGetScreenHeight()/4,
                                1*(float)ofGetScreenHeight()/4,
                                true);
};
