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

