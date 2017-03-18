#include "LevelClips.h"

#define OF_ADDON_USING_OFXDIRLIST

//-----------------------------------------------------------------------
LevelClips::LevelClips(int _intensity, bool loop, string foldername) {
  intensity = _intensity;

  loadMovies(loop, foldername);
  
  // initialize random seed
  srand(time(NULL));
}

//-----------------------------------------------------------------------
Layer *LevelClips::getRandomLayer() {
  // Select a random movie from vector
  int i = clips.size();
  i = rand() % i;
  return new Layer(intensity, clips.at(i));
}

//-----------------------------------------------------------------------
void LevelClips::loadMovies(bool loop, string foldername) {

  ofDirectory oDir;
  
  int nFiles = oDir.listDir(foldername);
  
  // Load movies into vector
  for(int i = 0; i < nFiles; i++){
    clips.push_back(new Clip(oDir.getPath(i), loop, FADE_TIME));
    cout << "Loaded movie " << oDir.getPath(i) << endl;
  }
}
