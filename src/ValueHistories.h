//
//  ValueHistories.h
//  vela2017
//
//  Created by Nuno on 26/04/2017.
//
//

#ifndef ValueHistories_h
#define ValueHistories_h

#include <string>
#include <unordered_map>
#include <vector>
#include "ValueHistory.h"

class ValueHistories {
public:
  ValueHistories(int bufferSize) {ValueHistory::setSize(bufferSize);}
  void addValue(std::string name, float value) {getHistory(name)->addValue(value);}
  ValueHistory* getHistory(std::string name) {return &histories[name];}
  std::vector<std::string> getKeys();

private:
  std::unordered_map<std::string, ValueHistory> histories;
};

#endif /* ValueHistories_h */
