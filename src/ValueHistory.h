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

#define VALUEHISTORY_DEFAULT_SIZE 100

class ValueHistory {
public:
  ValueHistory() {bufferSize = VALUEHISTORY_DEFAULT_SIZE;}
  void addValue(float value);
  std::deque<float> getValues() {return values;}

  static void setSize(int _bufferSize) {bufferSize=_bufferSize;}

private:
  static int bufferSize;
  std::deque<float> values;
};

#endif /* ValueHistory_h */
