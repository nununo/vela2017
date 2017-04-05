#include "ClipLayer.h"

//-----------------------------------------------------------------------
ClipLayer::ClipLayer(int _intensity, Clip *_clip) {
  clip = _clip;
  intensity = _intensity;
  
  clip->rewind();
  
  setVisible(true);

  cout << "Created layer for " << clip->getFilename() << endl;
}

//-----------------------------------------------------------------------
ClipLayer::~ClipLayer() {
  cout << "Destroyed layer for " << clip->getFilename() << endl;
}

//-----------------------------------------------------------------------
void ClipLayer::update() {
  if (!clip->isPlaying())
    setVisible(false);
  
  clip->update();
}

//-----------------------------------------------------------------------
void ClipLayer::drawAlgorithm() {
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
