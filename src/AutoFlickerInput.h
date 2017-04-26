//
//  AutoFlickerInput.h
//  vela2017
//
//  Created by Nuno on 17/03/2017.
//
//

#ifndef AutoFlickerInput_h
#define AutoFlickerInput_h

#include "DataInput.h"

class AutoFlickerInput: public DataInput {
public:
  AutoFlickerInput(int _minPeriod);
  ~AutoFlickerInput() {};

  // DataInput
  virtual void update();
  virtual blowIntensityType getBlowIntensity();

  // ITrace
  virtual std::string getTrace();
  
private:
  int minPeriod;
  int lastTime;
  bool isFlickerTime;
};

#endif /* AutoFlickerInput_h */
