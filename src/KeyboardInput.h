//
//  KeyboardInput.h
//  vela2017
//
//  Created by Nuno on 16/03/2017.
//
//

#ifndef KeyboardInput_h
#define KeyboardInput_h

#include "ValueInput.h"
#include "ofMain.h"

class KeyboardInput: public DataInput {
public:
  KeyboardInput();
  ~KeyboardInput() {ofUnregisterKeyEvents(this);}
  
  //DataInput
  virtual void update() {}
  virtual blowIntensityType getBlowIntensity() {return valueInput->getBlowIntensity();}
  
  //ITrace
  virtual string getTrace() {return valueInput->getTrace();}

  void keyPressed(ofKeyEventArgs &e);
  void keyReleased(ofKeyEventArgs &e);

private:
  ValueInput *valueInput;

};

#endif /* KeyboardInput_h */
