//
//  ThresholdsDataInputFactory.h
//  vela2017
//
//  Created by Nuno on 27/04/2017.
//
//

#ifndef ThresholdsDataInputFactory_h
#define ThresholdsDataInputFactory_h

#include "DataInputFactory.h"
#include "CalibrationSettings.h"

class ThresholdsDataInputFactory : public DataInputFactory {
public:
  virtual DataInput* createAux(ofXml *xml, CalibrationSettings *calibrationSettings, string namePrefix);
};

#endif /* ThresholdsDataInputFactory_h */
