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

class ValueHistory {
public:
  void addValue(float value);
  void setThresholds(Thresholds _thresholds) {thresholds=_thresholds;}
  Thresholds getThresholds() const {return thresholds;}
  std::deque<float> getValues() const {return values;}

private:
  Thresholds thresholds;
  std::deque<float> values;
};

#endif /* ValueHistory_h */
