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
ofVec2f ValueHistoriesLayer::getThresholdsMinMax(const ValueHistory* history) {
  float min;
  float max;

  if (!history->getThresholds().isInverted()) {
    min = history->getThresholds().getOffset();
    max = history->getThresholds().getBlowOut();
  } else {
    min = history->getThresholds().getBlowOut();
    max = history->getThresholds().getOffset();
  }
  return ofVec2f(min,max);
}

//--------------------------------------------------------------
ofVec2f ValueHistoriesLayer::getValuesMinMax(const ValueHistory* history) {
  float min;
  float max;
  
  deque<float> values = history->getValues();
  min = values.back();
  max = values.back();
  for (deque<float>::iterator it = values.begin(); it!=values.end(); ++it) {
    if ((*it)>max)
      max = (*it);
    if ((*it)<min)
      min = (*it);
  }
  return ofVec2f(min,max);
}

//--------------------------------------------------------------
ofVec2f ValueHistoriesLayer::getMinMax(ofVec2f valuesMinMax, ofVec2f thresholdsMinMax) {
  ofVec2f minMax;
  minMax = valuesMinMax;
  if (thresholdsMinMax.x < minMax.x )
    minMax.x = thresholdsMinMax.x;
  if (thresholdsMinMax.y > minMax.y )
    minMax.y = thresholdsMinMax.y;
  return minMax;
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
  ofVec2f valuesMinMax;
  ofVec2f minMax;

  valuesMinMax = getValuesMinMax(history);
  minMax = getMinMax(valuesMinMax, getThresholdsMinMax(history));

  ofPushStyle();
  ofEnableAlphaBlending();

  // Threshold lines
  ofSetColor(255,255,255,100);
  drawLine(minMax, history, history->getThresholds().getOffset());
  ofSetColor(0,255,0,100);
  drawLine(minMax, history, history->getThresholds().getLow());
  ofSetColor(255,255,0,100);
  drawLine(minMax, history, history->getThresholds().getHigh());
  ofSetColor(255,0,0,100);
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
  font.drawString(name + " min:" + ofToString(roundf(valuesMinMax.x*1)/1.0f) + " max:" + ofToString(roundf(valuesMinMax.y*1)/1), 0, -2);

  // Draw rectange
  ofSetColor(255,255,255,100);
  ofNoFill();
  ofSetLineWidth(3);
  ofDrawRectangle(-3, 0, HistorySettings::getBufferSize()+6, historySettings.getChartHeight());

  ofPopStyle();
  ofDisableAlphaBlending();
}
