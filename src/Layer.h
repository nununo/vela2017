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

class Layer {

public:
  Layer() {setVisible(true);}
  virtual ~Layer() {};
  void draw() {if (isVisible()) drawAlgorithm();}
  virtual void setVisible(bool _visible) {visible = _visible; cout << "setVisible=" << visible << "\n";}
  virtual bool isVisible() {return visible;}
  
protected:
  virtual void drawAlgorithm() = 0;

  bool visible;
};

#endif /* Layer_h */
