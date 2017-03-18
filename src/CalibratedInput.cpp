//
//  CalibratedInput.cpp
//  vela2017
//
//  Created by Nuno on 16/03/2017.
//
//

#include "CalibratedInput.h"

//--------------------------------------------------------------
CalibratedInput::CalibratedInput(IDataInput *_dataInput) {
 dataInput = _dataInput;
  offset = 0;
};

//--------------------------------------------------------------
void CalibratedInput::update() {
  dataInput->update();
}

//--------------------------------------------------------------
void CalibratedInput::setup() {
  dataInput->setup();
}

//--------------------------------------------------------------
void CalibratedInput::calibrate() {
//  cout << "Calibrating...";
//  if (!calibrate1())
//    calibrate2();
}

//--------------------------------------------------------------
bool CalibratedInput::calibrate1() {
  //  int count = 0;
  //  for(int i=ARDUINO_BUFFER_SIZE-1; i>=0; i--)
  //    if (getIntensity(buffer[i])>0)
  //      count++;
  //  if (count > ARDUINO_CALIBRATION_COUNT) {
  //    offsetOffset(1);
  //    cout << " lowering sensibility by 1. movements=" << count << endl;
  //  }
}

//--------------------------------------------------------------
bool CalibratedInput::calibrate2() {
//  // Sort buffer in ascending order
//  sort(buffer, buffer+ARDUINO_BUFFER_SIZE);
//  // get max value
//  int maxValue = buffer[ARDUINO_BUFFER_SIZE-1];
//  // Go from bigger to smaller values but only the biggest value is relevant so when
//  // we find a new one we stop counting
//  int count = 0;
//  for(int i=ARDUINO_BUFFER_SIZE-1; i>=0; i--) {
//    // If a new value is found then
//    if (buffer[i] != maxValue)
//      break;
//    count++;
//  }
//  
//  cout << " max=" << maxValue << " count=" << count;
//  
//  if (count > ARDUINO_CALIBRATION_COUNT) {
//    // Calculate difference between
//    int diffCalibration = maxValue - offset + 1;
//    offsetOffset(diffCalibration);
//    cout << " adjusting sentibility." << " diff=" << diffCalibration << endl;
//  } else {
//    cout << " unstable: nothing done." << endl;
//  }
}
