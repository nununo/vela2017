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
                       float initialOffset,
                       float lowThreshold,
                       float highThreshold,
                       float blowOutThreshold) {
  name = _name;
  setThreshold(BLOW_INTENSITY_LOW, lowThreshold);
  setThreshold(BLOW_INTENSITY_HIGH, highThreshold);
  setThreshold(BLOW_INTENSITY_BLOWOUT, blowOutThreshold);
  lastValue = 0;
}

//--------------------------------------------------------------
blowIntensityType ValueInput::getBlowIntensity() {
  
  if (lastValue < getThreshold(BLOW_INTENSITY_LOW))
    return BLOW_INTENSITY_IDLE;

  else if (lastValue < getThreshold(BLOW_INTENSITY_HIGH))
    return BLOW_INTENSITY_LOW;
  
  else if (lastValue < getThreshold(BLOW_INTENSITY_BLOWOUT))
    return BLOW_INTENSITY_HIGH;
  
  else
    return BLOW_INTENSITY_BLOWOUT;
}

//--------------------------------------------------------------
void ValueInput::setValue(int value) {
  lastValue = value;
}

//--------------------------------------------------------------
string ValueInput::getTrace() {
  stringstream ss;
  
  ss << name << ": |";
  
  for(int i=1; i<4;i++)
    ss << roundf(getThreshold((blowIntensityType)i)*100)/100 << "| ";
  
  ss << "last: " << lastValue << "\n";
  
  return ss.str();
}
