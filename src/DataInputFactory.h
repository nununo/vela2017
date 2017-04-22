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
#include "IDataInput.h"
#include "CalibrationSettings.h"

namespace DataInputType {
  const string DATA_INPUT_KEYBOARD = "keyboard";
  const string DATA_INPUT_MOUSE = "mouse";
  const string DATA_INPUT_AUTO_FLICKER = "autoFlicker";
  const string DATA_INPUT_ARDUINO = "arduino";
  const string DATA_INPUT_ANALOG = "analog";
}

class DataInputFactory {
public:
  
  virtual IDataInput* create(ofXml *xml, CalibrationSettings *calibrationSettings=NULL) = 0;
  
  static DataInputFactory* createFactory(string dataInputType);
};


#endif /* DataInputFactory_h */
