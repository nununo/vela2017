#include "Clips.h"

//-----------------------------------------------------------------------
Clips::Clips(GeneralSettings _generalSettings, ClipOutputSettings _clipOutputSettings, LevelSettings *_levelSettings) {

  generalSettings = _generalSettings;
  clipOutputSettings = _clipOutputSettings;
  levelSettings = _levelSettings;
  
  buildFilenameList();
  
  // initialize random seed
  srand(time(NULL));
}

//-----------------------------------------------------------------------
string Clips::getRandomFilename() {
  // Select a random filename from vector
  int i = filenames.size();
  i = rand() % i;
  return filenames.at(i);
}

//-----------------------------------------------------------------------
Clip *Clips::getRandomClip() {
  return new Clip(generalSettings,
                        clipOutputSettings,
                        levelSettings,
                        getRandomFilename());
}

//-----------------------------------------------------------------------
void Clips::buildFilenameList() {
  
  ofDirectory oDir;
  
  int nFiles = oDir.listDir(levelSettings->getMovieFolder());
  
  for(int i = 0; i < nFiles; i++)
    filenames.push_back(oDir.getPath(i));
}
