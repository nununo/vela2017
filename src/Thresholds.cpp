//
//  Thresholds.cpp
//  vela2017
//
//  Created by Nuno on 29/04/2017.
//
//

#include "Thresholds.h"

//--------------------------------------------------------------
Thresholds::Thresholds(float _low, float _high, float _blowOut, bool _inverted) {
  inverted = _inverted;
  if (!inverted) {
    low = _low;
    high = _high;
    blowOut = _blowOut;
  } else {
    low = -_low;
    high = -_high;
    blowOut = -_blowOut;
  }
}

//--------------------------------------------------------------
BlowIntensity Thresholds::getBlowIntensity(float value) {
  
  if (!inverted) {
    if (value < getLow())
      return BlowIntensity::IDLE;
    
    else if (value < getHigh())
      return BlowIntensity::LOW;
    
    else if (value < getBlowOut())
      return BlowIntensity::HIGH;
    
    else
      return BlowIntensity::BLOWOUT;
    
  } else {
    if (value > getLow())
      return BlowIntensity::IDLE;
    
    else if (value > getHigh())
      return BlowIntensity::LOW;
    
    else if (value > getBlowOut())
      return BlowIntensity::HIGH;
    
    else
      return BlowIntensity::BLOWOUT;
    
  }
  
}
