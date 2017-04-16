//
//  KeyboardDataInput.h
//  vela2017
//
//  Created by Nuno on 16/03/2017.
//
//

#ifndef KeyboardDataInput_h
#define KeyboardDataInput_h

#include "AnalogDataInput.h"
#include "ofMain.h"

class KeyboardDataInput: public IDataInput {
public:
  KeyboardDataInput();
  ~KeyboardDataInput() {ofUnregisterKeyEvents(this);}
  
  //IDataInput
  virtual void update() {}
  virtual blowIntensityType getBlowIntensity() {return analogDataInput->getBlowIntensity();}
  
  //ITrace
  virtual string getTrace() {return analogDataInput->getTrace();}

  void keyPressed(ofKeyEventArgs &e);
  void keyReleased(ofKeyEventArgs &e);

private:
  AnalogDataInput *analogDataInput;

};

#endif /* KeyboardDataInput_h */
