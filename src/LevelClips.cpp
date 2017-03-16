#include "LevelClips.h"

#define OF_ADDON_USING_OFXDIRLIST

//-----------------------------------------------------------------------
LevelClips::LevelClips(int _intensity, string foldername) {
  intensity = _intensity;
  // Read files in this folder
  ofDirectory oDir;
  //oDir.setVerbose(false);                   // Is this needed? It was in the old version
  int nFiles = oDir.listDir(foldername);
  // Load movies into vector
  for(int i = 0; i < nFiles; i++){
    // Load movie
    ofVideoPlayer *movie = new ofVideoPlayer();
    movie->load(oDir.getPath(i));
    movie->play();
    movies.push_back(movie);
    // Save filename
    filenames.push_back(oDir.getPath(i));
    cout << "Loaded movie " << oDir.getPath(i) << endl;
  }
  // initialize random seed
  srand(time(NULL));
}

CandleLayer *LevelClips::getNewLayer(bool loop) {
  // Select a random movie from vector
  int i = movies.size();
  i = rand() % i;
  CandleLayer *layer = new CandleLayer(intensity, filenames.at(i), movies.at(i), FADE_TIME, loop);
  return layer;
}
