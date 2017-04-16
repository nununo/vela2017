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

  analogDataInput = new AnalogDataInput("keyboard",
                                        0,
                                        4,
                                        1,
                                        2,
                                        3);
}

//--------------------------------------------------------------
void KeyboardDataInput::keyPressed(ofKeyEventArgs &e) {
  
  switch (e.key) {
    case '1':
      analogDataInput->setValue(1);
      break;
    case '2':
      analogDataInput->setValue(2);
      break;
    case '3':
      analogDataInput->setValue(3);
      break;
  };
};

//--------------------------------------------------------------
void KeyboardDataInput::keyReleased(ofKeyEventArgs &e) {
  analogDataInput->setValue(0);
}
