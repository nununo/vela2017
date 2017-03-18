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

#define ALPHA_MAX 255

class Clip {
public:
  Clip(string _filename, ofVideoPlayer *_movie, bool _loop, float fadeTime);
  void rewind_and_play();
  void update();
  void draw();
  
  static void configure(float _offsetX, float _offsetY, float _zoomX, float _zoomY) {offsetX = _offsetX; offsetY = _offsetY; zoomX = _zoomX; zoomY = _zoomY;}
  
private:
  float timeToPercentage(float time);
  void setLoop(bool _loop);
  void rewind();
  void stop() {movie->setSpeed(0);};
  void play() {movie->setSpeed(1);};
  bool isPlaying() {return movie->getSpeed() > 0;};
  int getAlpha();
  
  string filename;
  ofVideoPlayer *movie;
  bool loop;
  float fadePercentage;

  static float offsetX;
  static float offsetY;
  static float zoomX;
  static float zoomY;
  
};

#endif /* Clip_h */
