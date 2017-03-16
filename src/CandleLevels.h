//
//  CandleLevels.h
//  vela2017
//
//  Created by Nuno on 15/03/2017.
//
//

#ifndef CandleLevels_h
#define CandleLevels_h

#include "CandleLevel.h"

class CandleLevels{
  
public:
  CandleLevels( string dataFolder );
  CandleLayer *getNewLayer( int level, bool loop);
  
private:
  vector<CandleLevel*> levels;

};

#endif /* CandleLevels_h */
