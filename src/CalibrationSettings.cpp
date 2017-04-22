//
//  CalibrationSettings.cpp
//  vela2017
//
//  Created by Nuno on 22/04/2017.
//
//

#include "CalibrationSettings.h"
#include <sstream>
using namespace std;

string CalibrationSettings::getTrace() {
  stringstream ss;
  ss  << " (" << getHistorySize() << "," << getExcentricSize() << "," << getSkipSize() << ") ";
  return ss.str();
}
