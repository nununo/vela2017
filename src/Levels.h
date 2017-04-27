//
//  Levels.h
//  vela2017
//
//  Created by Nuno on 15/03/2017.
//
//

#ifndef Levels_h
#define Levels_h

#include "Clips.h"

class Levels{
  
public:
  Levels(GeneralSettings generalSettings, ClipOutputSettings clipOutputSettings, vector<LevelSettings*> levelSettingsList);
  Clip *getRandomClip(int level);
  
private:  
  vector<Clips*> levels;
};

#endif /* Levels_h */
