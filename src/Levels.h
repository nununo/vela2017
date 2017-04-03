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
  Levels(ClipOutputSettings *clipOutputSettings, string folder0, string folder1, string folder2, string folder3);
  Clip *getRandomClip(int level);
  
private:  
  vector<Clips*> levels;
};

#endif /* Levels_h */
