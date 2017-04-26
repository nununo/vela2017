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

class CalibratedValueInput : public DataInput {
public:
  CalibratedValueInput(string name,
                       Thresholds thresholds,
                       bool inverted,
                       CalibrationSettings* calibrationSettings=NULL);
  ~CalibratedValueInput() { delete [] history;}

  // DataInput
  virtual void update() {valueInput->update();}
  virtual blowIntensityType getBlowIntensity() {return valueInput->getBlowIntensity();}
  
  // ITrace
  virtual string getTrace() {return valueInput->getTrace();}
  
  void setValue(float value);
  
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
