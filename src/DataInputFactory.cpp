//
//  DataInputFactory.cpp
//  vela2017
//
//  Created by Nuno on 16/04/2017.
//
//

#include "DataInputFactory.h"
#include "MouseInputFactory.h"
#include "KeyboardInputFactory.h"
#include "AutoFlickerInputFactory.h"
#include "ArduinoInputFactory.h"

//--------------------------------------------------------------
DataInputFactory* DataInputFactory::createFactory(string dataInputType) {
  
  if (dataInputType == DataInputType::DATA_INPUT_MOUSE)
    return new MouseInputFactory();
  
  else if (dataInputType == DataInputType::DATA_INPUT_KEYBOARD)
    return new KeyboardInputFactory();
  
  else if (dataInputType == DataInputType::DATA_INPUT_AUTO_FLICKER)
    return new AutoFlickerInputFactory();
  
  else if (dataInputType == DataInputType::DATA_INPUT_ARDUINO)
    return new ArduinoInputFactory();

  else {
    ofLogError() << "Invalid input type " << dataInputType;
    return NULL;
  }
}

//--------------------------------------------------------------
DataInput* DataInputFactory::create(ConfigXml *xml) {
  return createAux(xml);
}
