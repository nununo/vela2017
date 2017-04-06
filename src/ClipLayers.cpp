//
//  ClipLayers.cpp
//  vela2017
//
//  Created by Nuno on 16/03/2017.
//
//

#include "ClipLayers.h"
#include <sstream>

ClipLayers::ClipLayers(Levels *_levels, int _clipsRotation) {
  levels = _levels;
  clipsRotation = _clipsRotation;
  currentIntensity = 0;
  
  // Create base layer for level 0 (which will always loop)
  baseLayer = new ClipLayer(0, levels->getRandomClip(0));

  topLayer = NULL;
}

//--------------------------------------------------------------
void ClipLayers::update(int intensity) {

  updateIntensity(intensity);

  if (topLayer)
    topLayer->update();
  
  if (isBaseLayerVisible())
    baseLayer->update();
};

//--------------------------------------------------------------
bool ClipLayers::isBaseLayerVisible() {
  return topLayer == NULL || !topLayer->isOpaque();}

//--------------------------------------------------------------
void ClipLayers::draw() {
  
  // Rotate clips
  if (clipsRotation != 0) {
    glRotatef(clipsRotation, 0, 0, 1);
    glTranslatef(-ofGetWidth(), -ofGetHeight(), 0);
  }
  
  if (isBaseLayerVisible())
    baseLayer->draw();
  
  if (topLayer)
    topLayer->draw();
  
  // Reset rotation
  if (clipsRotation != 0) {
    glTranslatef(ofGetWidth(), ofGetHeight(), 0);
    glRotatef(-clipsRotation, 0, 0, 1);
  }
}

//--------------------------------------------------------------
void ClipLayers::updateIntensity(int intensity) {
  
  if (topLayer && !topLayer->isVisible()) {
    delete topLayer;
    topLayer = NULL;
    currentIntensity = 0;
  }
  
  if (intensity > currentIntensity) {
    topLayer = new ClipLayer(intensity, levels->getRandomClip(intensity));
    currentIntensity = intensity;
  }
}

//--------------------------------------------------------------
string ClipLayers::getTrace() {
  stringstream ss;

  ss << "  topLayer: " << (topLayer != NULL) << "\n";
  ss << "  isBaseLayerVisible: " << isBaseLayerVisible()<< "\n";
  
  ss << baseLayer->getTrace();
  
  if (topLayer)
    ss << topLayer->getTrace();
  
  return ss.str();
}
