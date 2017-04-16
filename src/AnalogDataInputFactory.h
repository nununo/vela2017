//
//  AnalogDataInputFactory.h
//  vela2017
//
//  Created by Nuno on 16/04/2017.
//
//

#ifndef AnalogDataInputFactory_h
#define AnalogDataInputFactory_h

#include "DataInputFactory.h"
#include "AnalogDataInput.h"

class AnalogDataInputFactory : public DataInputFactory {
public:
  virtual IDataInput* create(ofXml *xml) {return createTyped(xml);}
  AnalogDataInput* createTyped(ofXml *xml);
};

#endif /* AnalogDataInputFactory_h */
