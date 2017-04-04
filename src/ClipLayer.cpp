#include "ClipLayer.h"
#include "Util.h"

//-----------------------------------------------------------------------
ClipLayer::ClipLayer(int _intensity, Clip *_clip) {
  clip = _clip;
  intensity = _intensity;
  
  clip->play();

  cout << "Created layer for " << clip->getFilename() << endl;
}

//-----------------------------------------------------------------------
ClipLayer::~ClipLayer() {
  cout << "Destroyed layer for " << clip->getFilename() << endl;
}

//-----------------------------------------------------------------------
void ClipLayer::update() {
  setVisible(clip->isPlaying());
  
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
