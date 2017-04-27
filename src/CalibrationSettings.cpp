//
//  CalibrationSettings.cpp
//  vela2017
//
//  Created by Nuno on 22/04/2017.
//
//

#include "CalibrationSettings.h"
#include <sstream>

std::string CalibrationSettings::getTrace() {
  std::stringstream ss;
  ss  << " (" << getBufferSize() << "," << getExcentricSize() << "," << getSkipSize() << ") ";
  return ss.str();
}
