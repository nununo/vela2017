//
//  ArduinoInputFactory.h
//  vela2017
//
//  Created by Nuno on 16/04/2017.
//
//

#ifndef ArduinoInputFactory_h
#define ArduinoInputFactory_h

#include "ValueInputFactory.h"
#include "ArduinoInput.h"

class ArduinoInputFactory : public ValueInputFactory {
public:
  virtual DataInput* createAux(ofXml *xml, CalibrationSettings *calibrationSettings);
};

#endif /* ArduinoInputFactory_h */
