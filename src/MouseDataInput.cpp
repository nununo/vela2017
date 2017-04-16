//
//  MouseDataInput.cpp
//  vela2017
//
//  Created by Nuno on 15/03/2017.
//
//

#include "MouseDataInput.h"
#include "Util.h"

//--------------------------------------------------------------
MouseDataInput::MouseDataInput() {
  valueInput =
    new ValueInput("mouse",
                        0,
                        ofGetScreenHeight(),
                        (float)ofGetScreenHeight()/4,
                        2*(float)ofGetScreenHeight()/4,
                        3*(float)ofGetScreenHeight()/4);
};
