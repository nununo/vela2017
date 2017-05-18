//
//  ValueHistories.cpp
//  vela2017
//
//  Created by Nuno on 26/04/2017.
//
//

#include "ValueHistories.h"
#include "ValueInput.h"

//--------------------------------------------------------------
ValueHistories::ValueHistories() {
  ofAddListener(ValueInput::newValue , this, &ValueHistories::onNewValue);
  ofAddListener(ValueInput::newThresholds , this, &ValueHistories::onNewThresholds);
}

//--------------------------------------------------------------
ValueHistories::~ValueHistories() {
  ofRemoveListener(ValueInput::newThresholds, this, &ValueHistories::onNewThresholds);
  ofRemoveListener(ValueInput::newValue, this, &ValueHistories::onNewValue);
}

//--------------------------------------------------------------
std::vector<std::string> ValueHistories::getKeys() {
  std::vector<std::string> v;
  
  for ( auto it = histories.begin(); it != histories.end(); ++it )
    v.push_back(it->first);
  
  return v;
}

//--------------------------------------------------------------
void ValueHistories::onNewThresholds(ThresholdsEventArgs &e) {
  setThresholds(e.getName(), e.getThresholds());
}

//--------------------------------------------------------------
void ValueHistories::onNewValue(NameFloatEventArgs &e) {
  addValue(e.getName(), e.getValue());
}
