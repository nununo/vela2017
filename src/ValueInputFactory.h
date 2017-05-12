//
//  ValueInputFactory.h
//  vela2017
//
//  Created by Nuno on 12/05/2017.
//
//

#ifndef ValueInputFactory_h
#define ValueInputFactory_h

#include "DataInputFactory.h"
#include "Thresholds.h"

class ValueInputFactory : public DataInputFactory {
public:
  virtual DataInput* createAux(ofXml *xml, CalibrationSettings calibrationSettings);

protected:
  Thresholds getThresholds(ofXml *xml);
};


#endif /* ValueInputFactory_hpp */
