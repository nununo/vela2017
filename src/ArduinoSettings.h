//
//  ArduinoSettings.h
//  vela2017
//
//  Created by Nuno on 30/04/2017.
//
//

#ifndef ArduinoSettings_h
#define ArduinoSettings_h

#include <vector>

class ArduinoSettings {
public:
  void addDevice(string device) {devices.push_back(device);}
  std::vector<string> getDevices() {return devices;}

private:
  std::vector<string> devices;
};

#endif /* ArduinoSettings_h */
