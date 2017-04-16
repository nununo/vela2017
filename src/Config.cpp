//
//  Config.cpp
//  vela2017
//
//  Created by Nuno on 16/04/2017.
//
//

#include "Config.h"
#include "MultiDataInput.h"
#include "DataInputFactory.h"

//--------------------------------------------------------------
bool Config::setup(string filename) {
  ofFile file;
  file.open(filename); // open a file
  ofBuffer buffer = file.readToBuffer(); // read to a buffer
  
  if (!xml.loadFromBuffer( buffer.getText() ))
    ofLogError() << "Error loading XML file"; // now get the buffer as a string and make XML
  
  xml.setTo("vela2017");
}

//--------------------------------------------------------------
IDataInput* Config::createDataInputs() {
  
  MultiDataInput *multiDataInput;
  
  if (!xml.setTo("inputs/input[0]")) {
    ofLogError() << "XML position to /vela2017/inputs/input[0] failed. Check XML";
    return NULL;
  }
  
  multiDataInput = new MultiDataInput();
  
  do {
    if (isEnabled())
      multiDataInput->add(DataInputFactory::createFactory(xml.getAttribute("type"))->create(&xml));
  }
  while(xml.setToSibling());
  
  xml.setToParent(2);
  
  return multiDataInput;
}

//--------------------------------------------------------------
ClipOutputSettings* Config::createClipOutputSettings() {

  if (!xml.setTo("clipOutput")) {
    ofLogError() << "XML position to /vela2017/videoOutput failed. Check XML";
    return NULL;
  }

  ClipOutputSettings *clipOutputSettings =
    new ClipOutputSettings(xml.getIntValue("offsetX"),
                           xml.getIntValue("offsetY"),
                           xml.getFloatValue("zoomX"),
                           xml.getFloatValue("zoomY"),
                           xml.getFloatValue("rotation"));
  
  xml.setToParent();
  
  return clipOutputSettings;
}

//--------------------------------------------------------------
GeneralSettings* Config::createGeneralSettings() {
  
  if (!xml.setTo("general")) {
    ofLogError() << "XML position to /vela2017/general failed. Check XML";
    return NULL;
  }
  
  GeneralSettings *generalSettings =
    new GeneralSettings(xml.getIntValue("framerate"),
                        xml.getBoolValue("fullscreen"),
                        xml.getBoolValue("showTrace"),
                        xml.getBoolValue("showHistory"));
  
  xml.setToParent();
  
  return generalSettings;
}

//--------------------------------------------------------------
vector<LevelSettings*> Config::createLevelSettingsList() {
  vector<LevelSettings*> list;

  if (!xml.setTo("levels/level[0]")) {
    ofLogError() << "XML position to /vela2017/levels/level[0] failed. Check XML";
    return;
  }

  do {
    list.push_back(new LevelSettings(xml.getValue("movieFolder"),
                                     xml.getFloatValue("fadeInTime"),
                                     xml.getFloatValue("fadeOutTime"),
                                     xml.getBoolValue("loop"),
                                     xml.getBoolValue("canRestart")));
  }
  while(xml.setToSibling());

  xml.setToParent(2);
  
  return list;
}