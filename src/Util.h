//
//  Util.h
//  vela2017
//
//  Created by Nuno on 31/03/2017.
//
//

#ifndef UTIL_H_INCLUDED
#define UTIL_H_INCLUDED

#include "BlowIntensity.h"
#include "ofMain.h"

class Util {
public:
  static float remap(const float v, const float inMin, const float inMax, const float outMin, const float outMax);
  static string blowIntensityToString(const BlowIntensity blowIntensity);
};

#endif // UTIL_H_INCLUDED
