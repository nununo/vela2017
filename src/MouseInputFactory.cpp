//
//  MouseInputFactory.cpp
//  vela2017
//
//  Created by Nuno on 22/04/2017.
//
//

#include "MouseInputFactory.h"

DataInput* MouseInputFactory::createAux(ConfigXml *xml) {
  return new MouseInput(xml->getThresholdsSettings());
}
