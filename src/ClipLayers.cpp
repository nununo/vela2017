//
//  ClipLayers.cpp
//  vela2017
//
//  Created by Nuno on 16/03/2017.
//
//

#include "ClipLayers.h"

ClipLayers::ClipLayers(Levels *_levels, int _clipsRotation) {
  levels = _levels;
  clipsRotation = _clipsRotation;
  
  // Create base layer for level 0
  baseClipLayer = new ClipLayer(0, levels->getRandomClip(0));

}

//--------------------------------------------------------------
void ClipLayers::update(int intensity) {

  if (list.size()>0)
    if (intensity > list.back()->getIntensity())
      add(intensity);
  
  baseClipLayer->update();
  
  // Updates each layer
  vector<ClipLayer*>::iterator it;
  for (it = list.begin(); it != list.end(); it++) {
    (*it)->update();
  }
  
  deleteFinished();
  deleteHidden();

};

//--------------------------------------------------------------
void ClipLayers::deleteFinished() {
  
  // I do this 3 times because that's the maximum layers that can exist
  // Ideally I would delete all with the same iterator but deleting one
  // element destroys the iterator and the next iteration explodes
  // So this is not pretty but... it works

  for (int i=0; i<3;i++) {
    vector<ClipLayer*>::iterator it;
    for (it = list.begin(); it != list.end(); it++) {
      if (!(*it)->isVisible()) {
        delete *it;
        list.erase(it);
        break;
      }
    }
  }
}

//--------------------------------------------------------------
void ClipLayers::deleteHidden() {
  // Remove old first layer if top layer is no longer playing
  if (list.size() > 1 && !list.back()->isVisible()) {
    delete *list.begin();
    list.erase(list.begin());
    cout << "Layer erased. " << list.size() << " layers remain." << endl;
  }

}
//--------------------------------------------------------------
void ClipLayers::add(int intensity) {
  list.push_back(new ClipLayer(intensity, levels->getRandomClip(intensity)));
};

//--------------------------------------------------------------
void ClipLayers::draw() {

  // Rotate clips
  if (clipsRotation != 0) {
    glRotated(clipsRotation, 0, 0, 1);
    glTranslated(-ofGetWidth(), -ofGetHeight(), 0);
  }

  baseClipLayer->draw();
  
  vector<ClipLayer*>::iterator it;
  for (it = list.begin(); it != list.end(); it++)
    (*it)->draw();

  // Reset rotation
  if (clipsRotation != 0) {
    glTranslated(ofGetWidth(), ofGetHeight(), 0);
    glRotated(-clipsRotation, 0, 0, 1);
  }
};
