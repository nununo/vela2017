//
//  ArduinoInput.cpp
//  vela2017
//
//  Created by Nuno on 16/03/2017.
//
//

#include "ArduinoInput.h"

//--------------------------------------------------------------
ArduinoInput::ArduinoInput(string name, int _inputId, ThresholdsDataInput *_input): DataInput(name) {
  input = _input;
  arduino = &Arduino::getInstance();
  inputId = _inputId;
}

//--------------------------------------------------------------
void ArduinoInput::update() {
  input->setValue(arduino->getValue(inputId));
}

//--------------------------------------------------------------
string ArduinoInput::getTrace() {
  stringstream ss;
  
  ss << getName() << ": " << inputId << " " << input->getTrace();

  return ss.str();
}
