#ifndef CLIPS_H_INCLUDED
#define CLIPS_H_INCLUDED

#include "Clip.h"
#include "GeneralSettings.h"

class Clips {

public:
  Clips(GeneralSettings _generalSettings, ClipOutputSettings _clipOutputSettings, LevelSettings *_levelSettings);
  Clip *getRandomClip();

private:
  void buildFilenameList();
  string getRandomFilename();
  
  GeneralSettings generalSettings;
  ClipOutputSettings clipOutputSettings;
  LevelSettings *levelSettings;

  vector<string> filenames;
};

#endif // CLIPS_H_INCLUDED
