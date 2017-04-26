//
//  MouseInput.h
//  vela2017
//
//  Created by Nuno on 15/03/2017.
//
//

#ifndef MouseInput_h
#define MouseInput_h

#include "CalibratedValueInput.h"
#include "ofMain.h"

class MouseInput: public DataInput {
public:
  MouseInput(bool inverted, CalibrationSettings *calibrationSettings);
  ~MouseInput() {}
  
  // DataInput
  virtual void update() {calibratedValueInput->setValue(ofGetScreenHeight()-ofGetMouseY());};
  virtual blowIntensityType getBlowIntensity() {return calibratedValueInput->getBlowIntensity();}

  // ITrace
  virtual string getTrace() {return calibratedValueInput->getTrace();}

private:
  CalibratedValueInput *calibratedValueInput;
};

#endif /* MouseInput_h */
