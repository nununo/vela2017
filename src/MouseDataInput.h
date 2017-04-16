//
//  MouseDataInput.h
//  vela2017
//
//  Created by Nuno on 15/03/2017.
//
//

#ifndef MouseDataInput_h
#define MouseDataInput_h

#include "ValueInput.h"
#include "ofMain.h"

class MouseDataInput: public IDataInput {
public:
  MouseDataInput(bool inverted=false);
  ~MouseDataInput() {}
  
  // IDataInput
  virtual void update() {valueInput->setValue(ofGetScreenHeight()-ofGetMouseY());};
  virtual blowIntensityType getBlowIntensity() {return valueInput->getBlowIntensity();}

  // ITrace
  virtual string getTrace() {return valueInput->getTrace();}

private:
  ValueInput *valueInput;
};

#endif /* MouseDataInput_h */
