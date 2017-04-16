//
//  AutoFlickerDataInputFactory.cpp
//  vela2017
//
//  Created by Nuno on 16/04/2017.
//
//

#include "AutoFlickerDataInputFactory.h"
#include "AutoFlickerDataInput.h"

//--------------------------------------------------------------
IDataInput* AutoFlickerDataInputFactory::create(ofXml *xml) {
  return new AutoFlickerDataInput(xml->getIntValue("minPeriod"));
}
