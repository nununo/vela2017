//
//  ArduinoDataInput.h
//  vela2017
//
//  Created by Nuno on 16/03/2017.
//
//

#ifndef ArduinoDataInput_h
#define ArduinoDataInput_h

#include "IDataInput.h"
#include "ofMain.h"

class ArduinoDataInput: public IDataInput {
public:
  ArduinoDataInput(int _device, int _minValue, int _maxValue);
  ~ArduinoDataInput() {};
  virtual void update();
  virtual float getValue();
  virtual string getTrace();
  
private:
  void setValue(float _value);
  
  ofSerial serial;
  int device;
  int lastValue;
  int offset;
  int minValue; // lower sensor limit below which values are ignored, to avoid strange values
  int maxValue; // upper sensor limit beyond which values are ignored, to avoid strange values
  
};

#endif /* ArduinoDataInput_h */
