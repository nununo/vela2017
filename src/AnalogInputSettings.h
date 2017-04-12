//
//  AnalogInputSettings.h
//  vela2017
//
//  Created by Nuno on 09/04/2017.
//
//

#ifndef AnalogInputSettings_h
#define AnalogInputSettings_h

#include "Constants.h"
#include "ITrace.h"

class AnalogInputSettings : public ITrace {
public:
  AnalogInputSettings(string _name,
                      float minValue,
                      float lowThreshold,
                      float highThreshold,
                      float blowOutThreshold,
                      float maxValue);
  float getThreshold(blowIntensityType blowIntensity) {return threshold[blowIntensity];}
  blowIntensityType getBlowIntensity(float value);
  
  // ITrace
  virtual string getTrace();

private:
  string name;
  float threshold[5];
  
};

#endif /* AnalogInputSettings_h */
