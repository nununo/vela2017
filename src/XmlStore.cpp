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
string XmlStore::getArduinoSensorXmlPath(string arduinoName, string sensorName, blowIntensityType blowIntensity) {
  return getArduinoXmlPath(arduinoName) + "sensors:" + sensorName + ":" + Util::blowIntensityToString(blowIntensity);
}

//--------------------------------------------------------------
AnalogInputSettings *XmlStore::getArduinoSensorInputSettings(string arduinoName, string sensorName) {
  string test;
  
  test = XML.getValue(getArduinoSensorXmlPath(arduinoName, sensorName, BLOW_INTENSITY_MIN), "-");
  
  if (test != "-")
    return new AnalogInputSettings(
      XML.getValue(getArduinoSensorXmlPath(arduinoName, sensorName, BLOW_INTENSITY_MIN), 0),
      XML.getValue(getArduinoSensorXmlPath(arduinoName, sensorName, BLOW_INTENSITY_LOW), 0),
      XML.getValue(getArduinoSensorXmlPath(arduinoName, sensorName, BLOW_INTENSITY_HIGH), 0),
      XML.getValue(getArduinoSensorXmlPath(arduinoName, sensorName, BLOW_INTENSITY_BLOWOUT), 0),
      XML.getValue(getArduinoSensorXmlPath(arduinoName, sensorName, BLOW_INTENSITY_MAX), 0));
  else
    return NULL;
    
}
