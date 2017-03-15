//
//  MouseInput.h
//  vela2017
//
//  Created by Nuno on 15/03/2017.
//
//

#ifndef MouseInput_h
#define MouseInput_h

#include "IDataInput.h"
#include "ofMain.h"

class MouseInput: public IDataInput {
public:
  virtual void setup();
  virtual void update();
  virtual float getValue();
  ~MouseInput();

  //We need to declare all this mouse events methods to be able to listen to mouse events.
  //All this must be declared even if we are just going to use only one of this methods.
  void mouseMoved(ofMouseEventArgs & args) {};
  void mouseDragged(ofMouseEventArgs & args) {};
  void mousePressed(ofMouseEventArgs & args);    // We only need this one
  void mouseReleased(ofMouseEventArgs & args) {};
  void mouseScrolled(ofMouseEventArgs & args) {};
  void mouseEntered(ofMouseEventArgs & args) {};
  void mouseExited(ofMouseEventArgs & args) {};
  
private:
  void registerMouseEvents();
  void unregisterMouseEvents();
  
  bool bRegisteredEvents = false;
  int lastMouseY;
};

#endif /* MouseInput_h */
