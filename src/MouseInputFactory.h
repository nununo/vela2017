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
#include "Util.h"

class MouseInputFactory : public DataInputFactory {
public:
  virtual IDataInput* create(ofXml *xml, CalibrationSettings *calibrationSettings=NULL) {
    return new MouseInput(Util::stringToBool(xml->getAttribute("inverted")), calibrationSettings);
  }
};

#endif /* MouseInputFactory_h */
