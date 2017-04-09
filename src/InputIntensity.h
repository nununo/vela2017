//
//  InputIntensity.h
//  vela2017
//
//  Created by Nuno on 15/03/2017.
//
//

#ifndef InputIntensity_h
#define InputIntensity_h

#include "IDataInput.h"

class InputIntensity: public ITrace {
public:
  InputIntensity( IDataInput *_dataInput) {dataInput = _dataInput;}
  blowIntensityType getBlowIntensity() {return lastBlowIntensity;};
  void update();
  
  // ITrace
  virtual string getTrace();
  
private:
  void calcIntensity();
  
  IDataInput *dataInput;
  blowIntensityType lastBlowIntensity;
};

#endif /* InputIntensity_h */
