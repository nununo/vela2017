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
  ClipOutputSettings(float offsetX, float offsetY, float zoomX, float zoomY);
  float getOffsetX() {return offsetX;};
  float getOffsetY() {return offsetY;};
  float getZoomX() {return zoomX;};
  float getZoomY() {return zoomY;};
  
private:
  float offsetX;
  float offsetY;
  float zoomX;
  float zoomY;
};

#endif /* ClipOutputSettings_hpp */
