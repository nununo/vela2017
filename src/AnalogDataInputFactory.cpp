//
//  AnalogDataInputFactory.cpp
//  vela2017
//
//  Created by Nuno on 16/04/2017.
//
//

#include "AnalogDataInputFactory.h"
#include "Util.h"
#include "AnalogDataInput.h"

//--------------------------------------------------------------
IDataInput* AnalogDataInputFactory::create(ofXml *xml) {
  return new AnalogDataInput(xml->getAttribute("name"),
                             xml->getFloatValue(Util::blowIntensityToString(BLOW_INTENSITY_MIN)),
                             xml->getFloatValue(Util::blowIntensityToString(BLOW_INTENSITY_LOW)),
                             xml->getFloatValue(Util::blowIntensityToString(BLOW_INTENSITY_HIGH)),
                             xml->getFloatValue(Util::blowIntensityToString(BLOW_INTENSITY_BLOWOUT)),
                             xml->getFloatValue(Util::blowIntensityToString(BLOW_INTENSITY_MAX)));
}
