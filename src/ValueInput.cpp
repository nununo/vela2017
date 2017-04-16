//
//  AnalogInput.cpp
//  vela2017
//
//  Created by Nuno on 09/04/2017.
//
//

#include "ValueInput.h"
#include "ofMain.h"
#include "Util.h"
#include <sstream>
using namespace std;

//--------------------------------------------------------------
ValueInput::ValueInput(string _name,
                       float _offset,
                       float lowThreshold,
                       float highThreshold,
                       float blowOutThreshold,
                       bool _inverted) {
  name = _name;
  offset = _offset;
  inverted = _inverted;

  setThresholdOffset(BLOW_INTENSITY_IDLE, 0);
  setThresholdOffset(BLOW_INTENSITY_LOW, lowThreshold-offset);
  setThresholdOffset(BLOW_INTENSITY_HIGH, highThreshold-offset);
  setThresholdOffset(BLOW_INTENSITY_BLOWOUT, blowOutThreshold-offset);
  
  lastValue = _offset;
}

//--------------------------------------------------------------
blowIntensityType ValueInput::getBlowIntensity() {
  
  if (!inverted) {
    if (lastValue < offset + getThresholdOffset(BLOW_INTENSITY_LOW))
      return BLOW_INTENSITY_IDLE;

    else if (lastValue < offset + getThresholdOffset(BLOW_INTENSITY_HIGH))
      return BLOW_INTENSITY_LOW;
  
    else if (lastValue < offset + getThresholdOffset(BLOW_INTENSITY_BLOWOUT))
      return BLOW_INTENSITY_HIGH;
  
    else
      return BLOW_INTENSITY_BLOWOUT;
    
  } else {
    if (lastValue > offset + getThresholdOffset(BLOW_INTENSITY_LOW))
      return BLOW_INTENSITY_IDLE;
    
    else if (lastValue > offset + getThresholdOffset(BLOW_INTENSITY_HIGH))
      return BLOW_INTENSITY_LOW;
    
    else if (lastValue > offset + getThresholdOffset(BLOW_INTENSITY_BLOWOUT))
      return BLOW_INTENSITY_HIGH;
    
    else
      return BLOW_INTENSITY_BLOWOUT;
  }
}

//--------------------------------------------------------------
void ValueInput::setValue(int value) {
  lastValue = value;
}

//--------------------------------------------------------------
string ValueInput::getTrace() {
  stringstream ss;
  
  ss << name << ": |";
  
  for(int i=0; i<4;i++)
    ss << roundf(getThresholdOffset((blowIntensityType)i)*100)/100 << "| ";
  
  ss << "value: " << lastValue << " intensity: " << Util::blowIntensityToString(getBlowIntensity()) << "\n";
  
  return ss.str();
}
