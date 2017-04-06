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

#define ALPHA_MAX 255

class Clip {
public:
  Clip(ClipOutputSettings *_clipOutputSettings, LevelSettings *_levelSettings, string filename);
  void rewind();
  void pause(bool value=true);
  void update();
  void draw();
  bool isPlaying() {return (levelSettings->getLoop() || !movie->getIsMovieDone());}
  string getFilename() {return filename;};
  float getPosition() {return movie->getPosition();}
  float getSpeed() {return movie->getSpeed();}
  bool isOpaque() {return alpha == ALPHA_MAX;}
  int getAlpha() {return alpha;}

private:
  float timeToPercentage(float time);
  int calcAlpha();
  void setupMovie();

  ofVideoPlayer *movie;
  ClipOutputSettings *clipOutputSettings;
  LevelSettings *levelSettings;
  string filename;
  float fadeInPercentage;                 // Fade in percentage converted from fade in time
  float fadeOutPercentage;                // Fade out percentage converted from fade out time
  int alpha;                              // Alpha channel
};

#endif /* Clip_h */
