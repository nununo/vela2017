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
DataInput* CalibratedValueInputFactory::createAux(ofXml *xml, CalibrationSettings calibrationSettings) {
  string name = xml->getAttribute("name");
  
  if (Util::stringToBool(xml->getAttribute("calibrated")))
    return new CalibratedValueInput(name,
                                    getThresholds(xml),
                                    calibrationSettings);
  else
    return new ValueInput(name,
                          getThresholds(xml));
}
