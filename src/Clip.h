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

#define ALPHA_MAX 255
#define FREEZE_FRAMES_MAX 4

class Clip {
public:
  Clip(ClipOutputSettings *_clipOutputSettings, string _filename, bool _loop, float fadeTime);
  void play() {movie->setPosition(0); lastPosition=0; movie->setSpeed(1); movie->play();}
  void update();
  void draw();
  bool isPlaying() {return movie->getSpeed()>0;}
  string getFilename() {return filename;};
  float getPosition() {return lastPosition;}
  bool isOpaque() {return alpha == ALPHA_MAX;}
  int getAlpha() {return alpha;}

private:
  float timeToPercentage(float time);
  int calcAlpha();
  void setLoop(bool _loop);
  void stop() { movie->setSpeed(0); }

  ClipOutputSettings *clipOutputSettings;
  ofVideoPlayer *loadMovie(string filename);
  string filename;
  ofVideoPlayer *movie;
  float loop;
  float fadePercentage; // Fade percentage converted from fade time
  int alpha;            // Alpha channel
  float lastPosition;   // To check if the video is frozen
  int freezeCount;      // Count how many frames the movie doesn't move

  
};

#endif /* Clip_h */
