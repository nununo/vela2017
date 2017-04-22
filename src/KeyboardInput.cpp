//
//  KeyboardInput.cpp
//  vela2017
//
//  Created by Nuno on 16/03/2017.
//
//

#include "KeyboardInput.h"

//--------------------------------------------------------------
KeyboardInput::KeyboardInput() {

  ofRegisterKeyEvents(this); // enable our class to listen to keyboard events.

  valueInput = new ValueInput("keyboard",
                              1,
                              2,
                              3,
                              false);
}

//--------------------------------------------------------------
void KeyboardInput::keyPressed(ofKeyEventArgs &e) {
  
  switch (e.key) {
    case '1':
      valueInput->setValue(1);
      break;
    case '2':
      valueInput->setValue(2);
      break;
    case '3':
      valueInput->setValue(3);
      break;
  };
};

//--------------------------------------------------------------
void KeyboardInput::keyReleased(ofKeyEventArgs &e) {
  valueInput->setValue(0);
}
