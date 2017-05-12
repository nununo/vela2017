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

ValueInput::ValueInput(string name, Thresholds _thresholds): DataInput(name) {
  thresholds=_thresholds;
  lastValue=0;};

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

  ss << "value: " << roundf((lastValue)*100)/100 << " intensity: " << Util::blowIntensityToString(getBlowIntensity());
  
  return ss.str();
}
