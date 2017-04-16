#ifndef UTIL_H_INCLUDED
#define UTIL_H_INCLUDED

#include "Constants.h"
#include "ofMain.h"

class Util {
public:
  static float remap(float v, float inMin, float inMax, float outMin, float outMax);
  static string blowIntensityToString(blowIntensityType blowIntensity);
  static bool stringToBool(string str);
};

#endif // UTIL_H_INCLUDED
