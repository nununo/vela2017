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
  AutoFlickerInput(int _minPeriod);
  ~AutoFlickerInput() {};

  // IDataInput
  virtual void update();
  virtual blowIntensityType getBlowIntensity();

  // ITrace
  virtual string getTrace();
  
private:
  int minPeriod;
  int lastTime;
  bool isFlickerTime;
};

#endif /* AutoFlickerInput_h */
