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
string XmlStore::getArduinoSensorIntensityXmlPath(string arduinoName, string sensorName, blowIntensityType blowIntensity) {
  return getArduinoSensorXmlPath(arduinoName, sensorName) + ":" + Util::blowIntensityToString(blowIntensity);
}

//--------------------------------------------------------------
string XmlStore::getArduinoSensorXmlPath(string arduinoName, string sensorName) {
  return getArduinoXmlPath(arduinoName) + ":sensors:" + sensorName;
}

//--------------------------------------------------------------
AnalogInputSettings *XmlStore::getArduinoSensorInputSettings(string arduinoName, string sensorName) {

  if (XML.getAttribute(getArduinoSensorXmlPath(arduinoName, sensorName), "enabled", false))
    return new AnalogInputSettings(
      sensorName,
      XML.getValue(getArduinoSensorIntensityXmlPath(arduinoName, sensorName, BLOW_INTENSITY_MIN), 0),
      XML.getValue(getArduinoSensorIntensityXmlPath(arduinoName, sensorName, BLOW_INTENSITY_LOW), 0),
      XML.getValue(getArduinoSensorIntensityXmlPath(arduinoName, sensorName, BLOW_INTENSITY_HIGH), 0),
      XML.getValue(getArduinoSensorIntensityXmlPath(arduinoName, sensorName, BLOW_INTENSITY_BLOWOUT), 0),
      XML.getValue(getArduinoSensorIntensityXmlPath(arduinoName, sensorName, BLOW_INTENSITY_MAX), 0));
  else
    return NULL;
}
