//
//  CandleLevels.cpp
//  vela2017
//
//  Created by Nuno on 15/03/2017.
//
//

#include "CandleLevels.h"
#include "Clips.h"

//--------------------------------------------------------------
CandleLevels::CandleLevels( string dataFolder ) {
  loadMovies(dataFolder);
  cout << levels.size() << " levels loaded." << endl;
};

//--------------------------------------------------------------
Clip *CandleLevels::getRandomClip(int level) {
  return levels[level]->getRandomClip();
};

//--------------------------------------------------------------
void CandleLevels::loadMovies(string dataFolder) {
  // Read files in this folder
  ofDirectory oDir;
  
  int nFiles = oDir.listDir( dataFolder );
  
  // Load movies into vector
  for(int i = 0; i < nFiles; i++){
    cout << "Loading level " << i << " from " << oDir.getPath(i) << endl;
    
    levels.push_back(new Clips(i==0, oDir.getPath(i)));
  }
}
