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
using namespace std;

// the static event, or any static variable, must be initialized outside of the class definition.
ofEvent<NameFloatEventArgs> ValueInput::newValue = ofEvent<NameFloatEventArgs>();

//--------------------------------------------------------------
ValueInput::ValueInput(string name,
                       float lowThreshold,
                       float highThreshold,
                       float blowOutThreshold,
                       bool _inverted,
                       CalibrationSettings* calibrationSettings) : DataInput(name) {
  inverted = _inverted;
  
  if (calibrationSettings)
    calibration = new Calibration(calibrationSettings);

  setThresholdOffset(BLOW_INTENSITY_IDLE, 0);
  setThresholdOffset(BLOW_INTENSITY_LOW, (inverted?-lowThreshold:lowThreshold));
  setThresholdOffset(BLOW_INTENSITY_HIGH, (inverted?-highThreshold:highThreshold));
  setThresholdOffset(BLOW_INTENSITY_BLOWOUT, (inverted?-blowOutThreshold:blowOutThreshold));
  
  lastValue = 0;
}

//--------------------------------------------------------------
blowIntensityType ValueInput::getBlowIntensity() {
  
  if (!inverted) {
    if (lastValue < getThresholdOffset(BLOW_INTENSITY_IDLE) + getThresholdOffset(BLOW_INTENSITY_LOW))
      return BLOW_INTENSITY_IDLE;

    else if (lastValue < getThresholdOffset(BLOW_INTENSITY_IDLE) + getThresholdOffset(BLOW_INTENSITY_HIGH))
      return BLOW_INTENSITY_LOW;
  
    else if (lastValue < getThresholdOffset(BLOW_INTENSITY_IDLE) + getThresholdOffset(BLOW_INTENSITY_BLOWOUT))
      return BLOW_INTENSITY_HIGH;
  
    else
      return BLOW_INTENSITY_BLOWOUT;
    
  } else {
    if (lastValue > getThresholdOffset(BLOW_INTENSITY_IDLE) + getThresholdOffset(BLOW_INTENSITY_LOW))
      return BLOW_INTENSITY_IDLE;
    
    else if (lastValue > getThresholdOffset(BLOW_INTENSITY_IDLE) + getThresholdOffset(BLOW_INTENSITY_HIGH))
      return BLOW_INTENSITY_LOW;
    
    else if (lastValue > getThresholdOffset(BLOW_INTENSITY_IDLE) + getThresholdOffset(BLOW_INTENSITY_BLOWOUT))
      return BLOW_INTENSITY_HIGH;
    
    else
      return BLOW_INTENSITY_BLOWOUT;
  }
}

//--------------------------------------------------------------
void ValueInput::setValue(int value) {
  lastValue = value;
  
  if (calibration)
    setThresholdOffset(BLOW_INTENSITY_IDLE, calibration->getOffset(value));
  
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
  
  ss << roundf((getThresholdOffset(BLOW_INTENSITY_IDLE))*100)/100 << "| ";

  for(int i=1; i<4;i++)
    ss << roundf((getThresholdOffset(BLOW_INTENSITY_IDLE) + getThresholdOffset((blowIntensityType)i))*100)/100 << "| ";

  if (calibration)
    ss << calibration->getTrace() << " ";

  ss << "value: " << roundf((lastValue)*100)/100 << " intensity: " << Util::blowIntensityToString(getBlowIntensity()) << "\n";
  
  return ss.str();
}
