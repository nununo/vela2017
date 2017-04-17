//
//  Calibration.h
//  vela2017
//
//  Created by Nuno on 16/04/2017.
//
//

#ifndef Calibration_h
#define Calibration_h

#define CALIBRATION_HISTORY_SIZE 25
#define CALIBRATION_EXCENTRIC_SIZE 5
#define CALIBRATION_STEP_SIZE 10

class Calibration {
public:
  float getOffset(float value);

private:
  float history[CALIBRATION_HISTORY_SIZE];
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
