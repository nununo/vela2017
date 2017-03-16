//
//  Layers.h
//  vela2017
//
//  Created by Nuno on 16/03/2017.
//
//

#ifndef Layers_h
#define Layers_h

#include "CandleLayer.h"

class Layers {
public:
  void update();
  void push(CandleLayer *layer);
  void draw();
  
private:
  vector<CandleLayer*> layers;

};

#endif /* Layers_h */
