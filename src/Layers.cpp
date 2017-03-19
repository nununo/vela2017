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
  baseClipLayer = new ClipLayer(0, levels->getRandomClip(0));

}

//--------------------------------------------------------------
void Layers::update(int intensity) {

  if (clipLayers.size()>0)
    if (intensity > clipLayers.back()->getIntensity())
      add(intensity);
  
  baseClipLayer->update();
  
  // Updates each layer
  vector<ClipLayer*>::iterator it;
  for (it = clipLayers.begin(); it != clipLayers.end(); it++) {
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
    vector<ClipLayer*>::iterator it;
    for (it = clipLayers.begin(); it != clipLayers.end(); it++) {
      if (!(*it)->isPlaying()) {
        delete *it;
        clipLayers.erase(it);
        break;
      }
    }
  }
}

//--------------------------------------------------------------
void Layers::deleteHidden() {
  // Remove old first layer if top layer is no longer playing
  if (clipLayers.size() > 1 && !clipLayers.back()->isPlaying()) {
    delete *clipLayers.begin();
    clipLayers.erase(clipLayers.begin());
    cout << "Layer erased. " << clipLayers.size() << " layers remain." << endl;
  }

}
//--------------------------------------------------------------
void Layers::add(int intensity) {
  clipLayers.push_back(new ClipLayer(intensity, levels->getRandomClip(intensity)));
};

//--------------------------------------------------------------
void Layers::draw() {
  
  baseClipLayer->draw();
  
  vector<ClipLayer*>::iterator it;
  for (it = clipLayers.begin(); it != clipLayers.end(); it++)
    (*it)->draw();
};
