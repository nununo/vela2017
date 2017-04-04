//
//  LevelSettings.cpp
//  vela2017
//
//  Created by Nuno on 04/04/2017.
//
//

#include "LevelSettings.h"

LevelSettings::LevelSettings(string _movieFolder, float _fadeInTime, float _fadeOutTime, float _threshold, bool _loop) {
  movieFolder = _movieFolder;
  fadeInTime = _fadeInTime;
  fadeOutTime = _fadeOutTime;
  threshold = _threshold;
  loop = _loop;
}
