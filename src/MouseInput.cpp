//
//  MouseInput.cpp
//  vela2017
//
//  Created by Nuno on 15/03/2017.
//
//

#include "MouseInput.h"

//--------------------------------------------------------------
MouseInput::~MouseInput() {
  unregisterMouseEvents();
};

//--------------------------------------------------------------
void MouseInput::setup() {
  registerMouseEvents();
};

//--------------------------------------------------------------
float MouseInput::getValue() {
  float value = lastMouseY / ofGetScreenHeight();
  lastMouseY = 0;
  return value;
};

//--------------------------------------------------------------
void MouseInput::mousePressed(ofMouseEventArgs & args) {
  cout << "mouse: " << args.y;
  lastMouseY = args.y;
};

//--------------------------------------------------------------
void MouseInput::registerMouseEvents() {
  if(!bRegisteredEvents) {
    ofRegisterMouseEvents(this); // this will enable our circle class to listen to the mouse events.
    bRegisteredEvents = true;
  }
};

//--------------------------------------------------------------
void MouseInput::unregisterMouseEvents() {
};
