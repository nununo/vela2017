//
//  ValueHistoriesLayer.cpp
//  vela2017
//
//  Created by Nuno on 26/04/2017.
//
//

#include "ValueHistoriesLayer.h"
#include "CalibratedValueInput.h"

//--------------------------------------------------------------
ValueHistoriesLayer::ValueHistoriesLayer(LayerSettings settings, int bufferSize) : Layer(settings) {
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
  
  for (auto it = keys.begin(); it != keys.end(); ++it )
    drawHistory(valueHistories->getHistory((*it)));
}

//--------------------------------------------------------------
void ValueHistoriesLayer::drawHistory(ValueHistory* history) {
  
  int height = ofGetScreenHeight();
  int i=0;
  float lastValue=0;
  
  // Threshold lines
  ofPushStyle();
  ofEnableAlphaBlending();
  ofSetColor(255,255,255,100);
  
  ofDrawLine(0, height-history->getThresholds().getLow(), ValueHistory::getSize(), height-history->getThresholds().getLow());
  ofDrawLine(0, height-history->getThresholds().getHigh(), ValueHistory::getSize(), height-history->getThresholds().getHigh());
  ofDrawLine(0, height-history->getThresholds().getBlowOut(), ValueHistory::getSize(), height-history->getThresholds().getBlowOut());
  
  ofPopStyle();
  ofDisableAlphaBlending();
  
  // Value history
  deque<float> values = history->getValues();
  for (deque<float>::iterator it = values.begin(); it!=values.end(); ++it) {
    if (i>0)
      ofDrawLine(i, height-lastValue, i+1, height-(*it));
    lastValue = (*it);
    i++;
  }
  
}
