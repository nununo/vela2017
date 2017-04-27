//
//  ClipLayers.cpp
//  vela2017
//
//  Created by Nuno on 16/03/2017.
//
//

#include "ClipLayers.h"
#include "Util.h"

ClipLayers::ClipLayers(LayerSettings _layerSettings, Levels *_levels, int _clipsRotation) {
  layerSettings = _layerSettings;
  levels = _levels;
  clipsRotation = _clipsRotation;
  currentIntensity = BlowIntensity::IDLE;
  
  // Create base layer for level 0 (which will always loop)
  baseLayer = new ClipLayer(layerSettings, BlowIntensity::IDLE, levels->getRandomClip(BlowIntensity::IDLE));

  topLayer = NULL;
}

//--------------------------------------------------------------
void ClipLayers::update(BlowIntensity intensity) {

  // Delete top layer if it finished playing
  if (topLayer && !topLayer->isVisible()) {
    delete topLayer;
    topLayer = NULL;
    currentIntensity = BlowIntensity::IDLE;
  }

  if (intensity > BlowIntensity::IDLE && (!topLayer || topLayer->getCanRestart())) {
    delete topLayer;
    topLayer = new ClipLayer(layerSettings, intensity, levels->getRandomClip(intensity));
    currentIntensity = intensity;
  }

  if (topLayer)
    topLayer->update();
  
  if (isBaseLayerVisible())
    baseLayer->update();
  else
    baseLayer->pause();
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
string ClipLayers::getTrace() {
  stringstream ss;

  ss << "  topLayer: " << (topLayer != NULL) << "\n";
  ss << "  currentIntensity :" << Util::blowIntensityToString(currentIntensity) << "\n";
  ss << "  isBaseLayerVisible: " << isBaseLayerVisible()<< "\n";
  
  ss << baseLayer->getTrace();
  
  if (topLayer)
    ss << topLayer->getTrace();
  
  return ss.str();
}
