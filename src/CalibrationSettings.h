//
//  CalibrationSettings.h
//  vela2017
//
//  Created by Nuno on 17/04/2017.
//
//

#ifndef CalibrationSettings_h
#define CalibrationSettings_h

#include "ITrace.h"

class CalibrationSettings : ITrace {
public:
  CalibrationSettings() : CalibrationSettings(0,0,0) {}
  CalibrationSettings(int _bufferSize, int _excentricSize, int _samplePeriod) {
    bufferSize = _bufferSize;
    excentricSize = _excentricSize;
    samplePeriod = _samplePeriod;
  }
  int getBufferSize() {return bufferSize;}
  int getExcentricSize() {return excentricSize;}
  int getSamplePeriod() {return samplePeriod;}
  
  std::string getTrace();

private:
  int bufferSize;
  int excentricSize;
  int samplePeriod;
};
#endif /* CalibrationSettings_h */
