//
//  Layers.h
//  vela2017
//
//  Created by Nuno on 16/03/2017.
//
//

#ifndef Layers_h
#define Layers_h

#include "ClipLayer.h"
#include "Levels.h"

class Layers {
public:
  Layers(Levels *levels);
  void update(int intensity);
  void draw();
  
private:
  void add(int intensity);
  void deleteFinished();
  void deleteHidden();
  
  Levels *levels;
  vector<ClipLayer*> clipLayers;
  ClipLayer *baseClipLayer;

};

#endif /* Layers_h */
