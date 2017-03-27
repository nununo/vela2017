//
//  ClipLayers.h
//  vela2017
//
//  Created by Nuno on 16/03/2017.
//
//

#ifndef ClipLayers_h
#define ClipLayers_h

#include "ClipLayer.h"
#include "Levels.h"

class ClipLayers: public ITrace {
public:
  ClipLayers(Levels *levels, int _clipsRotation);
  void update(int intensity);
  void draw();
  virtual string getTrace();
  
private:
  void add(int intensity);
  void deleteFinished();
  void deleteHidden();
  bool isBaseLayerVisible() {return list.size() == 0 || !(list.back()->isOpaque());}

  Levels *levels;
  ClipLayer *baseLayer;
  vector<ClipLayer*> list;
  int clipsRotation;

};

#endif /* Layers_h */
