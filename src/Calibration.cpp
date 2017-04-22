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
Calibration::Calibration(CalibrationSettings *_settings) {
  settings = _settings;
  
  history = new float[settings->getHistorySize()];
}

//--------------------------------------------------------------
float Calibration::getOffset(float value) {

  if (isSamplingTime()) {
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
  stepCounter = ((stepCounter + 1) % settings->getSkipSize());
  return stepCounter == 0;
}

//--------------------------------------------------------------
bool Calibration::isCalibrationTime() {
  
  // We only calibrate when the sample array is full of new data
  // This avoids constant CPU effort
  index = ((index + 1) % settings->getHistorySize());
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

  for (int i=0; i<settings->getHistorySize(); i++)
    sum += history[i];
  
  return sum / settings->getHistorySize();
}

//--------------------------------------------------------------
float Calibration::getMaxAcceptedDistance(float average) {
  
  float distance[settings->getHistorySize()];

  for (int i=0; i<settings->getHistorySize(); i++)
    distance[i] = abs(average-history[i]);

  sort(distance, distance + settings->getHistorySize());

  return distance[settings->getHistorySize()-settings->getExcentricSize()];
}

//--------------------------------------------------------------
void Calibration::removeExcentric() {
  float average = getAverage();
  float maxAcceptedDistance = getMaxAcceptedDistance(average);
  
  for (int i=0; i<settings->getHistorySize(); i++)
    if (abs(history[i]-average) > maxAcceptedDistance)
      history[i] = average;
}

//--------------------------------------------------------------
string Calibration::getTrace() {
  stringstream ss;
  ss  << "calibrated: " << settings->getTrace() << "(" << roundf((float)index/(float)settings->getHistorySize()*10)/10 << ")";
  return ss.str();
}
