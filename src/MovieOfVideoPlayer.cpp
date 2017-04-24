//
//  MovieOfVideoPlayer.cpp
//  vela2017
//
//  Created by Nuno on 24/04/2017.
//
//

#include "MovieOfVideoPlayer.h"

//--------------------------------------------------------------
MovieOfVideoPlayer::MovieOfVideoPlayer(string _filename, bool loop) {

  filename = _filename;
  
  movie = new ofVideoPlayer();

#ifdef TARGET_RASPBERRY_PI
  movie->setPixelFormat(OF_PIXELS_NATIVE);
#endif

  movie->load(filename);
  movie->play();
  setLoop(loop);
}

//--------------------------------------------------------------
void MovieOfVideoPlayer::setLoop(bool loop) {
  if (loop)
    movie->setLoopState(OF_LOOP_NORMAL);
  else
    movie->setLoopState(OF_LOOP_NONE);
}

//--------------------------------------------------------------
void MovieOfVideoPlayer::draw(float x, float y, float width, float height, int alpha) {
  if (alpha == ALPHA_MAX)
  {
    ofDisableAlphaBlending();
    ofSetHexColor(0xFFFFFF);
  } else {
    ofEnableAlphaBlending();
    ofSetColor(255, 255, 255, alpha);
  }
  
  movie->draw(x, y, width, height);
  
  ofDisableAlphaBlending();
}
