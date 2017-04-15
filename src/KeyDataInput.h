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
  ~KeyDataInput() {unregisterKeyboardEvents();}
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

#endif /* KeyDataInput_h */
