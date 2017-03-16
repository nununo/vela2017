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

class Layers {
public:
  void update();
  void push(Layer *layer);
  void draw();
  
private:
  vector<Layer*> layers;

};

#endif /* Layers_h */
