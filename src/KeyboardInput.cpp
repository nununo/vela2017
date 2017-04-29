//
//  KeyboardInput.cpp
//  vela2017
//
//  Created by Nuno on 16/03/2017.
//
//

#include "KeyboardInput.h"

//--------------------------------------------------------------
KeyboardInput::KeyboardInput() : DataInput("keyboard") {

  ofRegisterKeyEvents(this); // enable our class to listen to keyboard events.

  input = new ValueInput(getName(),
                         Thresholds(1,2,3,false));
}

//--------------------------------------------------------------
void KeyboardInput::keyPressed(ofKeyEventArgs &e) {
  
  switch (e.key) {
    case '1':
      input->setValue(1);
      break;
    case '2':
      input->setValue(2);
      break;
    case '3':
      input->setValue(3);
      break;
  };
};

//--------------------------------------------------------------
void KeyboardInput::keyReleased(ofKeyEventArgs &e) {
  input->setValue(0);
}
