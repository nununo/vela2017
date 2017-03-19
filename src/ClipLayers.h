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

class ClipLayers {
public:
  ClipLayers(Levels *levels);
  void update(int intensity);
  void draw();
  
private:
  void add(int intensity);
  void deleteFinished();
  void deleteHidden();
  
  Levels *levels;
  vector<ClipLayer*> list;
  ClipLayer *baseClipLayer;

};

#endif /* Layers_h */
