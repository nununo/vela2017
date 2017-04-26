//
//  Thresholds.h
//  vela2017
//
//  Created by Nuno on 26/04/2017.
//
//

#ifndef Thresholds_h
#define Thresholds_h

class Thresholds {
  
public:
  Thresholds(float _zero, float _low, float _high, float _blowOut) {
    zero = _zero;
    low = _low;
    high = _high;
    blowOut = _blowOut;
  }
  float zero() {return zero;}
  float low() {return low;}
  float high() {return high;}
  float blowOut() {return blowOut;}
  
private:
  float zero=0;
  float low=0;
  float high=0;
  float blowOut=0;
};

#endif /* Thresholds_h */
