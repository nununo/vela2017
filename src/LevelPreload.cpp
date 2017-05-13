//
//  LevelPreload.cpp
//  vela2017
//
//  Created by Nuno on 13/05/2017.
//
//

#include "LevelPreload.h"

//-----------------------------------------------------------------------
LevelPreload::LevelPreload(GeneralSettings generalSettings,
                           ClipOutputSettings clipOutputSettings,
                           LevelSettings *levelSettings) : Level(generalSettings, clipOutputSettings, levelSettings) {
  preloadClipList();
  srand(time(NULL));
}

//-----------------------------------------------------------------------
Clip *LevelPreload::getNextClip() {
  // Select a random movie from vector
  int i = list.size();
  i = rand() % i;
  return list.at(i);
}

//-----------------------------------------------------------------------
void LevelPreload::preloadClipList() {
  // Load movies into vector
  vector<string> filenames = getFilenames();
  
  vector<string>::iterator it;
  
  for(it=filenames.begin(); it < filenames.end(); it++){
    list.push_back(createClip(*it));
    ofLogNotice() << "Loaded movie " << *it;
  }
}
