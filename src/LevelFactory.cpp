//
//  LevelFactory.cpp
//  vela2017
//
//  Created by Nuno on 13/05/2017.
//
//

#include "LevelFactory.h"
#include "LevelPreload.h"
#include "LevelThreadChannel.h"

//--------------------------------------------------------------
Level* LevelFactory::create(GeneralSettings generalSettings,
                            ClipOutputSettings clipOutputSettings,
                            LevelSettings *levelSettings) {
  
  if (levelSettings->getLevelType() == LevelType::PRELOAD)
    return new LevelPreload(generalSettings, clipOutputSettings, levelSettings);

  else if (levelSettings->getLevelType() == LevelType::THREAD_CHANNEL)
    return new LevelThreadChannel(generalSettings, clipOutputSettings, levelSettings);
  
  else {
    ofLogError() << "Invalid level type " << levelSettings->getLevelType();
    return NULL;
  }
}
