#ifndef LEVEL_H_INCLUDED
#define LEVEL_H_INCLUDED

#include "Clip.h"
#include "GeneralSettings.h"

class Level {

public:
  Level(GeneralSettings generalSettings, ClipOutputSettings clipOutputSettings, LevelSettings *levelSettings);
  virtual Clip *getNextClip() = 0;

protected:
  string getRandomFilename();
  Clip *createClip(string filename);
  vector<string> getFilenames() const {return filenames;}
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
