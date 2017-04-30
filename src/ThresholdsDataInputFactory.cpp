//
//  ThresholdDataInputFactory.cpp
//  vela2017
//
//  Created by Nuno on 27/04/2017.
//
//

#include "ThresholdsDataInputFactory.h"

#include "Util.h"
#include "CalibratedValueInput.h"

//--------------------------------------------------------------
DataInput* ThresholdsDataInputFactory::createAux(ofXml *xml, CalibrationSettings *calibrationSettings) {
  
  Thresholds thresholds;
  string name;
  bool inverted;
  
  name = xml->getAttribute("name");

  inverted = Util::stringToBool(xml->getAttribute("inverted"));
  
  thresholds = Thresholds(xml->getFloatValue(Util::blowIntensityToString(BlowIntensity::LOW)),
                          xml->getFloatValue(Util::blowIntensityToString(BlowIntensity::HIGH)),
                          xml->getFloatValue(Util::blowIntensityToString(BlowIntensity::BLOWOUT)),
                          inverted);
  
  if (calibrationSettings)
    return new CalibratedValueInput(name, thresholds, calibrationSettings);
  else
    return new ValueInput(name, thresholds);
}
