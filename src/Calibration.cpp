//
//  Calibration.cpp
//  vela2017
//
//  Created by Nuno on 16/04/2017.
//
//

#include "Calibration.h"
#include "ofMain.h"

//--------------------------------------------------------------
float Calibration::getOffset(float value) {

  if (isSamplingTime()) {
    ofLogNotice() << "Sampling time. Index: " << index << "\n";
    history[index] = value;
    
    if (isCalibrationTime())
      calcCalibratedZero();
  }
  
  return lastCalibratedZero;
}

//--------------------------------------------------------------
bool Calibration::isSamplingTime() {

  // We only get samples every N requests
  // This allows for:
  // - longer calibration cycles without keeping a very long array
  // - lower excentricity since we won't store all values for peak moments
  stepCounter = ((stepCounter + 1) % CALIBRATION_STEP_SIZE);
  return stepCounter == 0;
}

//--------------------------------------------------------------
bool Calibration::isCalibrationTime() {
  
  // We only calibrate when the sample array is full of new data
  // This avoids constant CPU effort
  index = ((index + 1) % CALIBRATION_HISTORY_SIZE);
  return index == 0;
}

//--------------------------------------------------------------
void Calibration::calcCalibratedZero() {
  removeExcentric();
  lastCalibratedZero = getAverage();
  ofLogNotice() << "Calibrating. Result: " << lastCalibratedZero;
}

//--------------------------------------------------------------
float Calibration::getAverage() {
  float sum=0;

  for (int i=0; i<CALIBRATION_HISTORY_SIZE; i++)
    sum += history[i];
  
  return sum / CALIBRATION_HISTORY_SIZE;
}

//--------------------------------------------------------------
float Calibration::getMaxAcceptedDistance(float average) {
  
  float distance[CALIBRATION_HISTORY_SIZE];

  for (int i=0; i<CALIBRATION_HISTORY_SIZE; i++)
    distance[i] = abs(average-history[i]);

  sort(distance, distance + CALIBRATION_HISTORY_SIZE);

  return distance[CALIBRATION_HISTORY_SIZE-CALIBRATION_EXCENTRIC_SIZE];
}

//--------------------------------------------------------------
void Calibration::removeExcentric() {
  float average = getAverage();
  float maxAcceptedDistance = getMaxAcceptedDistance(average);
  
  for (int i=0; i<CALIBRATION_HISTORY_SIZE; i++)
    if (abs(history[i]-average) > maxAcceptedDistance)
      history[i] = average;
}
