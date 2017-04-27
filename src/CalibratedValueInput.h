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

class CalibratedValueInput : public ThresholdsDataInput {
public:
  CalibratedValueInput(string name,
                       Thresholds thresholds,
                       bool inverted,
                       CalibrationSettings* calibrationSettings=NULL);
  ~CalibratedValueInput() {
    delete valueInput;
    valueInput=NULL;
    delete [] history;
    history=NULL;
  }

  // DataInput
  virtual void update() {valueInput->update();}
  virtual blowIntensityType getBlowIntensity() {return valueInput->getBlowIntensity();}
  
  // ITrace
  virtual string getTrace() {return valueInput->getTrace();}
  
  // ThresholdDataInput
  virtual void setValue(float value);
  virtual Thresholds* const getThresholds() {return valueInput->getThresholds();};
  
private:
  float getAverage();
  float getMaxAcceptedDistance(float average);
  void removeExcentric();
  void calcOffset();
  void sampleValue(float value);

  ValueInput *valueInput;
  CalibrationSettings *settings;

  float *history;
  
  int index = 0;
  int stepCounter = 0;
};

#endif /* CalibratedValueInput_h */
