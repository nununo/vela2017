//
//  Layer.cpp
//  vela2017
//
//  Created by Nuno on 27/04/2017.
//
//

#include "Layer.h"

//--------------------------------------------------------------
Layer::Layer(GeneralSettings _generalSettings, LayerSettings _layerSettings) {
  layerSettings=_layerSettings;
  generalSettings = _generalSettings;
}

//--------------------------------------------------------------
void Layer::draw() {
  
  if (isVisible()) {
  
    ofPushMatrix();
    
    int width = generalSettings.getWindowSize().x;
    int height = generalSettings.getWindowSize().y;
    
    if (layerSettings.isRotated180()) {
      ofTranslate(width/2, height/2, 0);
      ofRotateZ(180);
      ofTranslate(-width/2, -height/2, 0);
    }
    
    if (layerSettings.isPortraitMode()) {
      ofTranslate(width,0);
      ofRotateZ(90);
    }
    
    ofTranslate(layerSettings.getOffset().x, layerSettings.getOffset().y);

    drawAlgorithm();

    ofPopMatrix();
  }
}
