//
//  DataInputFactory.h
//  vela2017
//
//  Created by Nuno on 15/04/2017.
//
//

#ifndef DataInputFactory_h
#define DataInputFactory_h

#include "ofMain.h"
#include "DataInput.h"
#include "ConfigXml.h"

namespace DataInputType {
  const string DATA_INPUT_KEYBOARD = "keyboard";
  const string DATA_INPUT_MOUSE = "mouse";
  const string DATA_INPUT_AUTO_FLICKER = "autoFlicker";
  const string DATA_INPUT_ARDUINO = "arduino";
}

class DataInputFactory {
public:  
  DataInput* create(ConfigXml *xml);
  
  static DataInputFactory* createFactory(string dataInputType);

private:
  virtual DataInput* createAux(ConfigXml *xml) = 0;

};

#endif /* DataInputFactory_h */
