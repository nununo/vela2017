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
  ClipOutputSettings(float offsetX, float offsetY, float zoomX, float zoomY, float rotation);
  float getOffsetX() {return offsetX;};
  float getOffsetY() {return offsetY;};
  float getZoomX() {return zoomX;};
  float getZoomY() {return zoomY;};
  float getRotation() {return rotation;}
  
private:
  float offsetX;
  float offsetY;
  float zoomX;
  float zoomY;
  float rotation;
};

#endif /* ClipOutputSettings_hpp */
