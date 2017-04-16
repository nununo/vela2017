//
//  ArduinoInputFactory.h
//  vela2017
//
//  Created by Nuno on 16/04/2017.
//
//

#ifndef ArduinoInputFactory_h
#define ArduinoInputFactory_h

#include "DataInputFactory.h"
#include "ArduinoInput.h"

class ArduinoInputFactory : public DataInputFactory {
public:
  virtual IDataInput* create(ofXml *xml);
  
private:
  void addDevices(ArduinoInput *arduinoInput, ofXml *xml);
  void addValueInputs(ArduinoInput *arduinoInput, ofXml *xml);
};

#endif /* ArduinoInputFactory_h */