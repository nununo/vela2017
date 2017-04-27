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
  CalibrationSettings(int _bufferSize, int _excentricSize, int _skipSize) {
    bufferSize = _bufferSize;
    excentricSize = _excentricSize;
    skipSize = _skipSize;
  }
  int getBufferSize() {return bufferSize;}
  int getExcentricSize() {return excentricSize;}
  int getSkipSize() {return skipSize;}
  
  std::string getTrace();

private:
  int bufferSize;
  int excentricSize;
  int skipSize;
};
#endif /* CalibrationSettings_h */
