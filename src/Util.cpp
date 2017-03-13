#include "Util.h"

float Util::remap(float v, float inMin, float inMax, float outMin, float outMax) {
  float aux =  1 - ((inMax - v) / (inMax - inMin));
  if (aux < 0)
    aux = 0;
  else if (aux > 1)
    aux = 1;
  return outMin + (outMax-outMin)* aux;
}

