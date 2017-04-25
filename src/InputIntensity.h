//
//  InputIntensity.h
//  vela2017
//
//  Created by Nuno on 15/03/2017.
//
//

#ifndef InputIntensity_h
#define InputIntensity_h

#include "DataInput.h"

class InputIntensity: public ITrace {
public:
  InputIntensity(DataInput *_dataInput) {dataInput=_dataInput; lastBlowIntensity=BLOW_INTENSITY_IDLE;}
  blowIntensityType getBlowIntensity() {return lastConvertedBlowIntensity;}
  void update();
  
  // ITrace
  virtual string getTrace();
  
private:
  DataInput *dataInput;
  blowIntensityType lastBlowIntensity;
  blowIntensityType lastConvertedBlowIntensity;
};

#endif /* InputIntensity_h */
