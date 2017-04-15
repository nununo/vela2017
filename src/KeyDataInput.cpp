//
//  KeyDataInput.cpp
//  vela2017
//
//  Created by Nuno on 16/03/2017.
//
//

#include "KeyDataInput.h"

//--------------------------------------------------------------
void KeyDataInput::keyPressed(ofKeyEventArgs &e) {
  switch (e.key) {
    case '1':
      lastBlowIntensity = BLOW_INTENSITY_LOW;
      break;
    case '2':
      lastBlowIntensity = BLOW_INTENSITY_HIGH;
      break;
    case '3':
      lastBlowIntensity = BLOW_INTENSITY_BLOWOUT;
      break;
  };
};

//--------------------------------------------------------------
void KeyDataInput::keyReleased(ofKeyEventArgs &e) {
  lastBlowIntensity = BLOW_INTENSITY_MIN;
}

//--------------------------------------------------------------
void KeyDataInput::registerKeyboardEvents() {
  if(!bRegisteredEvents) {
    ofRegisterKeyEvents(this); // enable our class to listen to keyboard events.
    bRegisteredEvents = true;
  }
};

//--------------------------------------------------------------
void KeyDataInput::unregisterKeyboardEvents() {
  if(bRegisteredEvents)
    ofUnregisterKeyEvents(this);
  bRegisteredEvents = false;
};
