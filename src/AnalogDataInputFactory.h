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

class AnalogDataInputFactory : public DataInputFactory {
public:
  virtual IDataInput* create(ofXml *xml);
};

#endif /* AnalogDataInputFactory_h */
