//
//  MovieOMXPlayer.h
//  vela2017
//
//  Created by Nuno on 24/04/2017.
//
//

#ifndef MovieOMXPlayer_h
#define MovieOMXPlayer_h

#ifdef TARGET_RASPBERRY_PI

#include "ofxOMXPlayer.h"
#include "MovieBase.h"

class MovieOMXPlayer: public MovieBase {
public:
  MovieOMXPlayer(string filename, bool _loop, ofColor color);
  virtual string getFilename() {return filename;}
  virtual float getPosition() {return ((float)movie.getCurrentFrame())/(float)movie.getTotalNumFrames();}
  virtual float getDuration() {return movie.getDurationInSeconds();}
  virtual void rewindAux() {movie.restartMovie();}
  virtual void update();
  virtual void draw(float x, float y, float width, float height);
  virtual void setPaused(bool pause=true) {movie.setPaused(pause);}
  virtual bool isPaused() {return movie.isPaused();}
  virtual bool getLoop();
  
private:
  void calcFinished();
  
  string filename;
  ofxOMXPlayer movie;
  ofColor color;
};

#endif

#endif /* MovieOMXPlayer_h */
