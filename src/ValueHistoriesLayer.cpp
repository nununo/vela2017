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
ValueHistoriesLayer::ValueHistoriesLayer(LayerSettings layerSettings, HistorySettings _historySettings) : Layer(layerSettings) {
  historySettings = _historySettings;
  valueHistories = new ValueHistories();
  font.load("frabk.ttf",10);

}

//--------------------------------------------------------------
ValueHistoriesLayer::~ValueHistoriesLayer() {
  delete valueHistories;
  valueHistories=NULL;
}

//--------------------------------------------------------------
ofVec2f ValueHistoriesLayer::getHistoryMinMax(const ValueHistory* history) {
  float min;
  float max;

  if (!history->getThresholds().isInverted()) {
    min = history->getThresholds().getOffset();
    max = history->getThresholds().getBlowOut();
  } else {
    min = history->getThresholds().getBlowOut();
    max = history->getThresholds().getOffset();
  }

  deque<float> values = history->getValues();
  for (deque<float>::iterator it = values.begin(); it!=values.end(); ++it) {
    if ((*it)>max)
      max = (*it);
    if ((*it)<min)
      min = (*it);
  }
  return ofVec2f(min,max);

}

//--------------------------------------------------------------
float ValueHistoriesLayer::mapHeight(ofVec2f minMax, float value) {
  return historySettings.getChartHeight()-ofMap(value, minMax.x, minMax.y, 5, historySettings.getChartHeight()-5, true);
}

//--------------------------------------------------------------
void ValueHistoriesLayer::drawAlgorithm() {
  vector<string> keys = valueHistories->getKeys();

  ofPushMatrix();
  ofTranslate(20,-20);
  
  for (auto it = keys.begin(); it != keys.end(); ++it ) {
    drawHistory((*it), valueHistories->getHistory((*it)));
    ofTranslate(HistorySettings::getBufferSize()+10,0);
  }
  
  ofPopMatrix();
}

//--------------------------------------------------------------
void ValueHistoriesLayer::drawLine(ofVec2f minMax, ValueHistory *history, float value) {
  float mappedValue = mapHeight(minMax, value);
  
  ofDrawLine(0,
             mappedValue,
             HistorySettings::getBufferSize(),
             mappedValue);
}

//--------------------------------------------------------------
void ValueHistoriesLayer::drawHistory(string name, ValueHistory* history) {

  float lastValue=0;

  ofVec2f minMax = getHistoryMinMax(history);

  ofPushStyle();
  ofEnableAlphaBlending();

  // Threshold lines
  ofSetColor(255,255,255,100);

  drawLine(minMax, history, history->getThresholds().getOffset());
  drawLine(minMax, history, history->getThresholds().getLow());
  drawLine(minMax, history, history->getThresholds().getHigh());
  drawLine(minMax, history, history->getThresholds().getBlowOut());

  // Value history
  ofSetColor(ofColor::white);

  int i=0;
  deque<float> values = history->getValues();
  for (deque<float>::iterator it = values.begin(); it!=values.end(); ++it) {
    if (i>0)
      ofDrawLine(i, mapHeight(minMax,lastValue), i+1, mapHeight(minMax,(*it)));
    lastValue = (*it);
    i++;
  }

  // Draw name
  font.drawString(name, 0, -2);

  // Draw rectange
  ofSetColor(255,255,255,100);
  ofNoFill();
  ofSetLineWidth(3);
  ofDrawRectangle(-3, 0, HistorySettings::getBufferSize()+6, historySettings.getChartHeight());

  ofPopStyle();
  ofDisableAlphaBlending();
}
