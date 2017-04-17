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
#include "IDataInput.h"
#include "Calibration.h"

class ValueInput : public IDataInput {
public:
  ValueInput(string _name,
             float lowThreshold,
             float highThreshold,
             float blowOutThreshold,
             bool inverted,
             bool calibrated);

  // IDataInput
  virtual void update() {}
  virtual blowIntensityType getBlowIntensity();

  // ITrace
  virtual string getTrace();

  void setValue(int _value);

private:
  string name;
  float thresholdOffset[4];
  float lastValue;
  bool inverted;
  bool calibrated;
  Calibration calibration;
  
  float getThresholdOffset(blowIntensityType blowIntensity) {return thresholdOffset[blowIntensity];}
  void setThresholdOffset(blowIntensityType blowIntensity, float value) {thresholdOffset[blowIntensity]=value;}
  
};

#endif /* AnalogInputSettings_h */
