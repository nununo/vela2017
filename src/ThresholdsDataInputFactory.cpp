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
DataInput* ThresholdsDataInputFactory::createAux(ofXml *xml, CalibrationSettings *calibrationSettings, string namePrefix) {
  
  Thresholds thresholds;
  string name;
  bool inverted;
  
  name = xml->getAttribute("name");
  if (namePrefix!="")
    name = namePrefix + "." + name;
  
  thresholds = Thresholds(xml->getFloatValue(Util::blowIntensityToString(BLOW_INTENSITY_LOW)),
                          xml->getFloatValue(Util::blowIntensityToString(BLOW_INTENSITY_HIGH)),
                          xml->getFloatValue(Util::blowIntensityToString(BLOW_INTENSITY_BLOWOUT)));
  
  inverted = Util::stringToBool(xml->getAttribute("inverted"));
  
  if (calibrationSettings)
    return new CalibratedValueInput(name,
                                    thresholds,
                                    inverted,
                                    calibrationSettings);
  else
    return new ValueInput(name,
                          thresholds,
                          inverted);
}
