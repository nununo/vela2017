//
//  ClipLayers.cpp
//  vela2017
//
//  Created by Nuno on 16/03/2017.
//
//

#include "ClipLayers.h"
#include "Util.h"
#include "InputIntensity.h"

//--------------------------------------------------------------
ClipLayers::ClipLayers(GeneralSettings _generalSettings, LayerSettings _layerSettings, Levels *_levels) {
  generalSettings = _generalSettings;
  layerSettings = _layerSettings;
  levels = _levels;
  
  // Create base layer for level 0 (which will always loop)
  baseLayer = new ClipLayer(generalSettings, layerSettings, BlowIntensity::IDLE, levels->getRandomClip(BlowIntensity::IDLE));

  topLayer = NULL;
  
  ofAddListener(InputIntensity::blowIntensityChanged , this, &ClipLayers::onBlowIntensityChanged);
}

//--------------------------------------------------------------
ClipLayers::~ClipLayers() {
  ofRemoveListener(InputIntensity::blowIntensityChanged, this, &ClipLayers::onBlowIntensityChanged);
}

//--------------------------------------------------------------
void ClipLayers::update() {

  // Delete top layer if it finished playing
  if (topLayer && !topLayer->isVisible()) {
    delete topLayer;
    topLayer = NULL;
  }

  if (topLayer)
    topLayer->update();
  
  if (isBaseLayerVisible())
    baseLayer->update();
  else
    baseLayer->pause();
};

//--------------------------------------------------------------
void ClipLayers::onBlowIntensityChanged(BlowIntensity &newIntensity) {
  if (newIntensity > BlowIntensity::IDLE && (!topLayer ||
                                             newIntensity > topLayer->getIntensity() ||
                                             topLayer->getCanRestart())) {
    if (topLayer)
      delete topLayer;
    topLayer = new ClipLayer(generalSettings, layerSettings, newIntensity, levels->getRandomClip(newIntensity));
  }
}

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
  ss << "  currentIntensity :" << Util::blowIntensityToString(getCurrentIntensity());
  ss << "  isBaseLayerVisible: " << isBaseLayerVisible() << endl;
  
  ss << baseLayer->getTrace() << endl;
  
  if (topLayer)
    ss << topLayer->getTrace() << endl;
  
  return ss.str();
}

//--------------------------------------------------------------
BlowIntensity ClipLayers::getCurrentIntensity() {
  if (!topLayer)
    return BlowIntensity::IDLE;
  else
    return topLayer->getIntensity();
}
