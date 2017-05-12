//
//  ArduinoInput.cpp
//  vela2017
//
//  Created by Nuno on 16/03/2017.
//
//

#include "ArduinoInput.h"

//--------------------------------------------------------------
ArduinoInput::ArduinoInput(string _device, Thresholds thresholds, CalibrationSettings *calibrationSettings): DataInput("arduino") {
  input = new CalibratedValueInput(getName(),
                                   thresholds,
                                   calibrationSettings);
  device = _device;
  connect();
}

//--------------------------------------------------------------
bool ArduinoInput::connect() {
  serial.listDevices();
  return (serial.setup((device),9600));
}

//--------------------------------------------------------------
void ArduinoInput::readValueFromSerial() {
  
  // Continue only if initialized
  if (!serial.isInitialized())
    return;
  
  // we try to read 2 bytes
    
  //we are going to read 3x 0 - 1023 number as two bytes
  //we need a buffer to store the two bytes and a second
  //buffer with space for the terminating zero byte
  unsigned char bytesReturned[2];
  unsigned char bytesReadString[3];
  
  //clear our buffers
  memset(bytesReadString, 0, 4);
  memset(bytesReturned, 0, 3);
  
  //we read as much as possible so we make sure we get the newest data
  while( serial.readBytes( bytesReturned, 3) > 0);
  
  //lets update our buffer
  memcpy(bytesReadString, bytesReturned, 3);
    
  //we need to put the bytes back into an int
  lastValue = (unsigned char)bytesReadString[1] << 8 |
              (unsigned char)bytesReadString[0];
}
//--------------------------------------------------------------
void ArduinoInput::update() {
  readValueFromSerial();
  input->setValue(lastValue);
}

//--------------------------------------------------------------
string ArduinoInput::getTrace() {
  stringstream ss;
  ss << input->getTrace() << " device: " << device;
  return ss.str();
}
