#include "Util.h"

//--------------------------------------------------------------
float Util::remap(float v, float inMin, float inMax, float outMin, float outMax) {
  float aux =  1 - ((inMax - v) / (inMax - inMin));
  if (aux < 0)
    aux = 0;
  else if (aux > 1)
    aux = 1;
  return outMin + (outMax-outMin)* aux;
}

//--------------------------------------------------------------
string Util::blowIntensityToString(blowIntensityType blowIntensity) {
  switch (blowIntensity) {
    case BLOW_INTENSITY_MIN:
      return "min";
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
    case BLOW_INTENSITY_MAX:
      return "max";
      break;
    default:
      return "invalidIntensity";
      break;
  }
}
