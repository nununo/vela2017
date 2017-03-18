//
//  ArduinoInput.h
//  vela2017
//
//  Created by Nuno on 16/03/2017.
//
//

#ifndef ArduinoInput_h
#define ArduinoInput_h

#include "IDataInput.h"
#include "ofMain.h"

#define ARDUINO_BUFFER_SIZE 500
#define ARDUINO_CALIBRATION_COUNT 20

class ArduinoInput: public IDataInput {
public:
  ArduinoInput(int _device, int _maxValue);
  virtual void setup();
  virtual void update();
  virtual float getValue() {return lastValue;}
  ~ArduinoInput();
  
private:
  void setValue(float _value);
  
  ofSerial serial;
  int lastValue;
  int offset;
  int maxValue; // limit beyond which values are ignored, to avoid strange values
  int buffer[ARDUINO_BUFFER_SIZE];
  int bufferCursor;
  
};

#endif /* ArduinoInput_h */
