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
#include "IMovie.h"

class MovieOMXPlayer: public IMovie {
public:
  MovieOMXPlayer(string filename, bool _loop);
  virtual string getFilename() {return filename;}
  virtual bool isFinished() {return finished;}
  virtual float getPosition() {return ((float)movie.getCurrentFrame())/(float)movie.getTotalNumFrames();}
  virtual float getDuration() {return movie.getDurationInSeconds();}
  virtual void rewind() {finished=false; lastPosition=-1; movie.restartMovie();}
  virtual void update();
  virtual void draw(float x, float y, float width, float height);
  virtual void setPaused(bool pause=true) {movie.setPaused(pause);}
  virtual bool isPaused() {return movie.isPaused();}
  
private:
  void calcFinished();
  
  string filename;
  float lastPosition;
  bool finished;
  bool loop;
  ofxOMXPlayer movie;
};

#endif

#endif /* MovieOMXPlayer_h */
