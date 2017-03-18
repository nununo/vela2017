//
//  KeyboardInput.cpp
//  vela2017
//
//  Created by Nuno on 16/03/2017.
//
//

#include "KeyboardInput.h"

//--------------------------------------------------------------
KeyboardInput::~KeyboardInput() {
  unregisterKeyboardEvents();
};

//--------------------------------------------------------------
void KeyboardInput::setup() {
  registerKeyboardEvents();
};

//--------------------------------------------------------------
float KeyboardInput::getValue() {
  switch (lastKey) {
    case '3':
      return 0.99f;
      break;
      
    case '2':
      return 0.55f;

    case '1':
      return 0.3f;
    
    default:
      return 0.0f;
      break;
  }
  lastKey = 0;
};

//--------------------------------------------------------------
void KeyboardInput::keyPressed(ofKeyEventArgs &e) {
  switch (e.key) {
    case '1':
    case '2':
    case '3':
      lastKey = e.key;
      break;
  };
};


//--------------------------------------------------------------
void KeyboardInput::registerKeyboardEvents() {
  if(!bRegisteredEvents) {
    ofRegisterKeyEvents(this); // enable our class to listen to mouse events.
    bRegisteredEvents = true;
  }
};

//--------------------------------------------------------------
void KeyboardInput::unregisterKeyboardEvents() {
  if(bRegisteredEvents)
    ofUnregisterKeyEvents(this);
  bRegisteredEvents = false;
};

