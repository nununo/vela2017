//
//  MouseInput.h
//  vela2017
//
//  Created by Nuno on 15/03/2017.
//
//

#ifndef MouseInput_h
#define MouseInput_h

#include "ofMain.h"
#include "ValueInput.h"
#include "CalibrationSettings.h"

class MouseInput: public DataInput {
public:
  MouseInput(bool inverted, CalibrationSettings *calibrationSettings);
  ~MouseInput() {delete input; input=NULL;}
  
  // DataInput
  virtual void update() {input->setValue(ofGetScreenHeight()-ofGetMouseY());};
  virtual BlowIntensity getBlowIntensity() {return input->getBlowIntensity();}

  // ITrace
  virtual string getTrace() {return input->getTrace();}

private:
  Thresholds getThresholds(bool inverted);
  string buildName(bool inverted, bool calibrated);
  
  ValueInput *input;
};

#endif /* MouseInput_h */
