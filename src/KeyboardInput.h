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
  ~KeyboardInput() {
    ofUnregisterKeyEvents(this);
    delete input;
    input=NULL;
  }
  
  //DataInput
  virtual void update() {}
  virtual BlowIntensity getBlowIntensity() {return input->getBlowIntensity();}
  
  //ITrace
  virtual string getTrace() {return input->getTrace();}

  void keyPressed(ofKeyEventArgs &e);
  void keyReleased(ofKeyEventArgs &e);

private:
  ValueInput *input;

};

#endif /* KeyboardInput_h */
