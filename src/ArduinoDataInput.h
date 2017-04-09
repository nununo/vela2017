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
  ArduinoDataInput(string _device, int _minValue, int _maxValue);
  ~ArduinoDataInput() {};
  virtual void update();
  virtual blowIntensityType getBlowIntensity();
  virtual string getTrace();
  
private:
  void setValue(int _value);
  
  ofSerial serial;
  string device;
  int lastValue;
  int offset;
  int minValue; // lower sensor limit below which values are ignored, to avoid strange values
  int maxValue; // upper sensor limit beyond which values are ignored, to avoid strange values
  
};

#endif /* ArduinoDataInput_h */
