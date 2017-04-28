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
  LayerSettings() : LayerSettings(true,ofPoint(),false,false) {}
  LayerSettings(bool visible, ofPoint _offset, bool _rotated180, bool _portraitMode) {
    setVisible(visible);
    offset=_offset;
    rotated180=_rotated180;
    portraitMode=_portraitMode;
  }
  void setVisible(bool _visible) {visible=_visible;}
  bool getVisible() {return visible;}
  ofPoint getOffset() {return offset;}
  bool isRotated180() {return rotated180;}
  bool isPortraitMode() {return portraitMode;}

private:
  bool visible;
  ofPoint offset;
  bool rotated180;
  bool portraitMode;
};

#endif /* LayerSettings_h */
