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
  Thresholds() : Thresholds(0,0,0) {}
  Thresholds(float _low, float _high, float _blowOut, float _offset=0) {
    low = _low;
    high = _high;
    blowOut = _blowOut;
    offset = _offset;
  }
  
  float getLow() {return low+offset;}
  float getHigh() {return high+offset;}
  float getBlowOut() {return blowOut+offset;}
  float getOffset() {return offset;}
  float setOffset(float _offset) {offset=_offset;}

private:
  float low;
  float high;
  float blowOut;
  float offset;
};

#endif /* Thresholds_h */
