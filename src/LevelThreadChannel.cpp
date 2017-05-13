//
//  LevelThreadChannel.cpp
//  vela2017
//
//  Created by Nuno on 13/05/2017.
//
//

#include "LevelThreadChannel.h"

//-----------------------------------------------------------------------
LevelThreadChannel::LevelThreadChannel(GeneralSettings generalSettings,
                                       ClipOutputSettings clipOutputSettings,
                                       LevelSettings *levelSettings) : Level(generalSettings, clipOutputSettings, levelSettings) {
  
  if (levelSettings->isThreadedMovieLoad()) {
    // start the thread as soon as the class is created
    // it won't use any CPU until we send a new frame to be analyzed
    startThread();
    
    // We immediately loading the next clip
    loadNextClip();
  }
}

//-----------------------------------------------------------------------
Clip *LevelThreadChannel::createRandomClip() {
  return new Clip(getGeneralSettings(),
                  getClipOutputSettings(),
                  getLevelSettings(),
                  getRandomFilename());
}

//-----------------------------------------------------------------------
void LevelThreadChannel::loadNextClip() {
  nextClip.send(createRandomClip());
}

//-----------------------------------------------------------------------
Clip *LevelThreadChannel::getNextClip() {
  
  Clip *clip;
  if (getLevelSettings()->isThreadedMovieLoad()) {
    if (nextClip.receive(clip)) {
      clipConsumed.send(true);
      return clip;
    } else {
      return NULL;
    }
  } else
    return createRandomClip();
}

//-----------------------------------------------------------------------
void LevelThreadChannel::threadedFunction() {
  // wait until there's a new frame
  // this blocks the thread, so it doesn't use
  // the CPU at all, until a frame arrives.
  // also receive doesn't allocate or make any copies
  bool b;
  while(clipConsumed.receive(b)){
    // The last clip was consumed, we must load a new one
    loadNextClip();
  }
}
