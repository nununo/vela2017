#include "Clips.h"
#include "MovieFactory.h"

#define OF_ADDON_USING_OFXDIRLIST

//-----------------------------------------------------------------------
Clips::Clips(GeneralSettings generalSettings, ClipOutputSettings *clipOutputSettings, LevelSettings *levelSettings) {

  buildClipList(generalSettings, clipOutputSettings, levelSettings);

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
void Clips::buildClipList(GeneralSettings generalSettings, ClipOutputSettings *clipOutputSettings, LevelSettings *levelSettings) {

  ofDirectory oDir;

  int nFiles = oDir.listDir(levelSettings->getMovieFolder());

  // Load movies into vector
  for(int i = 0; i < nFiles; i++){
    list.push_back(new Clip(clipOutputSettings, levelSettings, MovieFactory::create(oDir.getPath(i), levelSettings->getLoop(), generalSettings)));
    ofLogNotice() << "Loaded movie " << oDir.getPath(i);
  }
}
