//
//  ArduinoInput.cpp
//  vela2017
//
//  Created by Nuno on 16/03/2017.
//
//

#include "ArduinoInput.h"

//--------------------------------------------------------------
ArduinoInput::ArduinoInput(string _device, ThresholdsSettings thresholdsSettings): DataInput("arduino") {
  input = new DerivativeValueInput(getName(),
                                   thresholdsSettings);
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
  
  unsigned char bytesReturned[2];
  int bytesRead;
  
  
  // Arduino sends space followed by 2 bytes
  memset(bytesReturned, 0, 2);
  do {
    // So first we wait for a space
    bytesRead = serial.readBytes(bytesReturned, 1);
  }
  while (bytesReturned[0] != ' ' && bytesRead > 0);
  
  // If a space was found, we read the other 2 bytes
  if (bytesReturned[0]==' ') {
    memset(bytesReturned, 0, 2);
    bytesRead = serial.readBytes(bytesReturned, 2);
  
    // If indeed we read 2 bytes, convert them into an int
    if (bytesRead == 2)
      lastValue = (unsigned char)bytesReturned[1] << 8 | (unsigned char)bytesReturned[0];
  }
  // Not sure if this is needed
  serial.flush();

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
