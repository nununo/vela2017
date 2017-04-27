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
  BlowIntensity getBlowIntensity() {return lastConvertedBlowIntensity;}
  void update();
  
  // ITrace
  virtual std::string getTrace();

  // Event
  static ofEvent<BlowIntensity> blowIntensityChanged;

private:
  void setBlowIntensity(BlowIntensity newBlowIntensity);
  void broadcastBlowIntensityChangedEvent();

  DataInput *input;
  BlowIntensity lastBlowIntensity;
  BlowIntensity lastConvertedBlowIntensity; // Converted back to IDLE unless the intensity increases
};

#endif /* InputIntensity_h */
