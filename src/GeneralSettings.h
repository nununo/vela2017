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
  GeneralSettings(int framerate, bool isFullscreen, bool showTrace, bool showHistory);
  int getFramerate() {return framerate;}
  bool getIsFullscreen() {return isFullscreen;}
  bool getShowTrace() {return showTrace;}
  bool getShowHistory() {return showHistory;}
  
private:
  int framerate;
  bool isFullscreen;
  bool showTrace;
  bool showHistory;
};

#endif /* GeneralSettings_h */
