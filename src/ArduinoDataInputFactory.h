//
//  ArduinoDataInputFactory.h
//  vela2017
//
//  Created by Nuno on 16/04/2017.
//
//

#ifndef ArduinoDataInputFactory_h
#define ArduinoDataInputFactory_h

#include "DataInputFactory.h"
#include "ArduinoDataInput.h"

class ArduinoDataInputFactory : public DataInputFactory {
public:
  virtual IDataInput* create(ofXml *xml);
  
private:
  void addDevices(ArduinoDataInput *arduinoDataInput, ofXml *xml);
  void addValueInputs(ArduinoDataInput *arduinoDataInput, ofXml *xml);
};

#endif /* ArduinoDataInputFactory_h */
