//
//  Util.cpp
//  vela2017
//
//  Created by Nuno on 31/03/2017.
//
//

#include "Util.h"

//--------------------------------------------------------------
float Util::remap(const float v, const float inMin, const float inMax, const float outMin, const float outMax) {
  float aux =  1 - ((inMax - v) / (inMax - inMin));
  if (aux < 0)
    aux = 0;
  else if (aux > 1)
    aux = 1;
  return outMin + (outMax-outMin)* aux;
}

//--------------------------------------------------------------
string Util::blowIntensityToString(const blowIntensityType blowIntensity) {
  switch (blowIntensity) {
    case BLOW_INTENSITY_IDLE:
      return "idle";
      break;
    case BLOW_INTENSITY_LOW:
      return "low";
      break;
    case BLOW_INTENSITY_HIGH:
      return "high";
      break;
    case BLOW_INTENSITY_BLOWOUT:
      return "blowOut";
      break;
    default:
      return "invalidIntensity";
      break;
  }
}

//--------------------------------------------------------------
bool Util::stringToBool(const string str) {
  return (str=="1" || str=="enabled" || str=="active" || str=="true" );
}
