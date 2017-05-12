//
//  ThresholdsSettings.cpp
//  vela2017
//
//  Created by Nuno on 12/05/2017.
//
//

#include "ThresholdsSettings.h"

//--------------------------------------------------------------
ThresholdsSettings::ThresholdsSettings(float _low, float _high, float _blowOut, bool _inverted) {
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

