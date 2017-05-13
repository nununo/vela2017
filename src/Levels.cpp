//
//  CandleLevels.cpp
//  vela2017
//
//  Created by Nuno on 15/03/2017.
//
//

#include "Levels.h"

//--------------------------------------------------------------
Levels::Levels(const GeneralSettings generalSettings, const ClipOutputSettings clipOutputSettings, const vector<LevelSettings*> levelSettingsList) {

  for (int i=0; i<4; i++) {
    ofLogNotice() << "Loading level " << i;
    levels.push_back(new Level(generalSettings, clipOutputSettings, levelSettingsList[i]));
  }
};

//--------------------------------------------------------------
Clip *Levels::getRandomClip(const BlowIntensity blowIntensity) {
  return levels[(int)blowIntensity]->getNextClip();
};
