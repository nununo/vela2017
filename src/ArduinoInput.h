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

class ArduinoInput: public DataInput {
public:
  ArduinoInput() : DataInput("arduino") {}
  ~ArduinoInput() {};
  
  void addDevice(string device) {devices.push_back(device);}
  void addInput(ThresholdsDataInput *input);
  bool connect();
  bool isEnabled() {return serial.isInitialized();}
  
  //DataInput
  virtual void update();
  virtual BlowIntensity getBlowIntensity();

  //ITrace
  virtual string getTrace();
  
private:
  vector<string> devices;
  vector<ThresholdsDataInput*> inputs;
  ofSerial serial;
  string device;
};

#endif /* ArduinoInput_h */
