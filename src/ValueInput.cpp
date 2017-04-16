//
//  AnalogInput.cpp
//  vela2017
//
//  Created by Nuno on 09/04/2017.
//
//

#include "ValueInput.h"
#include <sstream>
using namespace std;
#include "ofMain.h"

//--------------------------------------------------------------
ValueInput::ValueInput(string _name,
                       float minValue,
                       float maxValue,
                       float lowThreshold,
                       float highThreshold,
                       float blowOutThreshold) {
  name = _name;
  threshold[BLOW_INTENSITY_MIN] = minValue;
  threshold[BLOW_INTENSITY_LOW] = lowThreshold;
  threshold[BLOW_INTENSITY_HIGH] = highThreshold;
  threshold[BLOW_INTENSITY_BLOWOUT] = blowOutThreshold;
  threshold[BLOW_INTENSITY_MAX] = maxValue;
  lastValue = minValue;
}

//--------------------------------------------------------------
blowIntensityType ValueInput::getBlowIntensity() {
  
  if (lastValue < getThreshold(BLOW_INTENSITY_LOW))
    return BLOW_INTENSITY_MIN;

  else if (lastValue < getThreshold(BLOW_INTENSITY_HIGH))
    return BLOW_INTENSITY_LOW;
  
  else if (lastValue < getThreshold(BLOW_INTENSITY_BLOWOUT))
    return BLOW_INTENSITY_HIGH;
  
  else
    return BLOW_INTENSITY_BLOWOUT;
}

//--------------------------------------------------------------
void ValueInput::setValue(int value) {
  
  if (value < threshold[BLOW_INTENSITY_MIN] ||
      value > threshold[BLOW_INTENSITY_MAX] )
    return;
  
  lastValue = value;
}

//--------------------------------------------------------------
string ValueInput::getTrace() {
  stringstream ss;
  
  ss << name << ": |";
  
  for(int i=0; i<5;i++)
    ss << roundf(getThreshold((blowIntensityType)i)*100)/100 << "| ";
  
  ss << "last: " << lastValue << "\n";
  
  return ss.str();
}
