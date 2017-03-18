#include "Layer.h"
#include "Util.h"

//-----------------------------------------------------------------------
Layer::Layer(int _intensity, Clip *_clip) {
  clip = _clip;
  intensity = _intensity;
  
  clip->rewind_and_play();

  cout << "Created layer for " << clip->getFilename() << endl;
}

//-----------------------------------------------------------------------
Layer::~Layer() {
  cout << "Destroyed layer for " << clip->getFilename() << endl;
}

//-----------------------------------------------------------------------
void Layer::update() {
  clip->update();
}

//-----------------------------------------------------------------------
void Layer::draw() {
  clip->draw();
}


//-----------------------------------------------------------------------
void Layer::outputStatus() {
//  cout << "layer " << clip->getFilename() << " intensity=" << intensity << " pos=" << movie->getPosition() << " playing=" << isPlaying() << endl;
}
