#include "Clips.h"

#define OF_ADDON_USING_OFXDIRLIST

//-----------------------------------------------------------------------
Clips::Clips(ClipOutputSettings *clipOutputSettings, LevelSettings *levelSettings) {

  buildClipList(clipOutputSettings, levelSettings);
  
  // initialize random seed
  srand(time(NULL));
}

//-----------------------------------------------------------------------
Clip *Clips::getRandomClip() {
  // Select a random movie from vector
  int i = list.size();
  i = rand() % i;
  return list.at(i);
}

//-----------------------------------------------------------------------
void Clips::buildClipList(ClipOutputSettings *clipOutputSettings, LevelSettings *levelSettings) {

  ofDirectory oDir;
  
  int nFiles = oDir.listDir(levelSettings->getMovieFolder());
  
  // Load movies into vector
  for(int i = 0; i < nFiles; i++){
    list.push_back(new Clip(clipOutputSettings, levelSettings, oDir.getPath(i)));
    ofLogNotice() << "Loaded movie " << oDir.getPath(i);
  }
}
