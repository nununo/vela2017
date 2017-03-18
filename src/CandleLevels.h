//
//  CandleLevels.h
//  vela2017
//
//  Created by Nuno on 15/03/2017.
//
//

#ifndef CandleLevels_h
#define CandleLevels_h

#include "Clips.h"

class CandleLevels{
  
public:
  CandleLevels( string dataFolder );
  Clip *getRandomClip(int level);
  Layer *getNewLayer2( int level);
  
private:
  void loadMovies(string dataFolder);
  
  vector<Clips*> levels;

};

#endif /* CandleLevels_h */
