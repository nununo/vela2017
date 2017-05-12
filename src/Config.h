//
//  Config.h
//  vela2017
//
//  Created by Nuno on 16/04/2017.
//
//

#ifndef Config_h
#define Config_h

#include "ofMain.h"
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
  ofXml xml;
  
  bool isEnabled() {return Util::stringToBool(xml.getAttribute("enabled"));}
};

#endif /* Config_h */
