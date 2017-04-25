//
//  MouseInputFactory.cpp
//  vela2017
//
//  Created by Nuno on 22/04/2017.
//
//

#include "MouseInputFactory.h"

DataInput* MouseInputFactory::createAux(ofXml *xml, CalibrationSettings *calibrationSettings, string namePrefix) {
  
  return new MouseInput(Util::stringToBool(xml->getAttribute("inverted")), calibrationSettings);
}
