//
//  Layers.h
//  vela2017
//
//  Created by Nuno on 16/03/2017.
//
//

#ifndef Layers_h
#define Layers_h

#include "Layer.h"
#include "Levels.h"

class Layers {
public:
  Layers(Levels *levels);
  void update(int level);
  void push(Layer *layer);
  void draw();
  
private:
  void deleteFinished();
  void deleteHidden();
  
  Levels *levels;
  vector<Layer*> layers;
  Layer *baseLayer;

};

#endif /* Layers_h */
