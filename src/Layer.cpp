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
bool Layer::isLandscape() {
  return (settings.getRotation()>=-45 && settings.getRotation()<=45) ||
          (settings.getRotation()>=135 && settings.getRotation()<=225);
}

//--------------------------------------------------------------
ofPoint Layer::getSize() {
  ofPoint size;
  if (isLandscape()) {
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
    
    if (settings.getRotation()!=0) {
      ofTranslate((float)getSize().x/2, (float)getSize().y/2, 0);
      ofRotateZ(settings.getRotation());
      ofTranslate(-(float)getSize().x/2, -(float)getSize().y/2, 0);
    }
    
    ofTranslate(settings.getOffset().x, settings.getOffset().y);

    drawAlgorithm();

    ofPopMatrix();
  }
}
