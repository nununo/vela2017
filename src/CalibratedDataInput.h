//
//  CalibratedDataInput.hpp
//  vela2017
//
//  Created by Nuno on 16/03/2017.
//
//

#ifndef CalibratedDataInput_h
#define CalibratedDataInput_h

#include "IDataInput.h"

class CalibratedDataInput: public IDataInput {
public:
  CalibratedDataInput(IDataInput *_dataInput);
  virtual void update();
  virtual float getValue() {return dataInput->getValue() + offset;}
  ~CalibratedDataInput() {};

private:
  void calibrate();
  bool calibrate1();
  bool calibrate2();
  IDataInput *dataInput;
  float offset;
};

#endif /* CalibratedDataInput_h */
