//
//  MouseDataInput.h
//  vela2017
//
//  Created by Nuno on 15/03/2017.
//
//

#ifndef MouseDataInput_h
#define MouseDataInput_h

#include "AnalogDataInput.h"
#include "ofMain.h"

class MouseDataInput: public IDataInput {
public:
  MouseDataInput();
  ~MouseDataInput() {}
  
  // IDataInput
  virtual void update() {analogDataInput->setValue(ofGetScreenHeight()-ofGetMouseY());};
  virtual blowIntensityType getBlowIntensity() {return analogDataInput->getBlowIntensity();}

  // ITrace
  virtual string getTrace() {return analogDataInput->getTrace();}

private:
  AnalogDataInput *analogDataInput;
};

#endif /* MouseDataInput_h */
