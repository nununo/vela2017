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

class MouseDataInputFactory : public DataInputFactory {
public:
  virtual IDataInput* create(ofXml *xml) {return new MouseDataInput();}
};

#endif /* MouseDataInputFactory_h */
