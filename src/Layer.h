//
//  Layer.h
//  vela2017
//
//  Created by Nuno on 19/03/2017.
//
//

#ifndef Layer_h
#define Layer_h

class Layer {

public:
  virtual ~Layer() {};
  void draw() {if (isVisible()) drawAlgorithm();}
  virtual bool isVisible() = 0;
  
protected:
  virtual void drawAlgorithm() = 0;
  
};

#endif /* Layer_h */
