//
//  AnalogInput.cpp
//  vela2017
//
//  Created by Nuno on 09/04/2017.
//
//

#include "ValueInput.h"
#include "Util.h"
#include <sstream>

// the static event, or any static variable, must be initialized outside of the class definition.
ofEvent<NameFloatEventArgs> ValueInput::newValue = ofEvent<NameFloatEventArgs>();

//--------------------------------------------------------------
BlowIntensity ValueInput::getBlowIntensity() {
  
  if (!inverted) {
    if (lastValue < getThresholds()->getLow())
      return BlowIntensity::IDLE;

    else if (lastValue < getThresholds()->getHigh())
      return BlowIntensity::LOW;
  
    else if (lastValue < getThresholds()->getBlowOut())
      return BlowIntensity::HIGH;
  
    else
      return BlowIntensity::BLOWOUT;
    
  } else {
    if (lastValue > getThresholds()->getLow())
      return BlowIntensity::IDLE;
    
    else if (lastValue > getThresholds()->getHigh())
      return BlowIntensity::LOW;
    
    else if (lastValue > getThresholds()->getBlowOut())
      return BlowIntensity::HIGH;
    
    else
      return BlowIntensity::BLOWOUT;
  }
}

//--------------------------------------------------------------
void ValueInput::setValue(float value) {
  lastValue = value;
 
  broadcastNewValueEvent();
}

//--------------------------------------------------------------
void ValueInput::broadcastNewValueEvent() {
  NameFloatEventArgs evenArgs = NameFloatEventArgs(getName(), lastValue);
  ofNotifyEvent(newValue, evenArgs);
}

//--------------------------------------------------------------
string ValueInput::getTrace() {
  stringstream ss;
  
  ss << getName() << ": |";
  
  ss << roundf(getThresholds()->getOffset()*100)/100 << "| ";

  ss << roundf(getThresholds()->getLow()*100)/100 << "| ";
  ss << roundf(getThresholds()->getHigh()*100)/100 << "| ";
  ss << roundf(getThresholds()->getBlowOut()*100)/100 << "| ";

  ss << "value: " << roundf((lastValue)*100)/100 << " intensity: " << Util::blowIntensityToString(getBlowIntensity()) << "\n";
  
  return ss.str();
}
