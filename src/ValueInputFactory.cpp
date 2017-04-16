//
//  ValueInputFactory.cpp
//  vela2017
//
//  Created by Nuno on 16/04/2017.
//
//

#include "ValueInputFactory.h"
#include "Util.h"
#include "ValueInput.h"

//--------------------------------------------------------------
IDataInput* ValueInputFactory::create(ofXml *xml) {
  return new ValueInput(xml->getAttribute("name"),
                        xml->getFloatValue(Util::blowIntensityToString(BLOW_INTENSITY_IDLE)),
                        xml->getFloatValue(Util::blowIntensityToString(BLOW_INTENSITY_LOW)),
                        xml->getFloatValue(Util::blowIntensityToString(BLOW_INTENSITY_HIGH)),
                        xml->getFloatValue(Util::blowIntensityToString(BLOW_INTENSITY_BLOWOUT)),
                        Util::stringToBool(xml->getAttribute("inverted")));
}
