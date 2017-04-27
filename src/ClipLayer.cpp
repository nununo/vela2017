#include "ClipLayer.h"

//-----------------------------------------------------------------------
ClipLayer::ClipLayer(LayerSettings layerSettings, int _intensity, Clip *_clip) : Layer(layerSettings) {
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
  if (isVisible())
    clip->draw();
}

//--------------------------------------------------------------
string ClipLayer::getTrace() {
  stringstream ss;
  
    ss << "  " << getIntensity() << " "
    << "Filename: " << getFilename() << "\n"
    << "    Position: " << roundf(getPosition()*100)/100 << " "
    << "Alpha: " << getAlpha() << "\n"
    << "    Visible: " << isVisible() << " "
    << "Playing: " << clip->isPlaying() << "\n"
    << "";
  
  return ss.str();
}
