//
//  AnalogInput.h
//  vela2017
//
//  Created by Nuno on 09/04/2017.
//
//

#ifndef AnalogInput_h
#define AnalogInput_h

#include "Constants.h"
#include "IDataInput.h"

class AnalogInput : public IDataInput {
public:
  AnalogInput(string _name,
              float minValue,
              float lowThreshold,
              float highThreshold,
              float blowOutThreshold,
              float maxValue);

  // IDataInput
  virtual void update() {}
  virtual blowIntensityType getBlowIntensity();

  // ITrace
  virtual string getTrace();

  float getThreshold(blowIntensityType blowIntensity) {return threshold[blowIntensity];}
  void setValue(int _value);

private:
  string name;
  float threshold[5];
  float lastValue;
  
};

#endif /* AnalogInputSettings_h */
