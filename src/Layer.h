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

class Layer {

public:
  Layer() : Layer(LayerSettings()) {}
  Layer(LayerSettings _settings);
  ~Layer() {};
  void draw();
  void setVisible(bool visible) {settings.setVisible(visible);}
  bool isVisible() {return settings.getVisible();}

protected:
  virtual void drawAlgorithm() = 0;
  ofPoint getSize();
  
  LayerSettings settings;
};

#endif /* Layer_h */
