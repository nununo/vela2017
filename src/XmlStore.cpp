#include "XmlStore.h"

//--------------------------------------------------------------
bool XmlStore::setup(string _filename) {
  filename = ofToDataPath(_filename);
	if( XML.loadFile(filename) ){
	  cout << "Loaded xml settings from file " << filename << endl;
		return true;
	}else{
	  cout << "Error loading xml settings from file " << filename << endl;
	  return false;
	}
}

//--------------------------------------------------------------
string XmlStore::getAnalogInputIntensityXmlPath(string sensorName, blowIntensityType blowIntensity) {
  return XML_PREFIX + "analogInputs:" + sensorName + ":" + Util::blowIntensityToString(blowIntensity);
}

//--------------------------------------------------------------
string XmlStore::getArduinoSensorXmlPath(string arduinoName, string sensorName) {
  return getArduinoXmlPath(arduinoName) + ":sensors:" + sensorName;
}

//--------------------------------------------------------------
AnalogInput *XmlStore::getAnalogInput(string sensorName) {

  if (XML.getAttribute(XML_PREFIX + "analogInputs:" + sensorName, "enabled", false))
    return new AnalogInput(
      sensorName,
      XML.getValue(getAnalogInputIntensityXmlPath(sensorName, BLOW_INTENSITY_MIN), 0),
      XML.getValue(getAnalogInputIntensityXmlPath(sensorName, BLOW_INTENSITY_LOW), 0),
      XML.getValue(getAnalogInputIntensityXmlPath(sensorName, BLOW_INTENSITY_HIGH), 0),
      XML.getValue(getAnalogInputIntensityXmlPath(sensorName, BLOW_INTENSITY_BLOWOUT), 0),
      XML.getValue(getAnalogInputIntensityXmlPath(sensorName, BLOW_INTENSITY_MAX), 0));
  else
    return NULL;
}
