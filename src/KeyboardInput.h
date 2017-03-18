//
//  KeyboardInput.h
//  vela2017
//
//  Created by Nuno on 16/03/2017.
//
//

#ifndef KeyboardInput_h
#define KeyboardInput_h

#include "IDataInput.h"
#include "ofMain.h"

class KeyboardInput: public IDataInput {
public:
  virtual void setup();
  virtual void update() {};
  virtual float getValue();
  ~KeyboardInput();

  void keyPressed(ofKeyEventArgs &e);
  void keyReleased(ofKeyEventArgs &e) {};

private:
  void registerKeyboardEvents();
  void unregisterKeyboardEvents();  
  
  bool bRegisteredEvents = false;
  int lastKey;

};

#endif /* KeyboardInput_h */
