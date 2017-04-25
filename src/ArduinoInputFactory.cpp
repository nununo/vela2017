//
//  ArduinoInputFactory.cpp
//  vela2017
//
//  Created by Nuno on 16/04/2017.
//
//

#include "ArduinoInputFactory.h"
#include "ValueInputFactory.h"

//--------------------------------------------------------------
IDataInput* ArduinoInputFactory::createAux(ofXml *xml, CalibrationSettings *calibrationSettings) {
  ArduinoInput *arduinoInput = new ArduinoInput();
  
  addDevices(arduinoInput, xml);
  if (arduinoInput->connect())
    addValueInputs(arduinoInput, xml, calibrationSettings);
  
  return arduinoInput;
}

//--------------------------------------------------------------
void ArduinoInputFactory::addDevices(ArduinoInput *arduinoInput, ofXml *xml) {

  if (!xml->setTo("devices/device[0]")) {
    ofLogError() << "XML position to devices/device[0] failed. Check XML";
    return;
  }
  
  do {
    arduinoInput->addDevice(xml->getValue());
  }
  while(xml->setToSibling());
  
  xml->setToParent(2);
}

//--------------------------------------------------------------
void ArduinoInputFactory::addValueInputs(ArduinoInput *arduinoInput, ofXml *xml, CalibrationSettings *calibrationSettings) {
  
  ValueInputFactory valueInputFactory;
  if (!xml->setTo("analogInputs/analogInput[0]")) {
    ofLogError() << "XML position to analogInputs/analogInput[0] failed. Check XML";
    return;
  }
  
  do {
    if (xml->getAttribute("enabled")=="1")
      arduinoInput->addValueInput((ValueInput*)(valueInputFactory.create(xml, calibrationSettings)));
  }
  while(xml->setToSibling());
  
  xml->setToParent(2);
}
