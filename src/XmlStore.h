#ifndef XMLSTORE_H_INCLUDED
#define XMLSTORE_H_INCLUDED

#include <string>

#define OF_ADDON_USING_OFXXMLSETTINGS

#include "ofMain.h"
#include "ofxXmlSettings.h"
#include "Util.h"
#include "AnalogInput.h"

using namespace std;

class XmlStore {

public:
  bool setup(string filename);
  
  // Clips
  string getMovieFolder(int i) {return XML.getValue(XML_PREFIX + "levels:level" + ofToString(i) + ":movieFolder", "");}
  float getFadeInTime(int i)  {return XML.getValue(XML_PREFIX + "levels:level" + ofToString(i) + ":fadeInTime", 0.0f);}
  float getFadeOutTime(int i) {return XML.getValue(XML_PREFIX + "levels:level" + ofToString(i) + ":fadeOutTime", 0.0f);}
  bool getLoop(int i)         {return (XML.getValue(XML_PREFIX + "levels:level" + ofToString(i) + ":loop", 0) == 1);}
  bool getCanRestart(int i)   {return (XML.getValue(XML_PREFIX + "levels:level" + ofToString(i) + ":canRestart", 0) == 1);}

  // General settings
  bool getShowTrace()   {return (XML.getValue(XML_PREFIX + "display:showTrace", 0) == 1);}
  bool getShowHistory() {return (XML.getValue(XML_PREFIX + "display:showHistory", 0) == 1);}
  bool getFullscreen()  {return (XML.getValue(XML_PREFIX + "display:fullscreen", 0) == 1);}
  int getFramerate()    {return XML.getValue(XML_PREFIX + "display:framerate", 25);}

  // Clip display
  int getVideoRotation()  {return XML.getValue(XML_PREFIX + "videoOutput:rotation", 180);}
  float getVideoOffsetX() {return XML.getValue(XML_PREFIX + "videoOutput:offsetX", 0.0f);}
  float getVideoOffsetY() {return XML.getValue(XML_PREFIX + "videoOutput:offsetY", 0.0f);}
  float getVideoZoomX()   {return XML.getValue(XML_PREFIX + "videoOutput:zoomX", 1.0f);}
  float getVideoZoomY()   {return XML.getValue(XML_PREFIX + "videoOutput:zoomY", 1.0f);}
  
  // Arduino data input
  bool getArduinoInputEnabled(string arduinoName) {return XML.getAttribute(getArduinoXmlPath(arduinoName), "enabled", false);}
  string getArduinoInputDevice(string arduinoName)        {return XML.getValue(getArduinoXmlPath(arduinoName) + ":device", "?");}
  
  // Analog input
  AnalogInput *getAnalogInput(string sensorName);

  //Keyboard data input
  bool getKeyboardInputEnabled() {return XML.getAttribute(XML_PREFIX + "inputs:keyboard", "enabled", false);}

  // Autoflicker data input
  bool getAutoFlickerInputEnabled()  {return XML.getAttribute(XML_PREFIX + "inputs:autoFlicker", "enabled", false);}
  int getAutoFlickerInputMinPeriod() {return XML.getValue(XML_PREFIX + "inputs:autoFlicker:minPeriod", 0);}
  
private:
  const string XML_PREFIX = "vela2017:";

  string filename;
  ofxXmlSettings XML;
  
  string getArduinoXmlPath(string arduinoName) {return XML_PREFIX + "inputs:arduinos:" + arduinoName;}
  string getArduinoSensorXmlPath(string arduinoName, string sensorName);
  string getAnalogInputIntensityXmlPath(string sensorName, blowIntensityType blowIntensity);
};

#endif // XMLSTORE_H_INCLUDED
