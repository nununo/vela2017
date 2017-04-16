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
#include "ValueInput.h"
#include "ofMain.h"


class ArduinoInput: public IDataInput {
public:
  ~ArduinoInput() {};
  
  void addDevice(string device) {devices.push_back(device);}
  void addValueInput(ValueInput *valueInput);
  bool connect();
  bool isEnabled() {return serial.isInitialized();}
  
  //IDataInput
  virtual void update();
  virtual blowIntensityType getBlowIntensity();

  //ITrace
  virtual string getTrace();
  
private:
  vector<string> devices;
  vector<ValueInput*> valueInputs;
  ofSerial serial;
  string device;
};

#endif /* ArduinoInput_h */
