//
//  AutoFlickerDataInput.h
//  vela2017
//
//  Created by Nuno on 17/03/2017.
//
//

#ifndef AutoFlickerDataInput_h
#define AutoFlickerDataInput_h

#include "IDataInput.h"

class AutoFlickerDataInput: public IDataInput {
public:
  AutoFlickerDataInput(int _minPeriod, float _flickerValue);
  virtual void update();
  virtual float getValue();
  ~AutoFlickerDataInput() {};
  
private:
  int minPeriod;
  int lastTime;
  float flickerValue;
  bool isFlickerTime;
};

#endif /* AutoFlickerDataInput_h */
