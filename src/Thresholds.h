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
#include "ThresholdsSettings.h"

class Thresholds {
  
public:
  Thresholds() {}
  Thresholds(ThresholdsSettings _settings) {settings=_settings;}
  float getLow() {return settings.getLow()+offset;}
  float getHigh() {return settings.getHigh()+offset;}
  float getBlowOut() {return settings.getBlowOut()+offset;}
  float getOffset() {return offset;}
  void setOffset(float _offset) {offset=_offset;}
  BlowIntensity getBlowIntensity(float value);
  bool isInverted() {return settings.isInverted();}

private:
  float offset=0;
  ThresholdsSettings settings;
};

#endif /* Thresholds_h */
