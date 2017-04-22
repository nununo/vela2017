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
  virtual IDataInput* createAux(ofXml *xml, CalibrationSettings *calibrationSettings);
  
private:
  void addDevices(ArduinoInput *arduinoInput, ofXml *xml);
  void addValueInputs(ArduinoInput *arduinoInput, ofXml *xml, CalibrationSettings *calibrationSettings);
};

#endif /* ArduinoInputFactory_h */
