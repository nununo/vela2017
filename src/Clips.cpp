#include "Clips.h"

#define OF_ADDON_USING_OFXDIRLIST

//-----------------------------------------------------------------------
Clips::Clips(ClipOutputSettings *clipOutputSettings, bool loop, string foldername) {

  loadMovies(clipOutputSettings, loop, foldername);
  
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
void Clips::loadMovies(ClipOutputSettings *clipOutputSettings, bool loop, string foldername) {

  ofDirectory oDir;
  
  int nFiles = oDir.listDir(foldername);
  
  // Load movies into vector
  for(int i = 0; i < nFiles; i++){
    list.push_back(new Clip(clipOutputSettings, oDir.getPath(i), loop, FADE_TIME));
    cout << "Loaded movie " << oDir.getPath(i) << endl;
  }
}
