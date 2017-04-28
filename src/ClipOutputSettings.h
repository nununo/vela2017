//
//  ClipOutputSettings.h
//  vela2017
//
//  Created by Nuno on 18/03/2017.
//
//

#ifndef ClipOutputSettings_h
#define ClipOutputSettings_h

class ClipOutputSettings {
  
public:
  ClipOutputSettings() : ClipOutputSettings(1,1) {}
  ClipOutputSettings(float _zoomX, float _zoomY) {
    zoomX = _zoomX;
    zoomY = _zoomY;
  }
  float getZoomX() {return zoomX;};
  float getZoomY() {return zoomY;};
  
private:
  float zoomX;
  float zoomY;
};

#endif /* ClipOutputSettings_hpp */
