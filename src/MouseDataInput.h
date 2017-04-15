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
  ~MouseDataInput() {}
  
  // IDataInput
  virtual void update() {};
  virtual blowIntensityType getBlowIntensity();

  // ITrace
  virtual string getTrace();

private:
  blowIntensityType valueToBlowIntensity(float value);
};

#endif /* MouseDataInput_h */
