//
//  AutoFlickerInputFactory.h
//  vela2017
//
//  Created by Nuno on 16/04/2017.
//
//

#ifndef AutoFlickerInputFactory_h
#define AutoFlickerInputFactory_h

#include "DataInputFactory.h"

class AutoFlickerInputFactory : public DataInputFactory {
public:
  virtual DataInput* createAux(ofXml *xml, CalibrationSettings calibrationSettings);
};

#endif /* AutoFlickerInputFactory_h */
