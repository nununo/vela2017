//
//  KeyboardDataInput.cpp
//  vela2017
//
//  Created by Nuno on 16/03/2017.
//
//

#include "KeyboardDataInput.h"

//--------------------------------------------------------------
KeyboardDataInput::KeyboardDataInput() {

  ofRegisterKeyEvents(this); // enable our class to listen to keyboard events.

  valueInput = new ValueInput("keyboard",
                              0,
                              1,
                              2,
                              3);
}

//--------------------------------------------------------------
void KeyboardDataInput::keyPressed(ofKeyEventArgs &e) {
  
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
void KeyboardDataInput::keyReleased(ofKeyEventArgs &e) {
  valueInput->setValue(0);
}
