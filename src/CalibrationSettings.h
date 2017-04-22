//
//  CalibrationSettings.h
//  vela2017
//
//  Created by Nuno on 17/04/2017.
//
//

#ifndef CalibrationSettings_h
#define CalibrationSettings_h

class CalibrationSettings {
public:
  CalibrationSettings(int _historySize, int _excentricSize, int _skipSize) {
    historySize = _historySize;
    excentricSize = _excentricSize;
    skipSize = _skipSize;
  }
  int getHistorySize() {return historySize;}
  int getExcentricSize() {return excentricSize;}
  int getSkipSize() {return skipSize;}

private:
  int historySize;
  int excentricSize;
  int skipSize;
};
#endif /* CalibrationSettings_h */
