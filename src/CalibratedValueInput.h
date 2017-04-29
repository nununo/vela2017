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

class CalibratedValueInput : public ThresholdsDataInput {
public:
  CalibratedValueInput(string name,
                       Thresholds thresholds,
                       CalibrationSettings* calibrationSettings);
  ~CalibratedValueInput() {
    delete valueInput;
    valueInput=NULL;
    delete [] buffer;
    buffer=NULL;
  }

  // DataInput
  virtual void update() {valueInput->update();}
  virtual BlowIntensity getBlowIntensity() {return valueInput->getBlowIntensity();}
  
  // ITrace
  virtual string getTrace() {return valueInput->getTrace();}
  
  // ThresholdDataInput
  virtual void setValue(float value);
  virtual Thresholds* const getThresholds() {return valueInput->getThresholds();};

  // Event
  static ofEvent<ThresholdsEventArgs> thresholdsCalibrated;

private:
  float getAverage();
  float getMaxAcceptedDistance(float average);
  void removeExcentric();
  void calibrateOffset();
  void sampleValue(float value);
  void broadcastThresholdsCalibratedEvent();

  ValueInput *valueInput;
  CalibrationSettings *settings;

  float *buffer;
  
  int index = 0;
  int stepCounter = 0;
};

#endif /* CalibratedValueInput_h */
