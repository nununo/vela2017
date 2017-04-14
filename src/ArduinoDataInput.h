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
  ArduinoDataInput(string _device, AnalogInputSettings *_settings1, AnalogInputSettings *_settings2, AnalogInputSettings *_settings3);
  ~ArduinoDataInput() {};
  virtual void update();
  virtual blowIntensityType getBlowIntensity();
  virtual string getTrace();
  bool isEnabled() {return serial.isInitialized();}
  
private:
  enum sensorIdType {
    ARDUINO_SENSOR0=0,
    ARDUINO_SENSOR1=1,
    ARDUINO_SENSOR2=2
  };
  
  ofSerial serial;
  string device;
  AnalogInputSettings *settings[3];
  int lastValue[3];

  void setValue(sensorIdType sensorId, int _value);
  string getSensorTrace(sensorIdType sensorId);
  void setupSensor(sensorIdType sensorId, AnalogInputSettings *_settings);
};

#endif /* ArduinoDataInput_h */
