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
#include "Drawable.h"

#define ALPHA_MAX 255

class Clip : public Drawable {
public:
  Clip(ClipOutputSettings *_clipOutputSettings, string _filename, bool _loop, float fadeTime);
  void rewind_and_play();
  void update();
  virtual void drawAlgorithm();
  string getFilename() {return filename;};
  bool isOpaque() {return movie->getPosition() > fadePercentage;}
  bool isPlaying() {return movie->getSpeed() > 0;};

private:
  ClipOutputSettings *clipOutputSettings;
  ofVideoPlayer *loadMovie(string filename);
  float timeToPercentage(float time);
  void setLoop(bool _loop);
  void rewind();
  void stop() {movie->setSpeed(0);};
  void play() {movie->setSpeed(1);};
  int getAlpha();
  
  string filename;
  ofVideoPlayer *movie;
  bool loop;
  float fadePercentage;

  
};

#endif /* Clip_h */
