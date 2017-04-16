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

class ValueInput : public IDataInput {
public:
  ValueInput(string _name,
             float initialOffset,
             float lowThreshold,
             float highThreshold,
             float blowOutThreshold);

  // IDataInput
  virtual void update() {}
  virtual blowIntensityType getBlowIntensity();

  // ITrace
  virtual string getTrace();

  float getThreshold(blowIntensityType blowIntensity) {return threshold[blowIntensity-1];}
  void setValue(int _value);

private:
  string name;
  float threshold[3];
  float lastValue;
  
  void setThreshold(blowIntensityType blowIntensity, float value) {threshold[blowIntensity-1]=value;}
  
};

#endif /* AnalogInputSettings_h */
