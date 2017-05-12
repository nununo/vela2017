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

MovieBase* MovieFactory::create(string filename, bool loop, bool useOMXPlayer) {

#ifdef TARGET_RASPBERRY_PI
  if (useOmxPlayer)
    return new MovieOMXPlayer(filename, loop);
  else
    return new MovieOfVideoPlayer(filename, loop);
#else
  return new MovieOfVideoPlayer(filename, loop);
#endif

}
