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
  AutoFlickerDataInput(int _minPeriod);
  ~AutoFlickerDataInput() {};

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

#endif /* AutoFlickerDataInput_h */
