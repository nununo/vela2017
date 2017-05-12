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
  
  ThresholdsDataInput *input=
    (ThresholdsDataInput*)DataInputFactory::createFactory(DataInputType::DATA_INPUT_THRESHOLD)->create(xml, calibrationSettings);

  arduinoInput = new ArduinoInput(xml->getAttribute("device"),
                                  input);
  
  if (arduinoInput->isConnected())
    return arduinoInput;
  else {
    delete arduinoInput;
    arduinoInput = NULL;
    input = NULL;
  }
  
  return arduinoInput;
}
