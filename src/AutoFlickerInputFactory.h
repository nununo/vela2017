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
  virtual IDataInput* create(ofXml *xml, CalibrationSettings *calibrationSettings=NULL);
};

#endif /* AutoFlickerInputFactory_h */
