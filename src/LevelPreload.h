//
//  LevelPreload.h
//  vela2017
//
//  Created by Nuno on 13/05/2017.
//
//

#ifndef LevelPreload_h
#define LevelPreload_h

#include "Level.h"

class LevelPreload : public Level {
  
public:
  LevelPreload(GeneralSettings generalSettings, ClipOutputSettings clipOutputSettings, LevelSettings *levelSettings);
  virtual Clip *getNextClip();
  
private:
  void preloadClipList();

  vector<Clip*> list;
};

#endif /* LevelPreload_h */
