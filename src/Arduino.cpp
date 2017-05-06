//
//  Arduino.cpp
//  vela2017
//
//  Created by Nuno on 30/04/2017.
//
//

#include "Arduino.h"

//--------------------------------------------------------------
Arduino& Arduino::getInstance() {
  static Arduino a;
  return a;
}

//--------------------------------------------------------------
bool Arduino::setup(ArduinoSettings _settings) {
  settings=_settings;
  return connect();
}

//--------------------------------------------------------------
bool Arduino::connect() {
  serial.listDevices();
  vector<string> devices = settings.getDevices();
  vector<string>::iterator it;
  for(it=devices.begin() ; it < devices.end(); it++)
    if (serial.setup((*it),9600)) {
      device = (*it);
      return true;
    }
  return false;
}

//--------------------------------------------------------------
void Arduino::update() {
  
  // Continue only if initialized
  if (!serial.isInitialized())
    return;
  
  // we try to read 2 bytes
  
  //clear our variables
  int nTimesRead  = 0;
  int nBytesRead  = 0;
  int nRead		= 0;  // a temp variable to keep count per read
  
  //we are going to read 3x 0 - 1023 number as two bytes
  //we need a buffer to store the two bytes and a second
  //buffer with space for the terminating zero byte
  unsigned char bytesReturned[6];
  unsigned char bytesReadString[7];
  
  //clear our buffers
  memset(bytesReadString, 0, 7);
  memset(bytesReturned, 0, 6);
  
  //we read as much as possible so we make sure we get the newest data
  while( (nRead = serial.readBytes( bytesReturned, 6)) > 0){
    nTimesRead++;
    nBytesRead = nRead;
  }
  
  //if we have got 3 pairs of 2 bytes
  if( nBytesRead == 6){
    
    //lets update our buffer
    memcpy(bytesReadString, bytesReturned, 7);
    
    //we need to put the bytes back into an int
    for(int i=0; i<3; i++)
      values[i] = (unsigned char)bytesReadString[2*i+1] << 8 | (unsigned char)bytesReadString[2*i];
  }
}

//--------------------------------------------------------------
string Arduino::getTrace() {
  stringstream ss;
  
  ss << "Arduino" << ": " << device << " connected: " << serial.isInitialized();
  
  for(int i=0; i<3; i++)
    ss << " v[" << i << "]=" << (int)values[i] << " ";
    
  return ss.str();
}
