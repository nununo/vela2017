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
  virtual IDataInput* create(ofXml *xml) {return new MouseInput(Util::stringToBool(xml->getAttribute("inverted")),
                                                                Util::stringToBool(xml->getAttribute("calibrated")));}
};

#endif /* MouseInputFactory_h */
