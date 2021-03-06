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
string Util::blowIntensityToString(const BlowIntensity blowIntensity) {
  switch (blowIntensity) {
    case BlowIntensity::IDLE:
      return "idle";
      break;
    case BlowIntensity::LOW:
      return "low";
      break;
    case BlowIntensity::HIGH:
      return "high";
      break;
    case BlowIntensity::BLOWOUT:
      return "blowOut";
      break;
    default:
      return "invalidIntensity";
      break;
  }
}
/*
//--------------------------------------------------------------
int Util::blowIntensityToInt(const BlowIntensity blowIntensity) {
  switch (blowIntensity) {
    case BlowIntensity::IDLE:
      return 0;
      break;
    case BlowIntensity::LOW:
      return 1;
      break;
    case BlowIntensity::HIGH:
      return 2;
      break;
    case BlowIntensity::BLOWOUT:
      return "blowOut";
      break;
    default:
      return "invalidIntensity";
      break;
  }
}
*/
//--------------------------------------------------------------
bool Util::stringToBool(const string str) {
  return (str=="1" || str=="enabled" || str=="active" || str=="true" );
}
