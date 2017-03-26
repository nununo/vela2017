#include "ClipLayer.h"
#include "Util.h"

//-----------------------------------------------------------------------
ClipLayer::ClipLayer(int _intensity, Clip *_clip) {
  clip = _clip;
  intensity = _intensity;
  
  clip->rewind_and_play();

  cout << "Created layer for " << clip->getFilename() << endl;
}

//-----------------------------------------------------------------------
ClipLayer::~ClipLayer() {
  cout << "Destroyed layer for " << clip->getFilename() << endl;
}

//-----------------------------------------------------------------------
void ClipLayer::update() {
  clip->update();
}

//-----------------------------------------------------------------------
void ClipLayer::drawAlgorithm() {
  clip->draw();
}

//--------------------------------------------------------------
string ClipLayer::getTrace() {
  stringstream ss;
  
    ss << "  " << getIntensity() << "\n"
    << "    Filename: " << getFilename() << "\n"
    << "    Position: " << roundf(getPosition()*100)/100 << "\n"
    << "    Alpha: " << getAlpha() << "\n";
  
  return ss.str();
}
