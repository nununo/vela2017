//
//  ArduinoInputFactory.cpp
//  vela2017
//
//  Created by Nuno on 16/04/2017.
//
//

#include "ArduinoInputFactory.h"
#include "ThresholdsDataInputFactory.h"

//--------------------------------------------------------------
DataInput* ArduinoInputFactory::createAux(ofXml *xml, CalibrationSettings *calibrationSettings) {
  
  ArduinoInput *arduinoInput = NULL;
  
  if (Arduino::getInstance().isEnabled()) {
    
    ThresholdsDataInput *input=
      (ThresholdsDataInput*)DataInputFactory::createFactory(DataInputType::DATA_INPUT_THRESHOLD)->create(xml, calibrationSettings);

    arduinoInput =
      new ArduinoInput(xml->getAttribute("name"),
                       std::stoi(xml->getAttribute("id")),
                       input);
  }
  
  return arduinoInput;
}
