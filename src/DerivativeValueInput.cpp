//
//  DerivativeValueInput.cpp
//  vela2017
//
//  Created by Nuno on 17/05/2017.
//
//

#include "DerivativeValueInput.h"

/*//--------------------------------------------------------------
DerivativeValueInput::DerivativeValueInput(string name,
                                            ThresholdsSettings thresholdsSettings) : ValueInput(name, thresholdsSettings) {

}*/

//--------------------------------------------------------------
void DerivativeValueInput::setValue(float value) {
  derivativeBuffer.addValue(value);
  ValueInput::setValue(derivativeBuffer.getDerivative());
}

//--------------------------------------------------------------
string DerivativeValueInput::getTrace() {
  stringstream ss;
  ss << ValueInput::getTrace() << " derivativeLastValue: " << derivativeBuffer.getLastValue();
  return ss.str();
}
