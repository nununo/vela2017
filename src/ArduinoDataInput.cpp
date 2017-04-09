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
ArduinoDataInput::ArduinoDataInput(string _device, AnalogInputSettings *_settings) {
  settings = _settings;
  lastValue = settings->getThreshold(BLOW_INTENSITY_MIN);
  device = _device;
  serial.listDevices();
  serial.setup(_device, 9600);
}

//--------------------------------------------------------------
void ArduinoDataInput::update() {
  
  // Continue only if initialized
  if (!serial.isInitialized())
    return BLOW_INTENSITY_MIN;
  
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
  
  if (value < settings->getThreshold(BLOW_INTENSITY_MIN) || value > settings->getThreshold(BLOW_INTENSITY_MAX))
    return;
  
  lastValue = value;
}

//--------------------------------------------------------------
string ArduinoDataInput::getTrace() {
  stringstream ss;
  
  ss << "Arduino input device " << device << " initialized: " << serial.isInitialized() << " last:" << lastValue << "\n";
  ss << "    " << settings->getTrace();
  return ss.str();
}
