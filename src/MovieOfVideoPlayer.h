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
  MovieOfVideoPlayer(string filename, bool loop, ofColor color);
  ~MovieOfVideoPlayer();
  virtual string getFilename() override {return filename;}
  virtual float getPosition() override {return movie->getPosition();}
  virtual float getDuration() override {return movie->getDuration();}
  virtual void rewindAux() override {movie->setPosition(0); movie->play();}
  virtual void update() override {movie->update();}
  virtual void draw(float x, float y, float width, float height) override;
  virtual void setPaused(bool pause=true) override {movie->setPaused(pause);}
  virtual bool isPaused() override {return movie->isPaused();}
  virtual bool getLoop() override;

private:
  void setLoop(bool loop);
  
  string filename;
  ofVideoPlayer *movie;
  bool loop;
  ofColor color;
};


#endif /* MovieOfVideoPlayer_h */
