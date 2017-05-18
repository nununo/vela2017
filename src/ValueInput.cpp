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
ofFastEvent<NameFloatEventArgs> ValueInput::newValue = ofFastEvent<NameFloatEventArgs>();
ofFastEvent<ThresholdsEventArgs> ValueInput::newThresholds = ofFastEvent<ThresholdsEventArgs>();

//--------------------------------------------------------------
ValueInput::ValueInput(string name, ThresholdsSettings thresholdsSettings): DataInput(name) {
  thresholds=Thresholds(thresholdsSettings);
  lastValue=0;
  broadcastNewThresholdsEvent();
  broadcastNewValueEvent();
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
void ValueInput::broadcastNewThresholdsEvent() {
  ThresholdsEventArgs evenArgs = ThresholdsEventArgs(getName(), *getThresholds());
  ofNotifyEvent(newThresholds, evenArgs);
}

//--------------------------------------------------------------
string ValueInput::getTrace() {
  stringstream ss;
  
  ss << getName();
 
  if (getThresholds()->isInverted())
    ss << " inverted";
  
  ss << ": |";
  
  ss << roundf(getThresholds()->getOffset()*100)/100 << "| ";

  ss << roundf(getThresholds()->getLow()*100)/100 << "| ";
  ss << roundf(getThresholds()->getHigh()*100)/100 << "| ";
  ss << roundf(getThresholds()->getBlowOut()*100)/100 << "| ";

  ss << "value: " << roundf((lastValue)*100)/100 << " intensity: " << Util::blowIntensityToString(getBlowIntensity());
  
  return ss.str();
}
