//
//  AutoFlickerInput.h
//  vela2017
//
//  Created by Nuno on 17/03/2017.
//
//

#ifndef AutoFlickerInput_h
#define AutoFlickerInput_h

#include "IDataInput.h"

class AutoFlickerInput: public IDataInput {
public:
  AutoFlickerInput(int _minPeriod, float _flickerValue);
  virtual void setup();
  virtual void update();
  virtual float getValue();
  ~AutoFlickerInput() {};
  
private:
  int minPeriod;
  int lastTime;
  float flickerValue;
  bool isFlickerTime;
};

#endif /* AutoFlickerInput_h */
