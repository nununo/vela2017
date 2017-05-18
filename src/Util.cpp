//
//  Util.cpp
//  vela2017
//
//  Created by Nuno on 31/03/2017.
//
//

#include "Util.h"

//--------------------------------------------------------------
std::string Util::blowIntensityToString(const BlowIntensity blowIntensity) {
  switch (blowIntensity) {
    case BlowIntensity::IDLE:
      return "idle";
      break;
    case BlowIntensity::LOW:
      return "low";
      break;
    case BlowIntensity::HIGH:
      return "high";
      break;
    case BlowIntensity::BLOWOUT:
      return "blowOut";
      break;
    default:
      return "invalidIntensity";
      break;
  }
}
