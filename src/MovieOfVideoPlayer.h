//
//  MovieOfVideoPlayer.h
//  vela2017
//
//  Created by Nuno on 24/04/2017.
//
//

#ifndef MovieOfVideoPlayer_h
#define MovieOfVideoPlayer_h

#include "IMovie.h"

class MovieOfVideoPlayer: public IMovie {
public:
  MovieOfVideoPlayer(string filename);
  virtual string getFilename() {return filename;}
  virtual bool isFinished() {return movie->getIsMovieDone();}
  virtual float getPosition() {return movie->getPosition();}
  virtual float getDuration() {return movie->getDuration();}
  virtual void rewind() {movie->setPosition(0); movie->play();}
  virtual void update() {movie->update();}
  virtual void draw(float x, float y, float width, float height) {movie->draw(x, y, width, height);}
  virtual void setPaused(bool pause=true) {movie->setPaused(pause);}
  virtual bool isPaused() {return movie->isPaused();}
  virtual void setLoop(bool loop);
  virtual void setAlpha(int alpha) {}

private:
  string filename;
  ofVideoPlayer *movie;
};


#endif /* MovieOfVideoPlayer_h */
