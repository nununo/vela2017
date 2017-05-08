//
//  ClipLayers.cpp
//  vela2017
//
//  Created by Nuno on 16/03/2017.
//
//

#include "ClipLayers.h"
#include "Util.h"

ClipLayers::ClipLayers(LayerSettings _layerSettings, Levels *_levels) {
  layerSettings = _layerSettings;
  levels = _levels;
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

  if (intensity > BlowIntensity::IDLE && (!topLayer || topLayer->getCanBeInterrupted())) {
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
  
  if (isBaseLayerVisible())
    baseLayer->draw();
  
  if (topLayer)
    topLayer->draw();
}

//--------------------------------------------------------------
string ClipLayers::getTrace() {
  stringstream ss;

  ss << "  topLayer: " << (topLayer != NULL);
  ss << "  currentIntensity :" << Util::blowIntensityToString(currentIntensity);
  ss << "  isBaseLayerVisible: " << isBaseLayerVisible() << endl;
  
  ss << baseLayer->getTrace() << endl;
  
  if (topLayer)
    ss << topLayer->getTrace() << endl;
  
  return ss.str();
}
