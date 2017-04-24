//
//  MovieFactory.cpp
//  vela2017
//
//  Created by Nuno on 24/04/2017.
//
//

#include "MovieFactory.h"
#include "MovieOfVideoPlayer.h"

IMovie* MovieFactory::create(string filename) {

#ifdef TARGET_RASPBERRY_PI
  return new MovieOfVideoPlayer(filename);
#else
  return new MovieOfVideoPlayer(filename);
#endif

}
