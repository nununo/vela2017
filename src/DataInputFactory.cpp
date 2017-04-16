//
//  DataInputFactory.cpp
//  vela2017
//
//  Created by Nuno on 16/04/2017.
//
//

#include "DataInputFactory.h"
#include "MouseInputFactory.h"
#include "KeyboardDataInputFactory.h"
#include "AutoFlickerDataInputFactory.h"
#include "ArduinoDataInputFactory.h"
#include "ValueInputFactory.h"

DataInputFactory* DataInputFactory::createFactory(string dataInputType) {
  
  if (dataInputType == DataInputType::DATA_INPUT_MOUSE)
    return new MouseInputFactory();
  
  else if (dataInputType == DataInputType::DATA_INPUT_KEYBOARD)
    return new KeyboardDataInputFactory();
  
  else if (dataInputType == DataInputType::DATA_INPUT_AUTO_FLICKER)
    return new AutoFlickerDataInputFactory();
  
  else if (dataInputType == DataInputType::DATA_INPUT_ARDUINO)
    return new ArduinoDataInputFactory();
  
  else if (dataInputType == DataInputType::DATA_INPUT_ANALOG)
    return new ValueInputFactory();
  
  else {
    ofLogError() << "Invalid input type " << dataInputType;
    return NULL;
  }
  
}

