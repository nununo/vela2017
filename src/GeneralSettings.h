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

class GeneralSettings {
public:
  GeneralSettings() : GeneralSettings(25,true,true, ValueHistory::BUFFER_SIZE_DEFAULT) {}
  GeneralSettings(int framerate, bool isFullscreen, bool useOmxPlayer, int historyBufferSize);
  int getFramerate() {return framerate;}
  bool getIsFullscreen() {return isFullscreen;}
  bool getUseOmxPlayer() {return useOmxPlayer;}
  int getHistoryBufferSize() {return historyBufferSize;}
  void setIsFullscreen(bool _isFullScreen) {isFullscreen=_isFullScreen;}
private:
  int framerate;
  bool isFullscreen;
  bool useOmxPlayer;
  int historyBufferSize;
};

#endif /* GeneralSettings_h */
