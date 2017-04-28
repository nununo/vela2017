//
//  GeneralSettings.cpp
//  vela2017
//
//  Created by Nuno on 16/04/2017.
//
//

#include "GeneralSettings.h"

//--------------------------------------------------------------
GeneralSettings::GeneralSettings(int _framerate, bool _isFullscreen, bool _useOmxPlayer, int _historyBufferSize) {
  framerate = _framerate;
  isFullscreen = _isFullscreen;
  useOmxPlayer = _useOmxPlayer;
  historyBufferSize = _historyBufferSize;
  
}
