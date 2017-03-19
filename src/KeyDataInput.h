//
//  KeyDataInput.h
//  vela2017
//
//  Created by Nuno on 16/03/2017.
//
//

#ifndef KeyDataInput_h
#define KeyDataInput_h

#include "IDataInput.h"
#include "ofMain.h"

class KeyDataInput: public IDataInput {
public:
  KeyDataInput() {registerKeyboardEvents();}
  virtual void setup() {}
  virtual void update() {}
  virtual float getValue();
  ~KeyDataInput() {unregisterKeyboardEvents();}

  void keyPressed(ofKeyEventArgs &e);
  void keyReleased(ofKeyEventArgs &e) {};

private:
  void registerKeyboardEvents();
  void unregisterKeyboardEvents();  
  
  bool bRegisteredEvents = false;
  int lastKey;

};

#endif /* KeyDataInput_h */
