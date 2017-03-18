#include "Clips.h"

#define OF_ADDON_USING_OFXDIRLIST

//-----------------------------------------------------------------------
Clips::Clips(bool loop, string foldername) {

  loadMovies(loop, foldername);
  
  // initialize random seed
  srand(time(NULL));
}

//-----------------------------------------------------------------------
Clip *Clips::getRandomClip() {
  // Select a random movie from vector
  int i = clips.size();
  i = rand() % i;
  return clips.at(i);
}

//-----------------------------------------------------------------------
void Clips::loadMovies(bool loop, string foldername) {

  ofDirectory oDir;
  
  int nFiles = oDir.listDir(foldername);
  
  // Load movies into vector
  for(int i = 0; i < nFiles; i++){
    clips.push_back(new Clip(oDir.getPath(i), loop, FADE_TIME));
    cout << "Loaded movie " << oDir.getPath(i) << endl;
  }
}
