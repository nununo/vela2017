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
#include "AnalogInput.h"
#include "ofMain.h"


class ArduinoDataInput: public IDataInput {
public:
  ArduinoDataInput(string _device);
  ~ArduinoDataInput() {};
  
  void addAnalogInput(AnalogInput *analogInput);
  bool isEnabled() {return serial.isInitialized();}
  
  //IDataInput
  virtual void update();
  virtual blowIntensityType getBlowIntensity();

  //ITrace
  virtual string getTrace();
  
private:
  vector<AnalogInput*> analogInputs;
  ofSerial serial;
  string device;
};

#endif /* ArduinoDataInput_h */
