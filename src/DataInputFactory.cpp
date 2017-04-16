//
//  DataInputFactory.cpp
//  vela2017
//
//  Created by Nuno on 16/04/2017.
//
//

#include "DataInputFactory.h"
#include "MouseDataInputFactory.h"
#include "KeyboardDataInputFactory.h"
#include "AutoFlickerDataInputFactory.h"
#include "ArduinoDataInputFactory.h"
#include "AnalogDataInputFactory.h"

DataInputFactory* DataInputFactory::createFactory(string dataInputType) {
  
  if (dataInputType == DataInputType::DATA_INPUT_MOUSE)
    return new MouseDataInputFactory();
  
  else if (dataInputType == DataInputType::DATA_INPUT_KEYBOARD)
    return new KeyboardDataInputFactory();
  
  else if (dataInputType == DataInputType::DATA_INPUT_AUTO_FLICKER)
    return new AutoFlickerDataInputFactory();
  
  else if (dataInputType == DataInputType::DATA_INPUT_ARDUINO)
    return new ArduinoDataInputFactory();
  
  else if (dataInputType == DataInputType::DATA_INPUT_ANALOG)
    return new AnalogDataInputFactory();
  
  else {
    ofLogError() << "Invalid input type " << dataInputType;
    return NULL;
  }
  
}
