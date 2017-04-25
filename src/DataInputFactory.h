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
  DataInput* create(ofXml *xml, CalibrationSettings *calibrationSettings=NULL);
  
  static DataInputFactory* createFactory(string dataInputType);

private:
  virtual DataInput* createAux(ofXml *xml, CalibrationSettings *calibrationSettings) = 0;

};


#endif /* DataInputFactory_h */
