//
//  MovieOfVideoPlayer.cpp
//  vela2017
//
//  Created by Nuno on 24/04/2017.
//
//

#include "MovieOfVideoPlayer.h"

//--------------------------------------------------------------
MovieOfVideoPlayer::MovieOfVideoPlayer(string _filename, bool loop, ofColor _color) {

  filename = _filename;
  color = _color;
  
  movie = new ofVideoPlayer();
  movie->load(filename);
  movie->play();
  setLoop(loop);
}

//--------------------------------------------------------------
MovieOfVideoPlayer::~MovieOfVideoPlayer() {
  delete movie;
  movie = NULL;
}

//--------------------------------------------------------------
void MovieOfVideoPlayer::setLoop(bool _loop) {
  loop = _loop;
  if (loop)
    movie->setLoopState(OF_LOOP_NORMAL);
  else
    movie->setLoopState(OF_LOOP_NONE);
}

//--------------------------------------------------------------
bool MovieOfVideoPlayer::getLoop() {
  return loop;
// This doesn't work and I don't understand why. movie->getLoopState() always returns OF_LOOP_NORMAL
//  ofLoopType loopType = movie->getLoopState();
//  bool loop = (loopType == OF_LOOP_NORMAL);
//  return loop;
}

//--------------------------------------------------------------
void MovieOfVideoPlayer::draw(float x, float y, float width, float height) {
  if (getAlpha() == ALPHA_MAX)
  {
    ofDisableAlphaBlending();
    ofSetColor(color);
  } else {
    ofEnableAlphaBlending();
    ofSetColor(color, getAlpha());
  }
  
  movie->draw(x, y, width, height);
  
  ofDisableAlphaBlending();
}
