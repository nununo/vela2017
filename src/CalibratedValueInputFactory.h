//
//  CalibratedValueInputFactory.h
//  vela2017
//
//  Created by Nuno on 27/04/2017.
//
//

#ifndef CalibratedValueInputFactory_h
#define CalibratedValueInputFactory_h

#include "ValueInputFactory.h"
#include "CalibrationSettings.h"
#include "CalibratedValueInput.h"

class CalibratedValueInputFactory : public ValueInputFactory {
public:
  virtual DataInput* createAux(ofXml *xml, CalibrationSettings calibrationSettings);
};

#endif /* CalibratedValueInputFactory_h */
