//
//  KeyboardDataInput.h
//  vela2017
//
//  Created by Nuno on 16/03/2017.
//
//

#ifndef KeyboardDataInput_h
#define KeyboardDataInput_h

#include "IDataInput.h"
#include "ofMain.h"

class KeyboardDataInput: public IDataInput {
public:
  KeyboardDataInput() {registerKeyboardEvents();}
  ~KeyboardDataInput() {unregisterKeyboardEvents();}
  virtual void update() {}
  virtual blowIntensityType getBlowIntensity() {return lastBlowIntensity;}
  virtual string getTrace() {return "Keyboard input: keys: 1, 2 or 3: " + ofToString(lastBlowIntensity) + "\n";}

  void keyPressed(ofKeyEventArgs &e);
  void keyReleased(ofKeyEventArgs &e);

private:
  void registerKeyboardEvents();
  void unregisterKeyboardEvents();
  
  bool bRegisteredEvents = false;
  blowIntensityType lastBlowIntensity = BLOW_INTENSITY_MIN;

};

#endif /* KeyboardDataInput_h */
