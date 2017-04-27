//
//  CalibrationSettingsFactory.cpp
//  vela2017
//
//  Created by Nuno on 17/04/2017.
//
//

#include "CalibrationSettingsFactory.h"

//--------------------------------------------------------------
CalibrationSettings* CalibrationSettingsFactory::create(ofXml *xml) {

  return new CalibrationSettings(xml->getIntValue("bufferSize"),
                                xml->getIntValue("excentricSize"),
                                xml->getIntValue("skipSize"));

}
