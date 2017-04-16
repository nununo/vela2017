//
//  ArduinoDataInputFactory.cpp
//  vela2017
//
//  Created by Nuno on 16/04/2017.
//
//

#include "ArduinoDataInputFactory.h"
#include "AnalogDataInputFactory.h"

//--------------------------------------------------------------
IDataInput* ArduinoDataInputFactory::create(ofXml *xml) {
  ArduinoDataInput *arduinoDataInput = new ArduinoDataInput();
  
  addDevices(arduinoDataInput, xml);
  if (arduinoDataInput->connect())
    addAnalogDataInputs(arduinoDataInput, xml);
  
  return new ArduinoDataInput();
}

//--------------------------------------------------------------
void ArduinoDataInputFactory::addDevices(ArduinoDataInput *arduinoDataInput, ofXml *xml) {

  if (!xml->setTo("devices/device[0]")) {
    ofLogError() << "XML position to devices/device[0] failed. Check XML";
    return NULL;
  }
  
  do {
    arduinoDataInput->addDevice(xml->getValue());
  }
  while(xml->setToSibling());
  
  xml->setToParent(2);
}

//--------------------------------------------------------------
void ArduinoDataInputFactory::addAnalogDataInputs(ArduinoDataInput *arduinoDataInput, ofXml *xml) {
  
  AnalogDataInputFactory analogDataInputFactory;
  if (!xml->setTo("analogInputs/analogInput[0]")) {
    ofLogError() << "XML position to analogInputs/analogInput[0] failed. Check XML";
    return NULL;
  }
  
  do {
    if (xml->getAttribute("enabled")=="1")
      arduinoDataInput->addAnalogDataInput((AnalogDataInput*)(analogDataInputFactory.create(xml)));
  }
  while(xml->setToSibling());
  
  xml->setToParent(2);
}
