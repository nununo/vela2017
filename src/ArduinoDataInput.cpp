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
ArduinoDataInput::ArduinoDataInput(string _device) {
    
  device = _device;
  serial.listDevices();
  serial.setup(_device, 9600);
}

//--------------------------------------------------------------
void ArduinoDataInput::addAnalogInput(AnalogInput *analogInput) {
  if (analogInput)
    analogInputs.push_back(analogInput);
}

//--------------------------------------------------------------
void ArduinoDataInput::update() {
  
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
    vector<AnalogInput*>::iterator it;
    int i=0;
    for(it=analogInputs.begin() ; it < analogInputs.end(); it++,i=i+2)
      (*it)->setValue((unsigned char)bytesReadString[i+1] << 8 | (unsigned char)bytesReadString[i]);
  }
}


//--------------------------------------------------------------
blowIntensityType ArduinoDataInput::getBlowIntensity() {
  blowIntensityType blowIntensity = BLOW_INTENSITY_MIN;

  vector<AnalogInput*>::iterator it;
  for(it=analogInputs.begin() ; it < analogInputs.end(); it++)
    if ((*it)->getBlowIntensity()>blowIntensity)
      blowIntensity = (*it)->getBlowIntensity();
  
  return blowIntensity;
}

//--------------------------------------------------------------
string ArduinoDataInput::getTrace() {
  stringstream ss;
  
  ss << "Arduino input device " << device << " initialized: " << serial.isInitialized() << "\n";

  vector<AnalogInput*>::iterator it;
  for(it=analogInputs.begin() ; it < analogInputs.end(); it++)
    ss << (*it)->getTrace();

  return ss.str();
}
