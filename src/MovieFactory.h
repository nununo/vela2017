//
//  MovieFactory.h
//  vela2017
//
//  Created by Nuno on 24/04/2017.
//
//

#ifndef MovieFactory_h
#define MovieFactory_h

#include "MovieBase.h"
#include "GeneralSettings.h"

class MovieFactory {
public:
  static MovieBase* create(string filename, bool loop, GeneralSettings generalSettings);
};

#endif /* MovieFactory_h */
