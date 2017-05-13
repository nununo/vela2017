#ifndef LEVEL_H_INCLUDED
#define LEVEL_H_INCLUDED

#include "Clip.h"
#include "GeneralSettings.h"

class Level {

public:
  Level(GeneralSettings _generalSettings, ClipOutputSettings _clipOutputSettings, LevelSettings *_levelSettings);
  virtual Clip *getNextClip() = 0;

protected:
  string getRandomFilename();
  GeneralSettings getGeneralSettings() const {return generalSettings;}
  ClipOutputSettings getClipOutputSettings() const {return clipOutputSettings;}
  LevelSettings *getLevelSettings() const {return levelSettings;}

private:
  void buildFilenameList();

  GeneralSettings generalSettings;
  ClipOutputSettings clipOutputSettings;
  LevelSettings *levelSettings;
  vector<string> filenames;
};

#endif // LEVEL_H_INCLUDED
