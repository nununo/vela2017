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
Levels::Levels(ClipOutputSettings *clipOutputSettings, string folder0, string folder1, string folder2, string folder3) {

  cout << "Clips for 0 will be loaded from folder " << folder0 << "\n";
  levels.push_back(new Clips(clipOutputSettings, OF_LOOP_NORMAL, folder0));
  //cout << "Clips for 1 will be loaded from folder " << folder1 << "\n";
  //levels.push_back(new Clips(clipOutputSettings, OF_LOOP_NONE, folder1));
  //cout << "Clips for 2 will be loaded from folder " << folder2 << "\n";
  //levels.push_back(new Clips(clipOutputSettings, OF_LOOP_NONE, folder2));
  //cout << "Clips for 3 will be loaded from folder " << folder3 << "\n";
  //levels.push_back(new Clips(clipOutputSettings, OF_LOOP_NONE, folder3));
  //cout << levels.size() << " levels loaded." << endl;
};

//--------------------------------------------------------------
Clip *Levels::getRandomClip(int level) {
  return levels[level]->getRandomClip();
};
