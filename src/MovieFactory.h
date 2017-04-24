//
//  MovieFactory.h
//  vela2017
//
//  Created by Nuno on 24/04/2017.
//
//

#ifndef MovieFactory_h
#define MovieFactory_h

#include "IMovie.h"

class MovieFactory {
public:
  static IMovie* create(string filename);
};

#endif /* MovieFactory_h */
