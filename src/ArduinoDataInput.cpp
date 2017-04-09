//
//  ArduinoDataInput.cpp
//  vela2017
//
//  Created by Nuno on 16/03/2017.
//
//

#include "ArduinoDataInput.h"
#include <sstream>

//--------------------------------------------------------------
ArduinoDataInput::ArduinoDataInput(string _device, int _minValue, int _maxValue) {
  minValue = _minValue;
  maxValue = _maxValue;
  lastValue = minValue;
  device = _device;
  serial.listDevices();
  serial.setup(_device, 9600);
}

//--------------------------------------------------------------
void ArduinoDataInput::update() {
  
  // we try to read 2 bytes
  
  //clear our variables
  int nTimesRead  = 0;
  int nBytesRead  = 0;
  int nRead		= 0;  // a temp variable to keep count per read
  
  //we are going to read a 0 - 1024 number as two bytes
  //we need a buffer to store the two bytes and a second
  //buffer with space for the terminating zero byte
  unsigned char bytesReturned[2];
  unsigned char bytesReadString[3];
  
  //clear our buffers
  memset(bytesReadString, 0, 3);
  memset(bytesReturned, 0, 2);
  
  //we read as much as possible so we make sure we get the newest data
  while( (nRead = serial.readBytes( bytesReturned, 2)) > 0){
    nTimesRead++;
    nBytesRead = nRead;
  }
  
  //if we have got both bytes
  if( nBytesRead == 2){
    
    //lets update our buffer
    memcpy(bytesReadString, bytesReturned, 3);
    
    //we need to put the bytes back into an int and then remap it to a float
    int value = ( (unsigned char)bytesReadString[0] << 8 | (unsigned char)bytesReadString[1] );
    
    setValue(value);
  }
  
}

//--------------------------------------------------------------
void ArduinoDataInput::setValue(int value) {
  
  if (value < minValue || value > maxValue)
    return;
  
  lastValue = value;
}

//--------------------------------------------------------------
blowIntensityType ArduinoDataInput::getBlowIntensity() {
//  return ofMap(lastValue, minValue, maxValue, 0.0f, 1.0f); " XXX
}

//--------------------------------------------------------------
string ArduinoDataInput::getTrace() {
  stringstream ss;
  
  ss << "Arduino input device " << device << " min:" << minValue << " max:" << maxValue << " last:" << lastValue << "\n";
  
  return ss.str();
}
