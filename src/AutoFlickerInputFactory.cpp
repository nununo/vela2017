//
//  AutoFlickerInputFactory.cpp
//  vela2017
//
//  Created by Nuno on 16/04/2017.
//
//

#include "AutoFlickerInputFactory.h"
#include "AutoFlickerInput.h"

//--------------------------------------------------------------
IDataInput* AutoFlickerInputFactory::create(ofXml *xml) {
  return new AutoFlickerInput(xml->getIntValue("minPeriod"));
}
