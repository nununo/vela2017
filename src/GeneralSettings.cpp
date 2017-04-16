//
//  GeneralSettings.cpp
//  vela2017
//
//  Created by Nuno on 16/04/2017.
//
//

#include "GeneralSettings.h"

GeneralSettings::GeneralSettings(int _framerate, bool _isFullscreen, bool _showTrace, bool _showHistory) {
  framerate = _framerate;
  isFullscreen = _isFullscreen;
  showTrace = _showTrace;
  showHistory = _showHistory;
}
