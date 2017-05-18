//
//  LevelThreadChannel.h
//  vela2017
//
//  Created by Nuno on 13/05/2017.
//
//

#ifndef LevelThreadChannel_h
#define LevelThreadChannel_h

#include "Level.h"

class LevelThreadChannel : public ofThread, public Level {
  
public:
  LevelThreadChannel(GeneralSettings generalSettings, ClipOutputSettings clipOutputSettings, LevelSettings *levelSettings);
  virtual Clip *getNextClip();
  
private:
  Clip *createRandomClip() {return createClip(getRandomFilename());}
  void loadNextClip();
  void threadedFunction();
    
  ofThreadChannel<bool> clipConsumed;
  ofThreadChannel<Clip*> nextClip;
};

#endif /* LevelThreadChannel_h */
