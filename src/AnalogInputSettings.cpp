//
//  AnalogInputSettings.cpp
//  vela2017
//
//  Created by Nuno on 09/04/2017.
//
//

#include "AnalogInputSettings.h"
#include <sstream>
using namespace std;
#include "ofMain.h"

//--------------------------------------------------------------
AnalogInputSettings::AnalogInputSettings(string _name,
                                         float minValue,
                                         float lowThreshold,
                                         float highThreshold,
                                         float blowOutThreshold,
                                         float maxValue) {
  name = _name;
  threshold[BLOW_INTENSITY_MIN] = minValue;
  threshold[BLOW_INTENSITY_LOW] = lowThreshold;
  threshold[BLOW_INTENSITY_HIGH] = highThreshold;
  threshold[BLOW_INTENSITY_BLOWOUT] = blowOutThreshold;
  threshold[BLOW_INTENSITY_MAX] = maxValue;
}

//--------------------------------------------------------------
blowIntensityType AnalogInputSettings::getBlowIntensity(float value) {
  if (value < getThreshold(BLOW_INTENSITY_LOW))
    return BLOW_INTENSITY_MIN;

  else if (value < getThreshold(BLOW_INTENSITY_HIGH))
    return BLOW_INTENSITY_LOW;
  
  else if (value < getThreshold(BLOW_INTENSITY_BLOWOUT))
    return BLOW_INTENSITY_HIGH;
  
  else
    return BLOW_INTENSITY_BLOWOUT;
}

//--------------------------------------------------------------
string AnalogInputSettings::getTrace() {
  stringstream ss;
  
  ss << name << ": |";
  
  for(int i=0; i<5;i++)
    ss << roundf(getThreshold((blowIntensityType)i)*100)/100 << "| ";
  
  return ss.str();
}
