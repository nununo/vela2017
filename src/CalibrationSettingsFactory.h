//
//  CalibrationSettingsFactory.h
//  vela2017
//
//  Created by Nuno on 17/04/2017.
//
//

#ifndef CalibrationSettingsFactory_h
#define CalibrationSettingsFactory_h

#include "CalibrationSettings.h"
#include "ofMain.h"

class CalibrationSettingsFactory {
public:  
  static CalibrationSettings* create(ofXml *xml);

};

#endif /* CalibrationSettingsFactory_h */
