//
//  Arduino.h
//  vela2017
//
//  Created by Nuno on 30/04/2017.
//
//

#ifndef Arduino_h
#define Arduino_h

#include "ITrace.h"
#include "ofMain.h"
#include "ArduinoSettings.h"

class Arduino : public ITrace {
public:
  ~Arduino() {};
  bool setup(ArduinoSettings _settings);
  bool connect();
  bool isEnabled() {return serial.isInitialized();}
  float getValue(int index) {return values[index];}

  virtual void update();

  //ITrace
  virtual std::string getTrace();

  static Arduino& getInstance();    // Singleton
  Arduino(Arduino const&) = delete;
  void operator=(Arduino const&) = delete;

private:
  Arduino() {}

  ArduinoSettings settings;
  ofSerial serial;
  string device;
  float values[2] = {0,0};
};

#endif /* Arduino_h */
