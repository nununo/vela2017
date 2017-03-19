//
//  Layers.cpp
//  vela2017
//
//  Created by Nuno on 16/03/2017.
//
//

#include "Layers.h"

Layers::Layers(Levels *_levels) {
  levels = _levels;
  
  // Create base layer for level 0
  baseLayer = new Layer(0, levels->getRandomClip(0));

}

//--------------------------------------------------------------
void Layers::update(int intensity) {

  if (layers.size()>0)
    if (intensity > layers.back()->getIntensity())
      add(intensity);
  
  baseLayer->update();
  
  // Updates each layer
  vector<Layer*>::iterator it;
  for (it = layers.begin(); it != layers.end(); it++) {
    (*it)->update();
  }
  
  deleteFinished();
  deleteHidden();

};

//--------------------------------------------------------------
void Layers::deleteFinished() {
  
  // I do this 3 times because that's the maximum layers that can exist
  // Ideally I would delete all with the same iterator but deleting one
  // element destroys the iterator and the next iteration explodes
  // So this is not pretty but... it works

  for (int i=0; i<3;i++) {
    vector<Layer*>::iterator it;
    for (it = layers.begin(); it != layers.end(); it++) {
      if (!(*it)->isPlaying()) {
        delete *it;
        layers.erase(it);
        break;
      }
    }
  }
}

//--------------------------------------------------------------
void Layers::deleteHidden() {
  // Remove old first layer if top layer is no longer playing
  if (layers.size() > 1 && !layers.back()->isPlaying()) {
    delete *layers.begin();
    layers.erase(layers.begin());
    cout << "Layer erased. " << layers.size() << " layers remain." << endl;
  }

}
//--------------------------------------------------------------
void Layers::add(int intensity) {
  layers.push_back(new Layer(intensity, levels->getRandomClip(intensity)));
};

//--------------------------------------------------------------
void Layers::draw() {
  
  baseLayer->draw();
  
  vector<Layer*>::iterator it;
  for (it = layers.begin(); it != layers.end(); it++)
    (*it)->draw();
};
