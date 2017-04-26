//
//  ValueHistoriesLayer.cpp
//  vela2017
//
//  Created by Nuno on 26/04/2017.
//
//

#include "ValueHistoriesLayer.h"
#include "ValueInput.h"
#include "ValueHistoryLayer.h"

//--------------------------------------------------------------
ValueHistoriesLayer::ValueHistoriesLayer(int bufferSize) {
  valueHistories = new ValueHistories(bufferSize);

  ofAddListener(ValueInput::newValue , this, &ValueHistoriesLayer::onNewValue);
}

//--------------------------------------------------------------
ValueHistoriesLayer::~ValueHistoriesLayer() {
  ofRemoveListener(ValueInput::newValue, this, &ValueHistoriesLayer::onNewValue);
}

//--------------------------------------------------------------
void ValueHistoriesLayer::onNewValue(NameFloatEventArgs &e) {
  valueHistories->addValue(e.getName(), e.getValue());
}

//--------------------------------------------------------------
void ValueHistoriesLayer::drawAlgorithm() {
  vector<string> keys = valueHistories->getKeys();

  int i=0;
  for ( auto it = keys.begin(); it != keys.end(); ++it ) {
    ValueHistoryLayer layer = ValueHistoryLayer(valueHistories->getHistory((*it)), getColor(i));
    layer.draw();
    i++;
  }
}

//--------------------------------------------------------------
ofColor ValueHistoriesLayer::getColor(int i) {
  switch (i) {
    case 0:
      return ofColor::blue;
      break;
    case 1:
      return ofColor::green;
      break;
    case 2:
      return ofColor::red;
      break;
    case 3:
      return ofColor::brown;
      break;
    case 4:
      return ofColor::pink;
      break;
    case 5:
      return ofColor::cyan;
      break;
    case 6:
      return ofColor::fuchsia;
      break;
    default:
      return ofColor::white;
      break;
  }
}
