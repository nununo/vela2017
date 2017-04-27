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
#include "Constants.h"
#include "LayerSettings.h"

class ClipLayers: public ITrace {
public:
  ClipLayers(LayerSettings layerSettings, Levels *levels, int _clipsRotation);
  void update(blowIntensityType intensity);
  void draw();
  virtual string getTrace();
  
private:
  bool isBaseLayerVisible();
  void updateIntensity(blowIntensityType intensity);

  LayerSettings layerSettings;
  Levels *levels;
  ClipLayer *baseLayer;
  ClipLayer *topLayer;
  blowIntensityType currentIntensity;
  int clipsRotation;

};

#endif /* Layers_h */
