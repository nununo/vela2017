//
//  KeyboardDataInput.h
//  vela2017
//
//  Created by Nuno on 16/03/2017.
//
//

#ifndef KeyboardDataInput_h
#define KeyboardDataInput_h

#include "ValueInput.h"
#include "ofMain.h"

class KeyboardDataInput: public IDataInput {
public:
  KeyboardDataInput();
  ~KeyboardDataInput() {ofUnregisterKeyEvents(this);}
  
  //IDataInput
  virtual void update() {}
  virtual blowIntensityType getBlowIntensity() {return valueInput->getBlowIntensity();}
  
  //ITrace
  virtual string getTrace() {return valueInput->getTrace();}

  void keyPressed(ofKeyEventArgs &e);
  void keyReleased(ofKeyEventArgs &e);

private:
  ValueInput *valueInput;

};

#endif /* KeyboardDataInput_h */
