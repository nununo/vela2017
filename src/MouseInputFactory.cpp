//
//  MouseInputFactory.cpp
//  vela2017
//
//  Created by Nuno on 22/04/2017.
//
//

#include "MouseInputFactory.h"
#include "Util.h"

DataInput* MouseInputFactory::createAux(ConfigXml *xml, CalibrationSettings calibrationSettings) {
  return new MouseInput(xml->getBoolAttribute("inverted"), calibrationSettings);
}
