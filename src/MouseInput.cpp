//
//  MouseInput.cpp
//  vela2017
//
//  Created by Nuno on 15/03/2017.
//
//

#include "MouseInput.h"
#include "DerivativeValueInput.h"

//--------------------------------------------------------------
MouseInput::MouseInput(ThresholdsSettings thresholdsSettings) : DataInput("mouse") {
  input = new DerivativeValueInput(getName(), thresholdsSettings);
};
