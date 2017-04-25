//
//  MouseInput.h
//  vela2017
//
//  Created by Nuno on 15/03/2017.
//
//

#ifndef MouseInput_h
#define MouseInput_h

#include "ValueInput.h"
#include "ofMain.h"

class MouseInput: public DataInput {
public:
  MouseInput(bool inverted, CalibrationSettings *calibrationSettings);
  ~MouseInput() {}
  
  // DataInput
  virtual void update() {valueInput->setValue(ofGetScreenHeight()-ofGetMouseY());};
  virtual blowIntensityType getBlowIntensity() {return valueInput->getBlowIntensity();}

  // ITrace
  virtual string getTrace() {return valueInput->getTrace();}

private:
  ValueInput *valueInput;
};

#endif /* MouseInput_h */
