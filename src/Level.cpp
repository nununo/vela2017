#include "Level.h"

//-----------------------------------------------------------------------
Level::Level(GeneralSettings _generalSettings, ClipOutputSettings _clipOutputSettings, LevelSettings *_levelSettings) {
  
  generalSettings = _generalSettings;
  clipOutputSettings = _clipOutputSettings;
  levelSettings = _levelSettings;
  
  buildFilenameList();
  
  // initialize random seed
  srand(time(NULL));

  if (levelSettings->isThreadedMovieLoad()) {
    // start the thread as soon as the class is created
    // it won't use any CPU until we send a new frame to be analyzed
    startThread();

    // We immediately loading the next clip
    loadNextClip();
  }
}

//-----------------------------------------------------------------------
string Level::getRandomFilename() {
  // Select a random filename from vector
  int i = filenames.size();
  i = rand() % i;
  return filenames.at(i);
}

//-----------------------------------------------------------------------
Clip *Level::createRandomClip() {
  return new Clip(generalSettings,
                  clipOutputSettings,
                  levelSettings,
                  getRandomFilename());
}

//-----------------------------------------------------------------------
void Level::loadNextClip() {
  nextClip.send(createRandomClip());
}

//-----------------------------------------------------------------------
void Level::buildFilenameList() {
  
  ofDirectory oDir;
  
  int nFiles = oDir.listDir(levelSettings->getMovieFolder());
  
  for(int i = 0; i < nFiles; i++)
    filenames.push_back(oDir.getPath(i));
}

//-----------------------------------------------------------------------
Clip *Level::getNextClip() {
  
  Clip *clip;
  if (levelSettings->isThreadedMovieLoad()) {
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
void Level::threadedFunction() {
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
