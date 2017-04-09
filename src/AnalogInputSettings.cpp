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
  
  ss << "Thresholds: |";
  
  for(int i=0; i<5;i++)
    ss << roundf(getThreshold((blowIntensityType)i)*100)/100 << "|";
  
  ss << "\n";
  
  return ss.str();
}
