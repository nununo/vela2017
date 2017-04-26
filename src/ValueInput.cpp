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
ValueInput::ValueInput(string name,
                       Thresholds _thresholds,
                       bool _inverted) : DataInput(name) {
  inverted = _inverted;

  thresholds = _thresholds;
  
  lastValue = 0;
}

//--------------------------------------------------------------
blowIntensityType ValueInput::getBlowIntensity() {
  
  if (!inverted) {
    if (lastValue < thresholds.getLow())
      return BLOW_INTENSITY_IDLE;

    else if (lastValue < thresholds.getHigh())
      return BLOW_INTENSITY_LOW;
  
    else if (lastValue < thresholds.getBlowOut())
      return BLOW_INTENSITY_HIGH;
  
    else
      return BLOW_INTENSITY_BLOWOUT;
    
  } else {
    if (lastValue > thresholds.getLow())
      return BLOW_INTENSITY_IDLE;
    
    else if (lastValue > thresholds.getHigh())
      return BLOW_INTENSITY_LOW;
    
    else if (lastValue > thresholds.getBlowOut())
      return BLOW_INTENSITY_HIGH;
    
    else
      return BLOW_INTENSITY_BLOWOUT;
  }
}

//--------------------------------------------------------------
void ValueInput::setValue(int value) {
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
  
  ss << roundf(thresholds.getOffset()*100)/100 << "| ";

  ss << roundf(thresholds.getLow()*100)/100 << "| ";
  ss << roundf(thresholds.getHigh()*100)/100 << "| ";
  ss << roundf(thresholds.getBlowOut()*100)/100 << "| ";

  ss << "value: " << roundf((lastValue)*100)/100 << " intensity: " << Util::blowIntensityToString(getBlowIntensity()) << "\n";
  
  return ss.str();
}
