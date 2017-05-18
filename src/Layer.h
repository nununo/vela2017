//
//  Layer.h
//  vela2017
//
//  Created by Nuno on 19/03/2017.
//
//

#ifndef Layer_h
#define Layer_h

#include "ofMain.h"
#include "LayerSettings.h"
#include "GeneralSettings.h"

class Layer {

public:
  Layer(GeneralSettings generalSettings, LayerSettings settings);
  ~Layer() {};
  void draw();
  void setVisible(bool visible) {layerSettings.setVisible(visible);}
  const bool isVisible() const {return layerSettings.getVisible();}

protected:
  const LayerSettings getLayerSettings() const {return layerSettings;}
  virtual void drawAlgorithm() = 0;
  
  GeneralSettings generalSettings;
  LayerSettings layerSettings;
};

#endif /* Layer_h */
