//
//  CalibratedValueInput.cpp
//  vela2017
//
//  Created by Nuno on 26/04/2017.
//
//

#include "CalibratedValueInput.h"

// the static event, or any static variable, must be initialized outside of the class definition.
ofEvent<ThresholdsEventArgs> CalibratedValueInput::thresholdsCalibrated = ofEvent<ThresholdsEventArgs>();

//--------------------------------------------------------------
CalibratedValueInput::CalibratedValueInput(string name,
                                           Thresholds thresholds,
                                           CalibrationSettings* _settings) : ThresholdsDataInput(name) {
  
  valueInput = new ValueInput(name, thresholds);
  
  settings = _settings;
  
  buffer = new float[settings->getBufferSize()];

}

//--------------------------------------------------------------
void CalibratedValueInput::setValue(float value) {
  valueInput->setValue(value);

  sampleValue(value);
}

//--------------------------------------------------------------
void CalibratedValueInput::sampleValue(float value) {
  
  // We only get samples every N requests
  // This allows for:
  // - longer calibration cycles without keeping a very long array
  // - lower excentricity since we won't store all values for peak moments
  
  stepCounter = ((stepCounter + 1) % settings->getSkipSize());

  if (stepCounter==0) {
    buffer[index] = value;

    index = ((index + 1) % settings->getBufferSize());

    // We only calibrate when the sample array is full of new data to save CPU
    if (index==0)
      calibrateOffset();
  }
}

//--------------------------------------------------------------
void CalibratedValueInput::calibrateOffset() {
  
  removeExcentric();
  
  valueInput->getThresholds()->setOffset(getAverage());

  broadcastThresholdsCalibratedEvent();
  
  ofLogNotice() << "Calibrating. Result: " << valueInput->getThresholds()->getOffset();
}

//--------------------------------------------------------------
float CalibratedValueInput::getAverage() {
  float sum=0;
  
  for (int i=0; i<settings->getBufferSize(); i++)
    sum += buffer[i];
  
  return sum / settings->getBufferSize();
}

//--------------------------------------------------------------
float CalibratedValueInput::getMaxAcceptedDistance(const float average) {
  
  float distance[settings->getBufferSize()];
  
  for (int i=0; i<settings->getBufferSize(); i++)
    distance[i] = abs(average-buffer[i]);
  
  sort(distance, distance + settings->getBufferSize());
  
  return distance[settings->getBufferSize()-settings->getExcentricSize()];
}

//--------------------------------------------------------------
void CalibratedValueInput::removeExcentric() {
  float average = getAverage();
  float maxAcceptedDistance = getMaxAcceptedDistance(average);
  
  for (int i=0; i<settings->getBufferSize(); i++)
    if (abs(buffer[i]-average) > maxAcceptedDistance)
      buffer[i] = average;
}

//--------------------------------------------------------------
void CalibratedValueInput::broadcastThresholdsCalibratedEvent() {
  ThresholdsEventArgs evenArgs = ThresholdsEventArgs(getName(), *getThresholds());
  ofNotifyEvent(thresholdsCalibrated, evenArgs);
}
//--------------------------------------------------------------
/*string CalibratedValueInput::getTrace() {
  stringstream ss;
  ss  << "calibrated: " << settings->getTrace() << "(" << roundf((float)index/(float)settings->getBufferSize()*10)/10 << ")";
  return ss.str();
}*/

