//
//  IDataInput.h
//  vela2017
//
//  Created by Nuno on 14/03/2017.
//
//

#ifndef IDataInput_h
#define IDataInput_h

#include "ITrace.h"

class IDataInput : public ITrace {
public:
  virtual ~IDataInput() {}
  virtual void update() = 0;
  virtual float getValue() = 0;
};

#endif /* IDataInput_h */
