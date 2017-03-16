//
//  ArduinoInput.cpp
//  vela2017
//
//  Created by Nuno on 16/03/2017.
//
//

#include "ArduinoInput.h"

//--------------------------------------------------------------
ArduinoInput::ArduinoInput(int _device, int _maxValue) {
  maxValue = _maxValue;
  lastValue = 0;
  serial.listDevices();
  serial.setup(_device, 9600);
}

void ArduinoInput::update() {
  
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
    memcpy(bytesReadString, bytesReturned, 2);
    
    //we need to put the bytes back into an int and then remap it to a float
    int value = ( (unsigned char)bytesReadString[1] << 8 | (unsigned char)bytesReadString[0] );
    
    setValue(value);
  }
  
}

//--------------------------------------------------------------
void ArduinoInput::setValue(float value) {
  if (value > maxValue)
    return;
  lastValue = value;
}

