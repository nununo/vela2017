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
  void rewind_and_play() {rewind(); play();}
  void update();
  virtual void drawAlgorithm();
  string getFilename() {return filename;};

private:
  ClipOutputSettings *clipOutputSettings;
  ofVideoPlayer *loadMovie(string filename);
  float timeToPercentage(float time);
  void setLoop(bool _loop);
  void rewind() {movie->setPosition(0);}
  void play() {setVisible(true); movie->setSpeed(1);}
  void stop() {setVisible(false); movie->setSpeed(0);}
  int getAlpha();
  bool isOpaque() {return movie->getPosition() > fadePercentage;}
  
  string filename;
  ofVideoPlayer *movie;
  bool loop;
  float fadePercentage;

  
};

#endif /* Clip_h */
