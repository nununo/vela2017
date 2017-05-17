//
//  DerivativeValueInput.h
//  vela2017
//
//  Created by Nuno on 17/05/2017.
//
//

#ifndef DerivativeValueInput_h
#define DerivativeValueInput_h

#include "ValueInput.h"
#include "DerivativeBuffer.h"

class DerivativeValueInput : public ValueInput {
public:
  DerivativeValueInput(string name,
                       ThresholdsSettings thresholdsSettings) : ValueInput(name, thresholdsSettings) {}
 
  // ValueInput
  virtual void setValue(float value);
  
  // ITrace
  virtual string getTrace();

private:
  DerivativeBuffer derivativeBuffer;
};

#endif /* DerivativeValueInput_h */
