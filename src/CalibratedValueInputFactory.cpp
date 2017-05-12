//
//  CalibratedInputFactory.cpp
//  vela2017
//
//  Created by Nuno on 27/04/2017.
//
//

#include "CalibratedValueInputFactory.h"
#include "Util.h"
#include "CalibratedValueInput.h"

//--------------------------------------------------------------
DataInput* CalibratedValueInputFactory::createAux(ofXml *xml, CalibrationSettings *calibrationSettings) {
  return new CalibratedValueInput(xml->getAttribute("name"),
                                  getThresholds(xml),
                                  calibrationSettings);
}
