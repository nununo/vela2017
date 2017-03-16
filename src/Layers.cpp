//
//  Layers.cpp
//  vela2017
//
//  Created by Nuno on 16/03/2017.
//
//

#include "Layers.h"

//--------------------------------------------------------------
void Layers::update() {

  // Updates each layer
  vector<CandleLayer*>::iterator it;
  for (it = layers.begin(); it != layers.end(); it++) {
    (*it)->update();
    
    // Delete finished layers
    if (!(*it)->isPlaying()) {
      delete *it;
      layers.erase(it);
      // Ideally I wouldn't break here and go through all the layers looking for other deletable movies
      // but since deleting it destroys the iterator and the next iteration explodes... I'd have to come up
      // with a smarter code and I'm lazy.
      break;
    }
  }

  // Remove old first layer if top layer is already fully opaque.
  if (layers.size() > 1 && layers.back()->isOpaque()) {
    delete *layers.begin();
    layers.erase(layers.begin());
    cout << "Layer erased. " << layers.size() << " layers remain." << endl;
  }

};

//--------------------------------------------------------------
void Layers::push(CandleLayer *layer) {
  layers.push_back(layer);
};

//--------------------------------------------------------------
void Layers::draw() {
  vector<CandleLayer*>::iterator it;
  for (it = layers.begin(); it != layers.end(); it++)
    (*it)->draw();
};
