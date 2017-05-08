#ifndef CLIPS_H_INCLUDED
#define CLIPS_H_INCLUDED

#include "Clip.h"
#include "GeneralSettings.h"

class Clips {

public:
  Clips(GeneralSettings _generalSettings, ClipOutputSettings _clipOutputSettings, LevelSettings *_levelSettings);
  Clip *getRandomClip();

  vector<Clip*> list;
  vector<string> filenames;

private:
  void buildFilenameList();
  string getRandomFilename();
  void buildClipList(GeneralSettings generalSettings, ClipOutputSettings clipOutputSettings, LevelSettings *levelSettings);
  
  GeneralSettings generalSettings;
  ClipOutputSettings clipOutputSettings;
  LevelSettings *levelSettings;
};

#endif // CLIPS_H_INCLUDED
