//
//  AutoFlickerInput.h
//  vela2017
//
//  Created by Nuno on 17/03/2017.
//
//

#ifndef AutoFlickerInput_h
#define AutoFlickerInput_h

#include "ofMain.h"
#include "DataInput.h"

class AutoFlickerInput: public DataInput {
public:
  AutoFlickerInput(int _minPeriod);
  ~AutoFlickerInput();

  // DataInput
  virtual void update();
  virtual BlowIntensity getBlowIntensity();

  // ITrace
  virtual std::string getTrace();
  
private:
  void onBlowIntensityChanged(BlowIntensity &e);

  int minPeriod;
  int lastTime;
  bool isFlickerTime;
};

#endif /* AutoFlickerInput_h */
