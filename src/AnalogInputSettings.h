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
  AnalogInputSettings(float minValue,
                      float lowThreshold,
                      float highThreshold,
                      float blowOutThreshold,
                      float maxValue) {
    threshold[BLOW_INTENSITY_MIN] = minValue;
    threshold[BLOW_INTENSITY_LOW] = lowThreshold;
    threshold[BLOW_INTENSITY_HIGH] = highThreshold;
    threshold[BLOW_INTENSITY_BLOWOUT] = blowOutThreshold;
    threshold[BLOW_INTENSITY_MAX] = maxValue;
  }
  float getThreshold(blowIntensityType blowIntensity) {return threshold[blowIntensity];}
  blowIntensityType getBlowIntensity(float value);
  
  // ITrace
  virtual string getTrace();

private:
  float threshold[5];
  
};

#endif /* AnalogInputSettings_h */
