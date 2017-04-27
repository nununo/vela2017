//
//  ValueHistoryLayer.cpp
//  vela2017
//
//  Created by Nuno on 26/04/2017.
//
//

#include "ValueHistoryLayer.h"

//--------------------------------------------------------------
void ValueHistoryLayer::drawAlgorithm() {

  int height = ofGetScreenHeight();
  int i=0;
  float lastValue=0;
  
  // Threshold lines
  ofPushStyle();
  ofEnableAlphaBlending();
  ofSetColor(255,255,255,100);
  
  ofDrawLine(0, height-valueHistory->getThresholds().getLow(), ValueHistory::getSize(), height-valueHistory->getThresholds().getLow());
  ofDrawLine(0, height-valueHistory->getThresholds().getHigh(), ValueHistory::getSize(), height-valueHistory->getThresholds().getHigh());
  ofDrawLine(0, height-valueHistory->getThresholds().getBlowOut(), ValueHistory::getSize(), height-valueHistory->getThresholds().getBlowOut());
  
  ofPopStyle();
  ofDisableAlphaBlending();

  // Value history
  deque<float> values = valueHistory->getValues();
  for (deque<float>::iterator it = values.begin(); it!=values.end(); ++it) {
    if (i>0)
      ofDrawLine(i, height-lastValue, i+1, height-(*it));
    lastValue = (*it);
    i++;
  }
  
}
