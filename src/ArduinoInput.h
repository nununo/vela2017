//
//  ArduinoInput.h
//  vela2017
//
//  Created by Nuno on 16/03/2017.
//
//

#ifndef ArduinoInput_h
#define ArduinoInput_h

#include "DataInput.h"
#include "ThresholdsDataInput.h"
#include "ofMain.h"
#include "Arduino.h"

class ArduinoInput: public DataInput {
public:
  ArduinoInput(string name, int inputId, ThresholdsDataInput *input);
  ~ArduinoInput() {};
  
  //DataInput
  virtual void update();
  virtual BlowIntensity getBlowIntensity() {return input->getBlowIntensity();}

  //ITrace
  virtual string getTrace();
  
private:
  Arduino *arduino;
  ThresholdsDataInput *input;
  int inputId;
};

#endif /* ArduinoInput_h */
