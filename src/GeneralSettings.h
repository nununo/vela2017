//
//  GeneralSettings.h
//  vela2017
//
//  Created by Nuno on 16/04/2017.
//
//

#ifndef GeneralSettings_h
#define GeneralSettings_h

#include "ValueHistory.h"
#include "ofMain.h"

class GeneralSettings {
public:
  GeneralSettings() : GeneralSettings(25,true,true) {}
  GeneralSettings(int framerate, bool isFullscreen, bool useOmxPlayer);
  const int getFramerate() const {return framerate;}
  const bool getIsFullscreen() const {return isFullscreen;}
  const bool getUseOmxPlayer() const {return useOmxPlayer;}
  const ofVec2f getWindowSize() const {return windowSize;}
  
  void setIsFullscreen(bool _isFullScreen) {isFullscreen=_isFullScreen;}
private:
  int framerate;
  bool isFullscreen;
  bool useOmxPlayer;
  ofVec2f windowSize;
};

#endif /* GeneralSettings_h */
