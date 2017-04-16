//
//  ArduinoInput.cpp
//  vela2017
//
//  Created by Nuno on 16/03/2017.
//
//

#include "ArduinoInput.h"
#include <sstream>

//--------------------------------------------------------------
bool ArduinoInput::connect() {
  serial.listDevices();
  
  vector<string>::iterator it;
  for(it=devices.begin() ; it < devices.end(); it++)
    if (serial.setup((*it),9600)) {
      device = (*it);
      return true;
    }
  return false;
}

//--------------------------------------------------------------
void ArduinoInput::addValueInput(ValueInput *valueInput) {
  if (valueInput)
    valueInputs.push_back(valueInput);
}

//--------------------------------------------------------------
void ArduinoInput::update() {
  
  // Continue only if initialized
  if (!serial.isInitialized())
    return;
  
  // we try to read 2 bytes
  
  //clear our variables
  int nTimesRead  = 0;
  int nBytesRead  = 0;
  int nRead		= 0;  // a temp variable to keep count per read
  
  //we are going to read a 0 - 1024 number as two bytes
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
  
  //if we have got both bytes
  if( nBytesRead == 6){
    
    //lets update our buffer
    memcpy(bytesReadString, bytesReturned, 7);
    
    //we need to put the bytes back into an int
    vector<ValueInput*>::iterator it;
    int i=0;
    for(it=valueInputs.begin() ; it < valueInputs.end(); it++,i=i+2)
      (*it)->setValue((unsigned char)bytesReadString[i+1] << 8 | (unsigned char)bytesReadString[i]);
  }
}


//--------------------------------------------------------------
blowIntensityType ArduinoInput::getBlowIntensity() {
  blowIntensityType blowIntensity = BLOW_INTENSITY_IDLE;

  vector<ValueInput*>::iterator it;
  for(it=valueInputs.begin() ; it < valueInputs.end(); it++)
    if ((*it)->getBlowIntensity()>blowIntensity)
      blowIntensity = (*it)->getBlowIntensity();
  
  return blowIntensity;
}

//--------------------------------------------------------------
string ArduinoInput::getTrace() {
  stringstream ss;
  
  ss << "Arduino input device " << device << " initialized: " << serial.isInitialized() << "\n";

  vector<ValueInput*>::iterator it;
  for(it=valueInputs.begin() ; it < valueInputs.end(); it++)
    ss << (*it)->getTrace();

  return ss.str();
}
