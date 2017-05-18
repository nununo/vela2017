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
                             float _fadeOutTime,
                             bool _loop,
                             float _cannotRestartTime) {
  levelType = _levelType;
  movieFolder = _movieFolder;
  fadeOutTime = _fadeOutTime;
  loop = _loop;
  cannotRestartTime = _cannotRestartTime;
}
