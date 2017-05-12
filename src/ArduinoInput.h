//
//  ArduinoInput.h
//  vela2017
//
//  Created by Nuno on 16/03/2017.
//
//

#ifndef ArduinoInput_h
#define ArduinoInput_h

#include "CalibratedValueInput.h"
#include "ofMain.h"

class ArduinoInput: public DataInput {
public:
  ArduinoInput(string device, Thresholds thresholds, CalibrationSettings calibrationSettings);
  ~ArduinoInput() {delete input; input = NULL;};
  bool isConnected() {return serial.isInitialized();}

  //DataInput
  virtual void update();
  virtual BlowIntensity getBlowIntensity() {return input->getBlowIntensity();}

  //ITrace
  virtual string getTrace();
  
private:
  bool connect();
  void readValueFromSerial();
  
  ofSerial serial;
  ValueInput *input;
  string device;
  int lastValue;
};

#endif /* ArduinoInput_h */
