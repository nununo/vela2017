//
//  Layer.cpp
//  vela2017
//
//  Created by Nuno on 27/04/2017.
//
//

#include "Layer.h"

//--------------------------------------------------------------
void Layer::draw() {
  
  if (isVisible()) {
    ofPushMatrix();
    
    if (settings.getRotation()!=0) {
      glRotatef(settings.getRotation(), 0, 0, 1);
      glTranslatef(-ofGetWidth(), -ofGetHeight(), 0);
    }
    
    ofTranslate(settings.getOffset().x, settings.getOffset().y);
    
    drawAlgorithm();
  
    ofPopMatrix();
  }
}
