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
#include "ThresholdsEventArgs.h"
#include "NameFloatEventArgs.h"

class ValueHistories {
public:
  ValueHistories();
  ~ValueHistories();
  void addValue(std::string name, float value) {getHistory(name)->addValue(value);}
  void setThresholds(std::string name, Thresholds thresholds) {getHistory(name)->setThresholds(thresholds);}
  ValueHistory* getHistory(std::string name) {return &histories[name];}
  std::vector<std::string> getKeys();

private:
  void onNewThresholds(ThresholdsEventArgs &e);
  void onNewValue(NameFloatEventArgs &e);

  std::unordered_map<std::string, ValueHistory> histories;
};

#endif /* ValueHistories_h */
