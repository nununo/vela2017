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
  
  deque<float> values = valueHistory->getValues();
  for (deque<float>::iterator it = values.begin(); it!=values.end(); ++it) {
    if (i>0)
      ofDrawLine(i, lastValue, i+1, (*it));
    lastValue = (*it);
    i++;
  }
  
}
