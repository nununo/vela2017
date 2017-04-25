//
//  ValueInputFactory.h
//  vela2017
//
//  Created by Nuno on 16/04/2017.
//
//

#ifndef ValueInputFactory_h
#define ValueInputFactory_h

#include "DataInputFactory.h"
#include "CalibrationSettings.h"

class ValueInputFactory : public DataInputFactory {
public:
  virtual DataInput* createAux(ofXml *xml, CalibrationSettings *calibrationSettings, string namePrefix);
};

#endif /* ValueInputFactory_h */
