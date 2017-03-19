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
  void update(int intensity);
  void draw();
  
private:
  void add(int intensity);
  void deleteFinished();
  void deleteHidden();
  
  Levels *levels;
  vector<Layer*> layers;
  Layer *baseLayer;

};

#endif /* Layers_h */
