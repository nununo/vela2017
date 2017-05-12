#ifndef LEVEL_H_INCLUDED
#define LEVEL_H_INCLUDED

#include "Clip.h"
#include "GeneralSettings.h"

class Level {

public:
  Level(GeneralSettings _generalSettings, ClipOutputSettings _clipOutputSettings, LevelSettings *_levelSettings);
  Clip *getRandomClip();

private:
  void buildFilenameList();
  string getRandomFilename();
  
  GeneralSettings generalSettings;
  ClipOutputSettings clipOutputSettings;
  LevelSettings *levelSettings;

  vector<string> filenames;
};

#endif // LEVEL_H_INCLUDED
