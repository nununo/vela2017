//
//  ClipOutputSettings.h
//  vela2017
//
//  Created by Nuno on 18/03/2017.
//
//

#ifndef ClipOutputSettings_h
#define ClipOutputSettings_h

#include "ofMain.h"

class ClipOutputSettings {
  
public:
  ClipOutputSettings() : ClipOutputSettings(1,1, 0xFFFFFF) {}
  ClipOutputSettings(float _zoomX, float _zoomY, ofColor _color) {
    zoomX = _zoomX;
    zoomY = _zoomY;
    color = _color;
  }
  float getZoomX() {return zoomX;};
  float getZoomY() {return zoomY;};
  ofColor getColor() {return color;}
  
private:
  float zoomX;
  float zoomY;
  ofColor color;
};

#endif /* ClipOutputSettings_hpp */
