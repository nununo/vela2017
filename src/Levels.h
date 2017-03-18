//
//  Levels.h
//  vela2017
//
//  Created by Nuno on 15/03/2017.
//
//

#ifndef Levels_h
#define Levels_h

#include "Clips.h"

class Levels{
  
public:
  Levels(ClipOutputSettings *clipOutputSettings, string dataFolder);
  Clip *getRandomClip(int level);
  
private:
  void loadMovies(ClipOutputSettings *clipOutputSettings, string dataFolder);
  
  vector<Clips*> levels;
};

#endif /* Levels_h */
