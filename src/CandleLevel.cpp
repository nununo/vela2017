#include "CandleLevel.h"

#define OF_ADDON_USING_OFXDIRLIST
#include "ofAddons.h"

//-----------------------------------------------------------------------
CandleLevel::CandleLevel(int _intensity, string foldername) {
  intensity = _intensity;
  // Read files in this folder
  ofxDirList oDir;
  oDir.setVerbose(false);
  int nFiles = oDir.listDir(foldername);
  // Load movies into vector
  for(int i = 0; i < nFiles; i++){
    // Load movie
    ofVideoPlayer *movie = new ofVideoPlayer();
    movie->loadMovie(oDir.getPath(i));
    movie->play();
    movies.push_back(movie);
    // Save filename
    filenames.push_back(oDir.getPath(i));
    cout << "Loaded movie " << oDir.getPath(i) << endl;
  }
  // initialize random see
  srand(time(NULL));
}

CandleLayer *CandleLevel::getNewLayer(bool loop) {
  // Select a random movie from vector
  int i = movies.size();
  i = rand() % i;
  CandleLayer *layer = new CandleLayer(intensity, filenames.at(i), movies.at(i), FADE_TIME, loop);
  return layer;
}
