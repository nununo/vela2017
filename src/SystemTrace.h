//
//  SystemTrace.h
//  vela2017
//
//  Created by Nuno on 31/03/2017.
//
//

#ifndef SystemTrace_h
#define SystemTrace_h

#include "ITrace.h"

class SystemTrace : public ITrace {
  ~SystemTrace() {};
  virtual string getTrace();
};

#endif /* SystemTrace_h */
