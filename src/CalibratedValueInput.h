//
//  CalibratedValueInput.h
//  vela2017
//
//  Created by Nuno on 26/04/2017.
//
//

#ifndef CalibratedValueInput_h
#define CalibratedValueInput_h

#include "ValueInput.h"
#include "CalibrationSettings.h"
#include "ThresholdsEventArgs.h"

class CalibratedValueInput : public ValueInput {
public:
  CalibratedValueInput(string name,
                       Thresholds thresholds,
                       CalibrationSettings* calibrationSettings);
  ~CalibratedValueInput();
  
  void setValue(float value);

  // Event
  static ofEvent<ThresholdsEventArgs> thresholdsCalibrated;

private:
  float getAverage();
  float getMaxAcceptedDistance(float average);
  void removeExcentric();
  float calculateOffset();
  void calibrateOffset(float offset);
  void addValueToBuffer(float value);
  void broadcastThresholdsCalibratedEvent();

  CalibrationSettings *settings;

  float *buffer;
  int index = 0;
  int stepCounter = 0;
  bool neverCalibrated = true;
};

#endif /* CalibratedValueInput_h */
