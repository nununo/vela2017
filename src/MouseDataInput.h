//
//  MouseDataInput.h
//  vela2017
//
//  Created by Nuno on 15/03/2017.
//
//

#ifndef MouseDataInput_h
#define MouseDataInput_h

#include "IDataInput.h"
#include "ofMain.h"

class MouseDataInput: public IDataInput {
public:
  MouseDataInput() {registerMouseEvents();}
  ~MouseDataInput() {unregisterMouseEvents();}
  virtual void update();
  virtual float getValue();

  //We must declare all these mouse events methods to be able to listen to mouse events, even if we don't need them all
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

#endif /* MouseDataInput_h */
