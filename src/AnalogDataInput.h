//
//  AnalogInput.h
//  vela2017
//
//  Created by Nuno on 09/04/2017.
//
//

#ifndef AnalogDataInput_h
#define AnalogDataInput_h

#include "Constants.h"
#include "IDataInput.h"

class AnalogDataInput : public IDataInput {
public:
  AnalogDataInput(string _name,
                  float minValue,
                  float maxValue,
                  float lowThreshold,
                  float highThreshold,
                  float blowOutThreshold);

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
