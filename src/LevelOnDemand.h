//
//  LevelOnDemand.h
//  vela2017
//
//  Created by Nuno on 13/05/2017.
//
//

#ifndef LevelOnDemand_h
#define LevelOnDemand_h

#include "Level.h"

class LevelOnDemand : public Level {
  
public:
  LevelOnDemand(GeneralSettings generalSettings,
                ClipOutputSettings clipOutputSettings,
                LevelSettings *levelSettings) : Level(generalSettings, clipOutputSettings, levelSettings) {}
  virtual Clip *getNextClip() {return createClip(getRandomFilename());}
};

#endif /* LevelOnDemand_h */
