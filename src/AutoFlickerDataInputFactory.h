//
//  AutoFlickerDataInputFactory.h
//  vela2017
//
//  Created by Nuno on 16/04/2017.
//
//

#ifndef AutoFlickerDataInputFactory_h
#define AutoFlickerDataInputFactory_h

#include "DataInputFactory.h"

class AutoFlickerDataInputFactory : public DataInputFactory {
public:
  virtual IDataInput* create(ofXml *xml);
};

#endif /* AutoFlickerDataInputFactory_h */
