//
//  InputIntensity.h
//  vela2017
//
//  Created by Nuno on 15/03/2017.
//
//

#ifndef InputIntensity_h
#define InputIntensity_h

#include "DataInput.h"
#include "ofMain.h"

class InputIntensity: public ITrace {
public:
  InputIntensity(DataInput *_input) {input=_input; lastBlowIntensity=BlowIntensity::IDLE;}
  void update();
  
  // ITrace
  virtual std::string getTrace();

  // Event
  static ofEvent<BlowIntensity> blowIntensityChanged;

private:
  void setBlowIntensity(BlowIntensity newBlowIntensity);
  void broadcastBlowIntensityChangedEvent(BlowIntensity blowIntensity);

  DataInput *input;
  BlowIntensity lastBlowIntensity;
};

#endif /* InputIntensity_h */
