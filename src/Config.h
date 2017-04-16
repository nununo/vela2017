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
#include "IDataInput.h"
#include "ClipOutputSettings.h"
#include "GeneralSettings.h"
#include "LevelSettings.h"

class Config {
public:
  bool setup(string filename);
  
  IDataInput* createDataInputs();
  ClipOutputSettings* createClipOutputSettings();
  GeneralSettings* createGeneralSettings();
  vector<LevelSettings*> createLevelSettingsList();

private:
  ofXml xml;
  
  bool isEnabled() {return (xml.getAttribute("enabled")=="1");}
};

#endif /* Config_h */
