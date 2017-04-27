//
//  GeneralSettings.h
//  vela2017
//
//  Created by Nuno on 16/04/2017.
//
//

#ifndef GeneralSettings_h
#define GeneralSettings_h

class GeneralSettings {
public:
  GeneralSettings(int framerate, bool isFullscreen, bool useOmxPlayer);
  int getFramerate() {return framerate;}
  bool getIsFullscreen() {return isFullscreen;}
  bool getUseOmxPlayer() {return useOmxPlayer;}
  void setIsFullscreen(bool _isFullScreen) {isFullscreen=_isFullScreen;}
private:
  int framerate;
  bool isFullscreen;
  bool useOmxPlayer;
};

#endif /* GeneralSettings_h */
