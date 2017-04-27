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
#include "BlowIntensity.h"

class Levels{
  
public:
  Levels(const GeneralSettings generalSettings, const ClipOutputSettings clipOutputSettings, const vector<LevelSettings*> levelSettingsList);
  Clip *getRandomClip(const BlowIntensity blowIntensity);
  
private:  
  vector<Clips*> levels;
};

#endif /* Levels_h */
