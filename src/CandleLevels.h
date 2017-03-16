//
//  CandleLevels.h
//  vela2017
//
//  Created by Nuno on 15/03/2017.
//
//

#ifndef CandleLevels_h
#define CandleLevels_h

#include "LevelClips.h"

class CandleLevels{
  
public:
  CandleLevels( string dataFolder );
  Layer *getNewLayer( int level, bool loop);
  
private:
  vector<LevelClips*> levels;

};

#endif /* CandleLevels_h */
