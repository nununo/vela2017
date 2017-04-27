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
  LayerSettings() : LayerSettings(true, ofPoint()) {}
  LayerSettings(bool visible, ofPoint _offset) {
    setVisible(visible);
    offset=_offset;
  }
  void setVisible(bool _visible) {visible=_visible;}
  bool getVisible() {return visible;}
  ofPoint getOffset() {return offset;}
  
private:
  bool visible;
  ofPoint offset;
};

#endif /* LayerSettings_h */
