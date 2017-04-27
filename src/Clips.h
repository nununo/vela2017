#ifndef CLIPS_H_INCLUDED
#define CLIPS_H_INCLUDED

#include "Clip.h"
#include "GeneralSettings.h"

class Clips {

public:
  Clips(GeneralSettings generalSettings, ClipOutputSettings clipOutputSettings, LevelSettings *levelSettings);
  Clip *getRandomClip();

  vector<Clip*> list;

private:
  void buildClipList(GeneralSettings generalSettings, ClipOutputSettings clipOutputSettings, LevelSettings *levelSettings);
};

#endif // CLIPS_H_INCLUDED
