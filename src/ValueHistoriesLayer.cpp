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
  font.load("frabk.ttf",10);

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

  ofPushMatrix();
  ofTranslate(20,-20);
  
  for (auto it = keys.begin(); it != keys.end(); ++it ) {
    drawHistory((*it), valueHistories->getHistory((*it)));
    ofTranslate(ValueHistory::getSize()+10,0);
  }
  
  ofPopMatrix();
}

//--------------------------------------------------------------
void ValueHistoriesLayer::drawHistory(string name, ValueHistory* history) {
  
  int height = getSize().y;
  float lastValue=0;
  float min;
  float max;

  min=history->getThresholds().getOffset();
  max=history->getThresholds().getBlowOut();

  ofPushStyle();
  ofEnableAlphaBlending();

  // Threshold lines
  ofSetColor(255,255,255,100);

  ofDrawLine(0, height-history->getThresholds().getOffset(), ValueHistory::getSize(), height-history->getThresholds().getOffset());
  ofDrawLine(0, height-history->getThresholds().getLow(), ValueHistory::getSize(), height-history->getThresholds().getLow());
  ofDrawLine(0, height-history->getThresholds().getHigh(), ValueHistory::getSize(), height-history->getThresholds().getHigh());
  ofDrawLine(0, height-history->getThresholds().getBlowOut(), ValueHistory::getSize(), height-history->getThresholds().getBlowOut());
  
  // Value history
  ofSetColor(ofColor::white);

  int i=0;
  deque<float> values = history->getValues();
  for (deque<float>::iterator it = values.begin(); it!=values.end(); ++it) {
    if (i>0)
      ofDrawLine(i, height-lastValue, i+1, height-(*it));
    if ((*it)>max)
      max = (*it);
    if ((*it)<min)
      min = (*it);
    lastValue = (*it);
    i++;
  }
  
  // Draw name
  font.drawString(name, 0, height-min-2);

  // Draw rectange
  ofSetColor(255,255,255,100);
  ofNoFill();
  ofSetLineWidth(3);
  ofDrawRectangle(-3, height-min+10, ValueHistory::getSize()+6, min-max-20);

  ofPopStyle();
  ofDisableAlphaBlending();
}
