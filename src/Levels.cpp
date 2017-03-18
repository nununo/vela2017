//
//  CandleLevels.cpp
//  vela2017
//
//  Created by Nuno on 15/03/2017.
//
//

#include "Levels.h"
#include "Clips.h"

//--------------------------------------------------------------
Levels::Levels(ClipOutputSettings *clipOutputSettings, string dataFolder) {
  loadMovies(clipOutputSettings, dataFolder);
  cout << levels.size() << " levels loaded." << endl;
};

//--------------------------------------------------------------
Clip *Levels::getRandomClip(int level) {
  return levels[level]->getRandomClip();
};

//--------------------------------------------------------------
void Levels::loadMovies(ClipOutputSettings *clipOutputSettings, string dataFolder) {
  // Read files in this folder
  ofDirectory oDir;
  
  int nFiles = oDir.listDir( dataFolder );
  
  // Load movies into vector
  for(int i = 0; i < nFiles; i++){
    cout << "Loading level " << i << " from " << oDir.getPath(i) << endl;
    
    // Level 0 loops because it's the base layer. All the other levels
    // must not loop, they fade out when finished
    levels.push_back(new Clips(clipOutputSettings, i==0, oDir.getPath(i)));
  }
}
