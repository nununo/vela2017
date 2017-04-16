//
//  KeyboardDataInputFactory.h
//  vela2017
//
//  Created by Nuno on 16/04/2017.
//
//

#ifndef KeyboardDataInputFactory_h
#define KeyboardDataInputFactory_h

#include "DataInputFactory.h"
#include "KeyboardDataInput.h"

class KeyboardDataInputFactory : public DataInputFactory {
public:
  virtual IDataInput* create(ofXml *xml) {return new KeyboardDataInput();}
};

#endif /* KeyboardDataInputFactory_h */
