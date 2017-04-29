//
//  Thresholds.h
//  vela2017
//
//  Created by Nuno on 26/04/2017.
//
//

#ifndef Thresholds_h
#define Thresholds_h

#include "BlowIntensity.h"

class Thresholds {
  
public:
  Thresholds() : Thresholds(0,0,0,false) {}
  Thresholds(float _low, float _high, float _blowOut, bool _inverted);
  float getLow() {return low+offset;}
  float getHigh() {return high+offset;}
  float getBlowOut() {return blowOut+offset;}
  float getOffset() {return offset;}
  float setOffset(float _offset) {offset=_offset;}
  BlowIntensity getBlowIntensity(float value);

private:
  float offset=0;
  float low;
  float high;
  float blowOut;
  bool inverted;
};

#endif /* Thresholds_h */
