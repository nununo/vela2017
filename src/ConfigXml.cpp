//
//  ConfigXml.cpp
//  vela2017
//
//  Created by Nuno on 12/05/2017.
//
//

#include "ConfigXml.h"
#include "Util.h"

//--------------------------------------------------------------
ThresholdsSettings ConfigXml::getThresholdsSettings() {
  
  return ThresholdsSettings(xml->getFloatValue(Util::blowIntensityToString(BlowIntensity::LOW)),
                    xml->getFloatValue(Util::blowIntensityToString(BlowIntensity::HIGH)),
                    xml->getFloatValue(Util::blowIntensityToString(BlowIntensity::BLOWOUT)),
                    getBoolAttribute("inverted"));
}

//--------------------------------------------------------------
bool ConfigXml::getBoolAttribute(const string str) {
  string attribute = xml->getAttribute(str);
  return (attribute=="1" || attribute=="enabled" || attribute=="active" || attribute=="true" );
}
