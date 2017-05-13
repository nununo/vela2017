//
//  LevelSettings.cpp
//  vela2017
//
//  Created by Nuno on 04/04/2017.
//
//

#include "LevelSettings.h"

LevelSettings::LevelSettings(std::string _levelType,
                             std::string _movieFolder,
                             float _fadeInTime,
                             float _fadeOutTime,
                             bool _loop,
                             bool _canRestart) {
  levelType = _levelType;
  movieFolder = _movieFolder;
  fadeInTime = _fadeInTime;
  fadeOutTime = _fadeOutTime;
  loop = _loop;
  canRestart = _canRestart;
}
