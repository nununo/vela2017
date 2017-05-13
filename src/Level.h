#ifndef LEVEL_H_INCLUDED
#define LEVEL_H_INCLUDED

#include "Clip.h"
#include "GeneralSettings.h"

class Level : public ofThread {

public:
  Level(GeneralSettings _generalSettings, ClipOutputSettings _clipOutputSettings, LevelSettings *_levelSettings);
  Clip *getNextClip();
  
private:
  Clip *createRandomClip();
  void loadNextClip();
  void threadedFunction();
  void buildFilenameList();
  string getRandomFilename();
  
  GeneralSettings generalSettings;
  ClipOutputSettings clipOutputSettings;
  LevelSettings *levelSettings;
  vector<string> filenames;

  ofThreadChannel<bool> clipConsumed;
  ofThreadChannel<Clip*> nextClip;
};

#endif // LEVEL_H_INCLUDED
