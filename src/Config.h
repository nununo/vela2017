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
#include "LevelSettings.h"
#include "LayerSettings.h"
#include "Util.h"

class Config {
public:
  bool setup(string filename);
  
  DataInput* createDataInputs();
  ClipOutputSettings* createClipOutputSettings();
  GeneralSettings getGeneralSettings();
  CalibrationSettings *createCalibrationSettings();
  vector<LevelSettings*> createLevelSettingsList();
  LayerSettings getLayerSettings(string type);

private:
  ofXml xml;
  
  bool isEnabled() {return Util::stringToBool(xml.getAttribute("enabled"));}
};

#endif /* Config_h */
