//
//  ValueHistory.h
//  vela2017
//
//  Created by Nuno on 26/04/2017.
//
//

#ifndef ValueHistory_h
#define ValueHistory_h

#include <deque>
#include "Thresholds.h"

#define VALUEHISTORY_DEFAULT_SIZE 100

class ValueHistory {
public:
  ValueHistory() {bufferSize = VALUEHISTORY_DEFAULT_SIZE;}
  void addValue(float value);
  void setThresholds(Thresholds _thresholds) {thresholds=_thresholds;}
  Thresholds getThresholds() {return thresholds;}
  std::deque<float> getValues() {return values;}

  static void setSize(int _bufferSize) {bufferSize=_bufferSize;}

private:
  static int bufferSize;
  Thresholds thresholds;
  std::deque<float> values;
};

#endif /* ValueHistory_h */
