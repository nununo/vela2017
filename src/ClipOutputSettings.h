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
  ClipOutputSettings() : ClipOutputSettings(1,1,0) {}
  ClipOutputSettings(float zoomX, float zoomY, float rotation);
  float getZoomX() {return zoomX;};
  float getZoomY() {return zoomY;};
  float getRotation() {return rotation;}
  
private:
  float zoomX;
  float zoomY;
  float rotation;
};

#endif /* ClipOutputSettings_hpp */
