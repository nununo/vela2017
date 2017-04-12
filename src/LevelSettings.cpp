//
//  LevelSettings.cpp
//  vela2017
//
//  Created by Nuno on 04/04/2017.
//
//

#include "LevelSettings.h"

LevelSettings::LevelSettings(string _movieFolder, float _fadeInTime, float _fadeOutTime, bool _loop, bool _canRestart) {
  movieFolder = _movieFolder;
  fadeInTime = _fadeInTime;
  fadeOutTime = _fadeOutTime;
  loop = _loop;
  canRestart = _canRestart;
}
