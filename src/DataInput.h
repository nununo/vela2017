//
//  DataInput.h
//  vela2017
//
//  Created by Nuno on 14/03/2017.
//
//

#ifndef DataInput_h
#define DataInput_h

#include "ITrace.h"
#include "Constants.h"

class DataInput : public ITrace {
public:
  DataInput(string _name) {name=_name;}
  virtual ~DataInput() {}
  virtual void update() = 0;
  virtual blowIntensityType getBlowIntensity() = 0;
  string getName() {return name;}

private:
  string name;
};

#endif /* DataInput_h */
