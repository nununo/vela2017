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
  
  ofPushStyle();
  ofEnableAlphaBlending();
  ofSetColor(255,255,255,50);
  
  ofDrawLine(0, ofGetHeight()-valueHistory->getThresholds().getLow(), 100, ofGetHeight()-valueHistory->getThresholds().getLow());
  ofDrawLine(0, ofGetHeight()-valueHistory->getThresholds().getHigh(), 100, ofGetHeight()-valueHistory->getThresholds().getHigh());
  ofDrawLine(0, ofGetHeight()-valueHistory->getThresholds().getBlowOut(), 100, ofGetHeight()-valueHistory->getThresholds().getBlowOut());
  
  ofPopStyle();
  ofDisableAlphaBlending();

  deque<float> values = valueHistory->getValues();
  for (deque<float>::iterator it = values.begin(); it!=values.end(); ++it) {
    if (i>0)
      //ofDrawLine(i, ofGetHeight()-lastValue, i+1, ofGetHeight()-(*it));
    lastValue = (*it);
    i++;
  }
  
}
