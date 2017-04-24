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
#include "ClipOutputSettings.h"
#include "LevelSettings.h"
#include "IMovie.h"

class Clip {
public:
  Clip(ClipOutputSettings *_clipOutputSettings, LevelSettings *_levelSettings, IMovie *movie);
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

private:
  float timeToPercentage(float time);
  int calcAlpha();
  
  IMovie *movie;
  ClipOutputSettings *clipOutputSettings;
  LevelSettings *levelSettings;
  float fadeInPercentage;                 // Fade in percentage converted from fade in time
  float fadeOutPercentage;                // Fade out percentage converted from fade out time
  int alpha;                              // Alpha channel
};

#endif /* Clip_h */
