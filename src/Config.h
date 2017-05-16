//
//  Config.h
//  vela2017
//
//  Created by Nuno on 16/04/2017.
//
//

#ifndef Config_h
#define Config_h

#include "ConfigXml.h"
#include "DataInput.h"
#include "ClipOutputSettings.h"
#include "GeneralSettings.h"
#include "CalibrationSettings.h"
#include "HistorySettings.h"
#include "LevelSettings.h"
#include "LayerSettings.h"
#include "Util.h"

class Config {
public:
  bool setup(string filename);
  
  DataInput* createDataInputs();
  ClipOutputSettings getClipOutputSettings();
  GeneralSettings getGeneralSettings();
  CalibrationSettings getCalibrationSettings();
  vector<LevelSettings*> createLevelSettingsList();
  LayerSettings getLayerSettings(string type);
  HistorySettings getHistorySettings();

private:
  ConfigXml *xml;
  
  bool isEnabled() {return xml->getBoolAttribute("enabled");}
  unsigned int strToHex(string hex);
};

#endif /* Config_h */
