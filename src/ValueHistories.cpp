//
//  ValueHistories.cpp
//  vela2017
//
//  Created by Nuno on 26/04/2017.
//
//

#include "ValueHistories.h"

//--------------------------------------------------------------
std::vector<std::string> ValueHistories::getKeys() {
  std::vector<std::string> v;
  
  for ( auto it = histories.begin(); it != histories.end(); ++it )
    v.push_back(it->first);
  
  return v;
}
