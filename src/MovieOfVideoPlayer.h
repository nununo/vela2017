//
//  MovieOfVideoPlayer.h
//  vela2017
//
//  Created by Nuno on 24/04/2017.
//
//

#ifndef MovieOfVideoPlayer_h
#define MovieOfVideoPlayer_h

#include "MovieBase.h"

class MovieOfVideoPlayer: public MovieBase {
public:
  MovieOfVideoPlayer(string filename, bool loop);
  ~MovieOfVideoPlayer();
  virtual string getFilename() {return filename;}
  virtual bool isFinished() {return movie->getIsMovieDone();}
  virtual float getPosition() {return movie->getPosition();}
  virtual float getDuration() {return movie->getDuration();}
  virtual void rewind() {movie->setPosition(0); movie->play();}
  virtual void update() {movie->update();}
  virtual void draw(float x, float y, float width, float height);
  virtual void setPaused(bool pause=true) {movie->setPaused(pause);}
  virtual bool isPaused() {return movie->isPaused();}
  virtual bool getLoop();

private:
  void setLoop(bool loop);
  
  string filename;
  ofVideoPlayer *movie;
  bool loop;
};


#endif /* MovieOfVideoPlayer_h */
