//
//  Drawable.h
//  vela2017
//
//  Created by Nuno on 19/03/2017.
//
//

#ifndef Drawable_h
#define Drawable_h

class Drawable {

public:
  void setVisible(bool _visible) {visible=_visible;}
  void draw() {if (visible) drawAlgorithm();}
  virtual void drawAlgorithm() = 0;
  
private:
  bool visible = true;
};

#endif /* Drawable_h */
