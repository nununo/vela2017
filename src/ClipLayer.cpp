#include "ClipLayer.h"

//-----------------------------------------------------------------------
ClipLayer::ClipLayer(LayerSettings layerSettings, BlowIntensity _intensity, Clip *_clip) : Layer(layerSettings) {
  clip = _clip;
  intensity = _intensity;
  
  clip->rewind();
  
  ofLogNotice() << "Created layer for " << clip->getFilename();
}

//-----------------------------------------------------------------------
ClipLayer::~ClipLayer() {
  clip->pause();
  ofLogNotice() << "Destroyed layer for " << clip->getFilename();
}

//-----------------------------------------------------------------------
void ClipLayer::update() {
  if (!clip->isPlaying())
    setVisible(false);
  
  if (isVisible())
    clip->update();
}

//-----------------------------------------------------------------------
void ClipLayer::drawAlgorithm() {
  clip->draw();
}

//--------------------------------------------------------------
string ClipLayer::getTrace() {
  stringstream ss;
  ss << (int)getIntensity() << " Visible: " << isVisible() << " " << clip->getTrace();
  return ss.str();
}
