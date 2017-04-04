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

#define ALPHA_MIN 20
#define ALPHA_MAX 255

class Clip {
public:
  Clip(ClipOutputSettings *_clipOutputSettings, string _filename, bool _loop, float fadeTime);
  void rewind() {movie->setPosition(0);movie->play();}
  void update();
  void draw();
  bool isPlaying() {return !movie->getIsMovieDone();}
  string getFilename() {return filename;};
  float getPosition() {return movie->getPosition();}
  float getSpeed() {return movie->getSpeed();}
  bool isOpaque() {return alpha == ALPHA_MAX;}
  int getAlpha() {return alpha;}

private:
  float timeToPercentage(float time);
  int calcAlpha();
  void setLoop(bool _loop);

  ClipOutputSettings *clipOutputSettings;
  ofVideoPlayer *loadMovie(string filename);
  string filename;
  ofVideoPlayer *movie;
  float loop;
  float fadePercentage; // Fade percentage converted from fade time
  int alpha;            // Alpha channel

  
};

#endif /* Clip_h */
