//
//  CandleLevels.cpp
//  vela2017
//
//  Created by Nuno on 15/03/2017.
//
//

#include "Levels.h"
#include "Clips.h"

//--------------------------------------------------------------
Levels::Levels(GeneralSettings generalSettings, ClipOutputSettings *clipOutputSettings, vector<LevelSettings*> levelSettingsList) {

  for (int i=0; i<4; i++) {
    ofLogNotice() << "Loading level " << i;
    levels.push_back(new Clips(generalSettings, clipOutputSettings, levelSettingsList[i]));
  }
};

//--------------------------------------------------------------
Clip *Levels::getRandomClip(int level) {
  return levels[level]->getRandomClip();
};
