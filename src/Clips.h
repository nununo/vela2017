#ifndef CLIPS_H_INCLUDED
#define CLIPS_H_INCLUDED

#include "Clip.h"

class Clips {

public:
  Clips(ClipOutputSettings *clipOutputSettings, LevelSettings *levelSettings);
  Clip *getRandomClip();

  vector<Clip*> list;

private:
  void buildClipList(ClipOutputSettings *clipOutputSettings, LevelSettings *levelSettings);
};

#endif // CLIPS_H_INCLUDED
