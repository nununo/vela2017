//
//  IInfo.h
//  vela2017
//
//  Created by Nuno on 15/03/2017.
//
//

#ifndef IInfo_h
#define IInfo_h

#include "ofMain.h"

class IInfo {
public:
  virtual ~IInfo() {}
  virtual string getInfo() = 0;
};

#endif /* IInfo_h */
