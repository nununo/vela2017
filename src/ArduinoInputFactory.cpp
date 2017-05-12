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
  ArduinoInput *input = new ArduinoInput(xml->getAttribute("device"),
                                         getThresholds(xml),
                                         calibrationSettings);
  
  if (input->isConnected())
    return input;
  else {
    delete input;
    input = NULL;
  }
  
  return input;
}
