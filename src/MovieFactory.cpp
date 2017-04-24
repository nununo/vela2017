//
//  MovieFactory.cpp
//  vela2017
//
//  Created by Nuno on 24/04/2017.
//
//

#include "MovieFactory.h"
#include "MovieOfVideoPlayer.h"
#include "MovieOMXPlayer.h"

IMovie* MovieFactory::create(string filename, bool loop) {

#ifdef TARGET_RASPBERRY_PI
  return new MovieOMXPlayer(filename, loop);
#else
  return new MovieOfVideoPlayer(filename, loop);
#endif

}
