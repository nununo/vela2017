//
//  Clip.h
//  vela2017
//
//  Created by Nuno on 18/03/2017.
//
//

#ifndef Clip_h
#define Clip_h

#include "ofMain.h"
#include "GeneralSettings.h"
#include "ClipOutputSettings.h"
#include "LevelSettings.h"
#include "MovieBase.h"
#include "ITrace.h"

class Clip : public ITrace {
public:
  Clip(GeneralSettings generalSettings, ClipOutputSettings _clipOutputSettings, LevelSettings *_levelSettings, string filename);
  ~Clip();
  void rewind() {movie->rewind();}
  void pause(bool value=true);
  void update();
  void draw();
  bool isPlaying() {return (levelSettings->getLoop() || !movie->isFinished());}
  string getFilename() {return movie->getFilename();};
  float getPosition() {return movie->getPosition();}
  bool isOpaque() {return alpha == ALPHA_MAX;}
  int getAlpha() {return alpha;}
  bool getCanRestart() {return levelSettings->getCanRestart();}
  
  // ITrace
  string getTrace();
  
  bool isPreloaded() {return (levelSettings->getLevelType() == LevelType::PRELOAD);}

private:
  MovieBase* createMovie(GeneralSettings generalSettings, string filename);
  float timeToPercentage(float time);
  int calcAlpha();
  
  MovieBase *movie;
  ClipOutputSettings clipOutputSettings;
  LevelSettings *levelSettings;
  float fadeInPercentage;                 // Fade in percentage converted from fade in time
  float fadeOutPercentage;                // Fade out percentage converted from fade out time
  int alpha;                              // Alpha channel
};

#endif /* Clip_h */
