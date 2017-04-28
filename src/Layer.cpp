//
//  Layer.cpp
//  vela2017
//
//  Created by Nuno on 27/04/2017.
//
//

#include "Layer.h"

//--------------------------------------------------------------
Layer::Layer(LayerSettings _settings) {
  settings=_settings;
}

//--------------------------------------------------------------
ofPoint Layer::getSize() {
  ofPoint size;
   if (!settings.isPortraitMode()) {
    size.x = ofGetWidth();
    size.y = ofGetHeight();
  } else {
    size.x = ofGetHeight();
    size.y = ofGetWidth();
  }
  return size;
}

//--------------------------------------------------------------
void Layer::draw() {
  
  if (isVisible()) {
  
    ofPushMatrix();
    
    if (settings.isRotated180()) {
      ofTranslate(ofGetWidth()/2, ofGetHeight()/2, 0);
      ofRotateZ(180);
      ofTranslate(-ofGetWidth()/2, -ofGetHeight()/2, 0);
    }
    
    if (settings.isPortraitMode()) {
      ofTranslate(ofGetWidth(),0);
      ofRotateZ(90);
    }
    
    ofTranslate(settings.getOffset().x, settings.getOffset().y);

    drawAlgorithm();

    ofPopMatrix();
  }
}
