//
//  SystemInfo.h
//  vela2017
//
//  Created by Nuno on 31/03/2017.
//
//

#ifndef SystemInfo_h
#define SystemInfo_h

#include "ITrace.h"

class SystemInfo : public ITrace {
  ~SystemInfo() {};
  virtual std::string getTrace();
};

#endif /* SystemInfo_h */
