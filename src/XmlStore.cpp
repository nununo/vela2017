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
AnalogInputSettings *XmlStore::getArduinoInputSettings() {
  return new AnalogInputSettings(XML.getValue(xml_prefix + "inputs:arduino:thresholds:" + Util::blowIntensityToString(BLOW_INTENSITY_MIN), 0),
                                 XML.getValue(xml_prefix + "inputs:arduino:thresholds:" + Util::blowIntensityToString(BLOW_INTENSITY_LOW), 0),
                                 XML.getValue(xml_prefix + "inputs:arduino:thresholds:" + Util::blowIntensityToString(BLOW_INTENSITY_HIGH), 0),
                                 XML.getValue(xml_prefix + "inputs:arduino:thresholds:" + Util::blowIntensityToString(BLOW_INTENSITY_BLOWOUT), 0),
                                 XML.getValue(xml_prefix + "inputs:arduino:thresholds:" + Util::blowIntensityToString(BLOW_INTENSITY_MAX), 0));
}
