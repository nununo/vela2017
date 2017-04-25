//
//  AnalogInput.h
//  vela2017
//
//  Created by Nuno on 09/04/2017.
//
//

#ifndef ValueInput_h
#define ValueInput_h

#include "Constants.h"
#include "DataInput.h"
#include "Calibration.h"

class ValueInput : public DataInput {
public:
  ValueInput(string name,
             float lowThreshold,
             float highThreshold,
             float blowOutThreshold,
             bool inverted,
             CalibrationSettings* calibrationSettings=NULL);

  // DataInput
  virtual void update() {}
  virtual blowIntensityType getBlowIntensity();

  // ITrace
  virtual string getTrace();

  void setValue(int _value);

private:
  float thresholdOffset[4];
  float lastValue;
  bool inverted;
  Calibration *calibration=NULL;
  
  float getThresholdOffset(blowIntensityType blowIntensity) {return thresholdOffset[blowIntensity];}
  void setThresholdOffset(blowIntensityType blowIntensity, float value) {thresholdOffset[blowIntensity]=value;}
  
};

#endif /* AnalogInputSettings_h */
