//
//  Calibration.h
//  vela2017
//
//  Created by Nuno on 16/04/2017.
//
//

#ifndef Calibration_h
#define Calibration_h

#include "CalibrationSettings.h"
#include "ITrace.h"

class Calibration : ITrace {
public:
  Calibration(CalibrationSettings *_settings);
  ~Calibration() { delete [] history;}
  float getOffset(float value);
  
  std::string getTrace();

private:
  CalibrationSettings *settings;
  
  float *history;
  
  int index = 0;
  float lastCalibratedZero = 0;
  int stepCounter = 0;
  
  float getAverage();
  float getMaxAcceptedDistance(float average);
  void removeExcentric();
  void calcCalibratedZero();
  bool isSamplingTime();
  bool isCalibrationTime();
};
#endif /* Calibration_h */
