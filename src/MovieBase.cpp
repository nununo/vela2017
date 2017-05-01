//
//  MovieBase.cpp
//  vela2017
//
//  Created by Nuno on 01/05/2017.
//
//

#include "MovieBase.h"
#include <ostream>

string MovieBase::getTrace() {
  stringstream ss;
  
  ss << "Filename: " << getFilename()
  << " Position: " << roundf(getPosition()*100)/100
  << " Loop: " << getLoop();
  
  return ss.str();

}
