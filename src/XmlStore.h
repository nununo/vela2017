#ifndef XMLSTORE_H_INCLUDED
#define XMLSTORE_H_INCLUDED

#include <string>

#define OF_ADDON_USING_OFXXMLSETTINGS

#include "ofMain.h"
#include "ofxXmlSettings.h"

using namespace std;

#define XML_PREFIX_SETTINGS "settings:"

class XmlStore {

public:
  bool setup(string filename);
  
  string getMovieFolder(int i)       {
    string s = xml_prefix + "levels:level" + ofToString(i) + ":movieFolder";
    return XML.getValue(xml_prefix + "levels:level" + ofToString(i) + ":movieFolder", "");
  }
  float getFadeInTime(int i)         {return XML.getValue(xml_prefix + "levels:level" + ofToString(i) + ":fadeInTime", 0.0f);}
  float getFadeOutTime(int i)        {return XML.getValue(xml_prefix + "levels:level" + ofToString(i) + ":fadeOutTime", 0.0f);}
  float getThreshold(int i)          {return XML.getValue(xml_prefix + "levels:level" + ofToString(i) + ":threshold", 0.0f);}
  bool getLoop(int i)                {return (XML.getValue(xml_prefix + "levels:level" + ofToString(i) + ":loop", 0) == 1);}

  int getVideoRotation()             {return XML.getValue(xml_prefix + "videoOutput:rotation", 180);}
  float getVideoOffsetX()            {return XML.getValue(xml_prefix + "videoOutput:offsetX", 0.0f);}
  float getVideoOffsetY()            {return XML.getValue(xml_prefix + "videoOutput:offsetY", 0.0f);}
  float getVideoZoomX()              {return XML.getValue(xml_prefix + "videoOutput:zoomX", 1.0f);}
  float getVideoZoomY()              {return XML.getValue(xml_prefix + "videoOutput:zoomY", 1.0f);}
  
  bool getArduinoInputEnabled()      {return (XML.getValue(xml_prefix + "input:arduino:enabled", 0) == 1);}
  string getArduinoInputDevice()     {return XML.getValue(xml_prefix + "input:arduino:device", "?");}
  int getArduinoInputMinValue()      {return XML.getValue(xml_prefix + "input:arduino:minValue", 0);}
  int getArduinoInputMaxValue()      {return XML.getValue(xml_prefix + "input:arduino:maxValue", 1023);}
  
  bool getKeyboardInputEnabled()     {return (XML.getValue(xml_prefix + "input:keyboard:enabled", 0) == 1);}

  bool getAutoFlickerInputEnabled()  {return (XML.getValue(xml_prefix + "input:autoFlicker:enabled", 0) == 1);}
  int getAutoFlickerInputMinPeriod() {return XML.getValue(xml_prefix + "input:autoFlicker:minPeriod", 0);}
  float getAutoFlickerInputValue()   {return XML.getValue(xml_prefix + "input:autoFlicker:value", 0.0f);}

  bool getShowTrace()                {return (XML.getValue(xml_prefix + "display:showTrace", 0) == 1);}
  bool getShowHistory()              {return (XML.getValue(xml_prefix + "display:showHistory", 0) == 1);}
  bool getFullscreen()               {return (XML.getValue(xml_prefix + "display:fullscreen", 0) == 1);}
  int getFramerate()                 {return XML.getValue(xml_prefix + "display:framerate", 25);}
  
  //bool getAutocalirate() {return (XML.getValue(xml_prefix + string("AUTOCALIBRATE"), 0) == 1);}

private:
  string filename;
  string xml_prefix = XML_PREFIX_SETTINGS;
  ofxXmlSettings XML;
};


#endif // XMLSTORE_H_INCLUDED
