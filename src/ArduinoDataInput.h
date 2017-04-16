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
#include "AnalogDataInput.h"
#include "ofMain.h"


class ArduinoDataInput: public IDataInput {
public:
  ~ArduinoDataInput() {};
  
  void addDevice(string device) {devices.push_back(device);}
  void addAnalogDataInput(AnalogDataInput *analogDataInput);
  bool connect();
  bool isEnabled() {return serial.isInitialized();}
  
  //IDataInput
  virtual void update();
  virtual blowIntensityType getBlowIntensity();

  //ITrace
  virtual string getTrace();
  
private:
  vector<string> devices;
  vector<AnalogDataInput*> analogDataInputs;
  ofSerial serial;
  string device;
};

#endif /* ArduinoDataInput_h */
