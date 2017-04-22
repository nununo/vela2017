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

//--------------------------------------------------------------
ValueInput::ValueInput(string _name,
                       float lowThreshold,
                       float highThreshold,
                       float blowOutThreshold,
                       bool _inverted,
                       CalibrationSettings* calibrationSettings) {
  name = _name;
  inverted = _inverted;
  
  if (calibrationSettings)
    calibration = new Calibration(calibrationSettings);

  setThresholdOffset(BLOW_INTENSITY_IDLE, 0);
  setThresholdOffset(BLOW_INTENSITY_LOW, lowThreshold);
  setThresholdOffset(BLOW_INTENSITY_HIGH, highThreshold);
  setThresholdOffset(BLOW_INTENSITY_BLOWOUT, blowOutThreshold);
  
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
}

//--------------------------------------------------------------
string ValueInput::getTrace() {
  stringstream ss;
  
  ss << name << ": |";
  
  ss << roundf((getThresholdOffset(BLOW_INTENSITY_IDLE))*100)/100 << "| ";

  for(int i=1; i<4;i++)
    ss << roundf((getThresholdOffset(BLOW_INTENSITY_IDLE) + getThresholdOffset((blowIntensityType)i))*100)/100 << "| ";

  if (calibration)
    ss << calibration->getTrace() << " ";

  ss << "value: " << roundf((lastValue)*100)/100 << " intensity: " << Util::blowIntensityToString(getBlowIntensity()) << "\n";
  
  return ss.str();
}
