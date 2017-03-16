//
//  CalibratedInput.hpp
//  vela2017
//
//  Created by Nuno on 16/03/2017.
//
//

#ifndef CalibratedInput_h
#define CalibratedInput_h

#include "IDataInput.h"

class CalibratedInput: public IDataInput {
public:
  CalibratedInput(IDataInput *_dataInput);
  virtual void setup();
  virtual void update();
  virtual float getValue() {return dataInput->getValue() + offset;}
  ~CalibratedInput() {};

private:
  void calibrate();
  bool calibrate1();
  bool calibrate2();
  IDataInput *dataInput;
  float offset;
};

#endif /* CalibratedInput_h */
