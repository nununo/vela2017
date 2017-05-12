//
//  Thresholds.cpp
//  vela2017
//
//  Created by Nuno on 29/04/2017.
//
//

#include "Thresholds.h"

//--------------------------------------------------------------
BlowIntensity Thresholds::getBlowIntensity(float value) {
  
  if (!isInverted()) {
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
