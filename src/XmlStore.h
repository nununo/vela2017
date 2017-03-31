#ifndef XMLSTORE_H_INCLUDED
#define XMLSTORE_H_INCLUDED

#include <string>

#define OF_ADDON_USING_OFXXMLSETTINGS

#include "ofMain.h"
#include "ofxXmlSettings.h"

using namespace std;

class XmlStore {

public:
  bool setup(string filename);
  bool save();
  string getDataFolder() {return XML.getValue("SETTINGS:DATAFOLDER", "");}
  int getArduinoDevice() {return XML.getValue("SETTINGS:ARDUINODEVICE", 1);}
  int getArduinoMinValue() {return XML.getValue("SETTINGS:ARDUINOMINVALUE", 0);}
  int getArduinoMaxValue() {return XML.getValue("SETTINGS:ARDUINOMAXVALUE", 1023);}
  int getClipsRotation() {return XML.getValue("SETTINGS:CLIPSROTATION", 180);}
  int getThreshold(int threshold) {return XML.getValue("SETTINGS:THRESHOLD" + ofToString(threshold), 0);}

  float getOffsetX() {return XML.getValue("SETTINGS:OFFSETX", 0.0f);}
  float getOffsetY() {return XML.getValue("SETTINGS:OFFSETY", 0.0f);}
  
  float getZoomX() {return XML.getValue("SETTINGS:ZOOMX", 1.0f);}
  float getZoomY() {return XML.getValue("SETTINGS:ZOOMY", 1.0f);}
  
  bool getAutocalirate() {return (XML.getValue("SETTINGS:AUTOCALIBRATE", 0) == 1);}
  
  bool getTrace() {return (XML.getValue("SETTINGS:TRACE", 0) == 1);}
  bool getHistory() {return (XML.getValue("SETTINGS:HISTORY", 0) == 1);}
  bool getFullscreen() {return (XML.getValue("SETTINGS:FULLSCREEN", 0) == 1);}
  
  int getAutoFlickerMinPeriod() {return XML.getValue("SETTINGS:AUTOFLICKERMINPERIOD", 0);}
  float getAutoFlickerValue() {return XML.getValue("SETTINGS:AUTOFLICKERVALUE", 0.0f);}

  private:
    string filename;
		ofxXmlSettings XML;
};


#endif // XMLSTORE_H_INCLUDED
