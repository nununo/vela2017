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
#include "BlowIntensity.h"

class DataInput : public ITrace {
public:
  DataInput(std::string _name) {name=_name;}
  virtual ~DataInput() {}
  virtual void update() = 0;
  virtual BlowIntensity getBlowIntensity() = 0;
  std::string getName() {return name;}

private:
  std::string name;
};

#endif /* DataInput_h */
