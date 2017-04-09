//
//  KeyDataInput.cpp
//  vela2017
//
//  Created by Nuno on 16/03/2017.
//
//

#include "KeyDataInput.h"

//--------------------------------------------------------------
blowIntensityType KeyDataInput::getBlowIntensity() {
  blowIntensityType tempBlowIntensity;
  
  tempBlowIntensity = lastBlowIntensity;
  lastBlowIntensity = BLOW_INTENSITY_IDLE;
  return tempBlowIntensity;
}

//--------------------------------------------------------------
blowIntensityType KeyDataInput::calcBlowIntensity(int key) {
  
  switch (key) {
    case '3':
      return BLOW_INTENSITY_BLOWOUT;
      break;
      
    case '2':
      return BLOW_INTENSITY_HIGH;

    case '1':
      return BLOW_INTENSITY_LOW;
    
    default:
      return BLOW_INTENSITY_IDLE;
      break;
  }
};

//--------------------------------------------------------------
void KeyDataInput::keyPressed(ofKeyEventArgs &e) {
  switch (e.key) {
    case '1':
    case '2':
    case '3':
      lastBlowIntensity = calcBlowIntensity(e.key);
      break;
  };
};


//--------------------------------------------------------------
void KeyDataInput::registerKeyboardEvents() {
  if(!bRegisteredEvents) {
    ofRegisterKeyEvents(this); // enable our class to listen to mouse events.
    bRegisteredEvents = true;
  }
};

//--------------------------------------------------------------
void KeyDataInput::unregisterKeyboardEvents() {
  if(bRegisteredEvents)
    ofUnregisterKeyEvents(this);
  bRegisteredEvents = false;
};
