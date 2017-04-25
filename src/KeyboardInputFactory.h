//
//  KeyboardInputFactory.h
//  vela2017
//
//  Created by Nuno on 16/04/2017.
//
//

#ifndef KeyboardInputFactory_h
#define KeyboardInputFactory_h

#include "DataInputFactory.h"
#include "KeyboardInput.h"

class KeyboardInputFactory : public DataInputFactory {
public:
  virtual DataInput* createAux(ofXml *xml, CalibrationSettings *calibrationSettings, string namePrefix) {return new KeyboardInput();}
};

#endif /* KeyboardInputFactory_h */
