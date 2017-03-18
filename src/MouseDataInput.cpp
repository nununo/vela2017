//
//  MouseDataInput.cpp
//  vela2017
//
//  Created by Nuno on 15/03/2017.
//
//

#include "MouseDataInput.h"

//--------------------------------------------------------------
MouseDataInput::~MouseDataInput() {
  unregisterMouseEvents();
};

//--------------------------------------------------------------
void MouseDataInput::setup() {
  registerMouseEvents();
};

//--------------------------------------------------------------
float MouseDataInput::getValue() {
  return lastMouseY / ofGetScreenHeight();
};

//--------------------------------------------------------------
void MouseDataInput::update() {
  if (lastMouseY > 0)
    lastMouseY--;
};

//--------------------------------------------------------------
void MouseDataInput::mousePressed(ofMouseEventArgs & args) {
  cout << "mouse: " << args.y;
  lastMouseY = args.y;
};

//--------------------------------------------------------------
void MouseDataInput::registerMouseEvents() {
  if(!bRegisteredEvents) {
    ofRegisterMouseEvents(this); // this will enable our circle class to listen to the mouse events.
    bRegisteredEvents = true;
  }
};

//--------------------------------------------------------------
void MouseDataInput::unregisterMouseEvents() {
  if(bRegisteredEvents)
    ofUnregisterMouseEvents(this);
  bRegisteredEvents = false;
};
