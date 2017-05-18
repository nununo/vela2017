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
  ClipLayers(GeneralSettings generalSettings, LayerSettings layerSettings, Levels *levels);
  ~ClipLayers();
  void update();
  void draw();
  virtual string getTrace();
  
private:
  bool isBaseLayerVisible();
  void onBlowIntensityChanged(BlowIntensity &e);
  BlowIntensity getCurrentIntensity();

  GeneralSettings generalSettings;
  LayerSettings layerSettings;
  Levels *levels;
  ClipLayer *baseLayer;
  ClipLayer *topLayer;
};

#endif /* Layers_h */
