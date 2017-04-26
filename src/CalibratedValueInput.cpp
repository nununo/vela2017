//
//  CalibratedValueInput.cpp
//  vela2017
//
//  Created by Nuno on 26/04/2017.
//
//

#include "CalibratedValueInput.h"

//--------------------------------------------------------------
CalibratedValueInput::CalibratedValueInput(string name,
                                           Thresholds thresholds,
                                           bool inverted,
                                           CalibrationSettings* _settings) : DataInput(name) {
  
  valueInput = new ValueInput(name, thresholds, inverted);
  
  settings = _settings;
  
  history = new float[settings->getHistorySize()];

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
    history[index] = value;

    index = ((index + 1) % settings->getHistorySize());

    // We only calibrate when the sample array is full of new data to save CPU
    if (index==0)
      calcOffset();
  }
}

//--------------------------------------------------------------
void CalibratedValueInput::calcOffset() {
  removeExcentric();
  valueInput->getThresholds()->setOffset(getAverage());
  ofLogNotice() << "Calibrating. Result: " << valueInput->getThresholds()->getOffset();
}

//--------------------------------------------------------------
float CalibratedValueInput::getAverage() {
  float sum=0;
  
  for (int i=0; i<settings->getHistorySize(); i++)
    sum += history[i];
  
  return sum / settings->getHistorySize();
}

//--------------------------------------------------------------
float CalibratedValueInput::getMaxAcceptedDistance(float average) {
  
  float distance[settings->getHistorySize()];
  
  for (int i=0; i<settings->getHistorySize(); i++)
    distance[i] = abs(average-history[i]);
  
  sort(distance, distance + settings->getHistorySize());
  
  return distance[settings->getHistorySize()-settings->getExcentricSize()];
}

//--------------------------------------------------------------
void CalibratedValueInput::removeExcentric() {
  float average = getAverage();
  float maxAcceptedDistance = getMaxAcceptedDistance(average);
  
  for (int i=0; i<settings->getHistorySize(); i++)
    if (abs(history[i]-average) > maxAcceptedDistance)
      history[i] = average;
}

//--------------------------------------------------------------
/*string CalibratedValueInput::getTrace() {
  stringstream ss;
  ss  << "calibrated: " << settings->getTrace() << "(" << roundf((float)index/(float)settings->getHistorySize()*10)/10 << ")";
  return ss.str();
}*/

