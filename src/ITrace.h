//
//  ITrace.h
//  vela2017
//
//  Created by Nuno on 15/03/2017.
//
//

#ifndef ITrace_h
#define ITrace_h

#include <string>

class ITrace {
public:
  virtual ~ITrace() {}
  virtual std::string getTrace() = 0;
};

#endif /* ITrace_h */
