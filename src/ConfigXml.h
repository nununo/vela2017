//
//  ConfigXml.h
//  vela2017
//
//  Created by Nuno on 12/05/2017.
//
//

#ifndef ConfigXml_h
#define ConfigXml_h

#include "ofMain.h"
#include "ThresholdsSettings.h"

class ConfigXml {
public:
  ConfigXml(ofXml *_xml) {xml=_xml;}

  // From ofXml
  string getAttribute(const string& path) const {return xml->getAttribute(path);}
  string getValue(const string & path) const {return xml->getValue(path);}
  int	getIntValue(const string & path) const {return xml->getIntValue(path);}
  float getFloatValue(const string & path) const {return xml->getFloatValue(path);}
  bool getBoolValue(const string & path) const {return xml->getBoolValue(path);}
  bool setTo(const string& path) {return xml->setTo(path);}
  bool setToParent() {return xml->setToParent();}
  bool setToParent(int numLevelsUp) {return xml->setToParent(numLevelsUp);}
  bool setToSibling() {return xml->setToSibling();}

  bool getBoolAttribute(const string str);
  ThresholdsSettings getThresholdsSettings();

private:
  ofXml *xml;
};

#endif /* ConfigXml_h */
