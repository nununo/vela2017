//
//  LevelFactory.h
//  vela2017
//
//  Created by Nuno on 13/05/2017.
//
//

#ifndef LevelFactory_h
#define LevelFactory_h

#include "ofMain.h"
#include "Level.h"

class LevelFactory {
public:
  static Level* create(GeneralSettings generalSettings,
                       ClipOutputSettings clipOutputSettings,
                       LevelSettings *levelSettings);
};

#endif /* LevelFactory_h */
