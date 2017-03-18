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

#define ARDUINO_BUFFER_SIZE 500
#define ARDUINO_CALIBRATION_COUNT 20

class ArduinoDataInput: public IDataInput {
public:
  ArduinoDataInput(int _device, int _maxValue);
  virtual void setup();
  virtual void update();
  virtual float getValue() {return lastValue;}
  ~ArduinoDataInput();
  
private:
  void setValue(float _value);
  
  ofSerial serial;
  int lastValue;
  int offset;
  int maxValue; // limit beyond which values are ignored, to avoid strange values
  int buffer[ARDUINO_BUFFER_SIZE];
  int bufferCursor;
  
};

#endif /* ArduinoDataInput_h */
