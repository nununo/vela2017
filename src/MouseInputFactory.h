//
//  MouseInputFactory.h
//  vela2017
//
//  Created by Nuno on 16/04/2017.
//
//

#ifndef MouseInputFactory_h
#define MouseInputFactory_h

#include "DataInputFactory.h"
#include "MouseInput.h"

class MouseInputFactory : public DataInputFactory {
public:
  virtual DataInput* createAux(ofXml *xml, CalibrationSettings *calibrationSettings);
};

#endif /* MouseInputFactory_h */
