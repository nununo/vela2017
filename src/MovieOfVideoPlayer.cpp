//
//  MovieOfVideoPlayer.cpp
//  vela2017
//
//  Created by Nuno on 24/04/2017.
//
//

#include "MovieOfVideoPlayer.h"

//--------------------------------------------------------------
MovieOfVideoPlayer::MovieOfVideoPlayer(string _filename) {

  filename = _filename;
  
  movie = new ofVideoPlayer();

#ifdef TARGET_RASPBERRY_PI
  movie->setPixelFormat(OF_PIXELS_NATIVE);
#endif

  movie->load(filename);
  movie->play();
}

//--------------------------------------------------------------
void MovieOfVideoPlayer::setLoop(bool loop) {
  if (loop)
    movie->setLoopState(OF_LOOP_NORMAL);
  else
    movie->setLoopState(OF_LOOP_NONE);
}
