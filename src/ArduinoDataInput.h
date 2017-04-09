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
#include "AnalogInputSettings.h"
#include "ofMain.h"

class ArduinoDataInput: public IDataInput {
public:
  ArduinoDataInput(string _device, AnalogInputSettings *_settings);
  ~ArduinoDataInput() {};
  virtual void update();
  virtual blowIntensityType getBlowIntensity() {return settings->getBlowIntensity(lastValue); lastValue=BLOW_INTENSITY_LOW;}
  virtual string getTrace();
  
private:
  void setValue(int _value);
  
  ofSerial serial;
  AnalogInputSettings *settings;
  string device;
  int lastValue;
  int offset;  
};

#endif /* ArduinoDataInput_h */
