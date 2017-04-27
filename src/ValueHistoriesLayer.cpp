//
//  ValueHistoriesLayer.cpp
//  vela2017
//
//  Created by Nuno on 26/04/2017.
//
//

#include "ValueHistoriesLayer.h"
#include "CalibratedValueInput.h"
#include "ValueHistoryLayer.h"

//--------------------------------------------------------------
ValueHistoriesLayer::ValueHistoriesLayer(int bufferSize) {
  valueHistories = new ValueHistories(bufferSize);

  ofAddListener(ValueInput::newValue , this, &ValueHistoriesLayer::onNewValue);
  ofAddListener(CalibratedValueInput::thresholdsCalibrated , this, &ValueHistoriesLayer::onThresholdsCalibrated);
}

//--------------------------------------------------------------
ValueHistoriesLayer::~ValueHistoriesLayer() {
  ofRemoveListener(ValueInput::newValue, this, &ValueHistoriesLayer::onNewValue);
  ofRemoveListener(CalibratedValueInput::thresholdsCalibrated, this, &ValueHistoriesLayer::onThresholdsCalibrated);
  delete valueHistories;
  valueHistories=NULL;
}

//--------------------------------------------------------------
void ValueHistoriesLayer::onNewValue(NameFloatEventArgs &e) {
  valueHistories->addValue(e.getName(), e.getValue());
}

//--------------------------------------------------------------
void ValueHistoriesLayer::onThresholdsCalibrated(ThresholdsEventArgs &e) {
  valueHistories->setThresholds(e.getName(), e.getThresholds());
}

//--------------------------------------------------------------
void ValueHistoriesLayer::drawAlgorithm() {
  vector<string> keys = valueHistories->getKeys();
  
  int i=0;
  for ( auto it = keys.begin(); it != keys.end(); ++it ) {
    ValueHistoryLayer layer = ValueHistoryLayer(valueHistories->getHistory((*it)));
    layer.draw();
    i++;
  }
  
}
