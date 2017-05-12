//
//  ValueInputFactory.cpp
//  vela2017
//
//  Created by Nuno on 12/05/2017.
//
//

#include "ValueInputFactory.h"
#include "ValueInput.h"
#include "Util.h"

//--------------------------------------------------------------
DataInput* ValueInputFactory::createAux(ofXml *xml, CalibrationSettings *calibrationSettings) {
  return new ValueInput(xml->getAttribute("name"), getThresholds(xml));
}

//--------------------------------------------------------------
Thresholds ValueInputFactory::getThresholds(ofXml *xml) {
  
  return Thresholds(xml->getFloatValue(Util::blowIntensityToString(BlowIntensity::LOW)),
                    xml->getFloatValue(Util::blowIntensityToString(BlowIntensity::HIGH)),
                    xml->getFloatValue(Util::blowIntensityToString(BlowIntensity::BLOWOUT)),
                    Util::stringToBool(xml->getAttribute("inverted")));
}
