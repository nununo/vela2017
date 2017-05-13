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
  LevelThreadChannel(GeneralSettings _generalSettings, ClipOutputSettings _clipOutputSettings, LevelSettings *_levelSettings);
  virtual Clip *getNextClip();
  
private:
  Clip *createRandomClip();
  void loadNextClip();
  void threadedFunction();
    
  ofThreadChannel<bool> clipConsumed;
  ofThreadChannel<Clip*> nextClip;
};

#endif /* LevelThreadChannel_h */
