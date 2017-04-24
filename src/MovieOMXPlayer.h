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
  MovieOMXPlayer(string filename);
  virtual string getFilename() {return filename;}
  virtual bool isFinished() {return !movie.isPlaying();}
  virtual float getPosition() {return ((float)movie.getCurrentFrame())/(float)movie.getTotalNumFrames();}
  virtual float getDuration() {return movie.getDurationInSeconds();}
  virtual void rewind() {movie.restartMovie();}
  virtual void update() {}
  virtual void draw(float x, float y, float width, float height, int alpha);
  virtual void setPaused(bool pause=true) {movie.setPaused(pause);}
  virtual bool isPaused() {return movie.isPaused();}
  
private:
  string filename;
  ofxOMXPlayer movie;
};

#endif

#endif /* MovieOMXPlayer_h */
