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
#include "BlowIntensity.h"
#include "LayerSettings.h"

class ClipLayers: public ITrace {
public:
  ClipLayers(LayerSettings layerSettings, Levels *levels);
  void update(BlowIntensity intensity);
  void draw();
  virtual string getTrace();
  
private:
  bool isBaseLayerVisible();

  LayerSettings layerSettings;
  Levels *levels;
  ClipLayer *baseLayer;
  ClipLayer *topLayer;
  BlowIntensity currentIntensity;

};

#endif /* Layers_h */
