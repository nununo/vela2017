//
//  ArduinoInputFactory.cpp
//  vela2017
//
//  Created by Nuno on 16/04/2017.
//
//

#include "ArduinoInputFactory.h"
#include "CalibratedValueInputFactory.h"

//--------------------------------------------------------------
DataInput* ArduinoInputFactory::createAux(ofXml *xml, CalibrationSettings *calibrationSettings) {
  
  ArduinoInput *arduinoInput = NULL;
  
  CalibratedValueInput *input=
    (CalibratedValueInput*)DataInputFactory::createFactory(DataInputType::DATA_INPUT_CALIBRATED_VALUE)->create(xml, calibrationSettings);

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
