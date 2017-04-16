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

class ValueInputFactory : public DataInputFactory {
public:
  virtual IDataInput* create(ofXml *xml);
};

#endif /* ValueInputFactory_h */
