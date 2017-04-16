//
//  MouseDataInputFactory.h
//  vela2017
//
//  Created by Nuno on 16/04/2017.
//
//

#ifndef MouseDataInputFactory_h
#define MouseDataInputFactory_h

#include "DataInputFactory.h"
#include "MouseDataInput.h"
#include "Util.h"

class MouseDataInputFactory : public DataInputFactory {
public:
  virtual IDataInput* create(ofXml *xml) {return new MouseDataInput(Util::stringToBool(xml->getAttribute("inverted")));}
};

#endif /* MouseDataInputFactory_h */
