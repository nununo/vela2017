//
//  ArduinoInputFactory.cpp
//  vela2017
//
//  Created by Nuno on 16/04/2017.
//
//

#include "ArduinoInputFactory.h"

//--------------------------------------------------------------
DataInput* ArduinoInputFactory::createAux(ConfigXml *xml) {
  ArduinoInput *input = new ArduinoInput(xml->getAttribute("device"),
                                         xml->getThresholdsSettings());
  
  if (input->isConnected())
    return input;
  else {
    delete input;
    input = NULL;
  }
  
  return input;
}
