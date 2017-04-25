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
DataInput* ValueInputFactory::createAux(ofXml *xml, CalibrationSettings *calibrationSettings, string namePrefix) {
  
  string name = xml->getAttribute("name");
  
  if (namePrefix!="")
    name = namePrefix + "." + name;
  
  return new ValueInput(name,
                        xml->getFloatValue(Util::blowIntensityToString(BLOW_INTENSITY_LOW)),
                        xml->getFloatValue(Util::blowIntensityToString(BLOW_INTENSITY_HIGH)),
                        xml->getFloatValue(Util::blowIntensityToString(BLOW_INTENSITY_BLOWOUT)),
                        Util::stringToBool(xml->getAttribute("inverted")),
                        calibrationSettings);
}
