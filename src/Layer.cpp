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
    ofTranslate(settings.getOffset().x, settings.getOffset().y);
    drawAlgorithm();
    ofPopMatrix();
  }
  
}
