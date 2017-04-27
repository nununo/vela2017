//
//  Config.cpp
//  vela2017
//
//  Created by Nuno on 16/04/2017.
//
//

#include "Config.h"
#include "MultiInput.h"
#include "DataInputFactory.h"

//--------------------------------------------------------------
bool Config::setup(string filename) {
  ofFile file;
  file.open(filename); // open a file
  ofBuffer buffer = file.readToBuffer(); // read to a buffer
  
  if (!xml.loadFromBuffer( buffer.getText() )) {
    ofLogError() << "Error loading XML file"; // now get the buffer as a string and make XML
    return false;
  }

  xml.setTo("vela2017");
  return true;
}

//--------------------------------------------------------------
DataInput* Config::createDataInputs() {
  
  MultiInput *multiInput;
  
  CalibrationSettings *calibrationSettings = createCalibrationSettings();
  
  if (!xml.setTo("inputs/input[0]")) {
    ofLogError() << "XML position to /vela2017/inputs/input[0] failed. Check XML";
    return NULL;
  }
  
  multiInput = new MultiInput();
  
  do {
    if (isEnabled())
      multiInput->add(DataInputFactory::createFactory(xml.getAttribute("type"))->create(&xml, calibrationSettings));
  }
  while(xml.setToSibling());
  
  xml.setToParent(2);
  
  return multiInput;
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
                        xml.getBoolValue("showHistory"),
                        xml.getBoolValue("useOmxPlayer"));
  
  xml.setToParent();
  
  return generalSettings;
}

//--------------------------------------------------------------
CalibrationSettings* Config::createCalibrationSettings() {
  
  if (!xml.setTo("calibration")) {
    ofLogError() << "XML position to /vela2017/calibration failed. Check XML";
    return NULL;
  }
  
  CalibrationSettings *calibrationSettings =
  new CalibrationSettings(xml.getIntValue("bufferSize"),
                      xml.getIntValue("excentricSize"),
                      xml.getIntValue("skipSize"));
  
  xml.setToParent();
  
  return calibrationSettings;
}

//--------------------------------------------------------------
vector<LevelSettings*> Config::createLevelSettingsList() {
  vector<LevelSettings*> list;

  if (!xml.setTo("levels/level[0]")) {
    ofLogError() << "XML position to /vela2017/levels/level[0] failed. Check XML";
    return list;
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

//--------------------------------------------------------------
LayerSettings Config::getLayerSettings(string type) {
  
  LayerSettings layerSettings;
  string path;
  
  path = "layers/layer[@type='" + type + "']";
  if (!xml.setTo(path)) {
    ofLogError() << "XML position to " << path << " failed. Check XML";
    return layerSettings;
  }
  
  layerSettings = LayerSettings(Util::stringToBool(xml.getAttribute("visible")),
                                ofPoint(std::stoi(xml.getAttribute("offsetX")),
                                        std::stoi(xml.getAttribute("offsetY"))));
  
  xml.setToParent(2);
  
  return layerSettings;
}
