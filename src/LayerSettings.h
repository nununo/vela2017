//
//  LayerSettings.h
//  vela2017
//
//  Created by Nuno on 27/04/2017.
//
//

#ifndef LayerSettings_h
#define LayerSettings_h

#include "ofMain.h"

class LayerSettings {
public:
  LayerSettings() : LayerSettings(true, ofPoint(),0) {}
  LayerSettings(bool visible, ofPoint _offset, float _rotation) {
    setVisible(visible);
    offset=_offset;
    rotation=_rotation;
  }
  void setVisible(bool _visible) {visible=_visible;}
  bool getVisible() {return visible;}
  ofPoint getOffset() {return offset;}
  float getRotation() {return rotation;}
  
private:
  bool visible;
  ofPoint offset;
  float rotation;
};

#endif /* LayerSettings_h */
