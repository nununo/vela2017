//
//  DerivativeBuffer.cpp
//  vela2017
//
//  Created by Nuno on 17/05/2017.
//
//

#include "DerivativeBuffer.h"
#include <string.h>

#define DERIVATIVE_BUFFER_SIZE 25
#define DERIVATIVE_MAX_VALUE 1023

//--------------------------------------------------------------
DerivativeBuffer::DerivativeBuffer() {
  position = -1;
  lastDerivative = 0;
  buffer = new float[DERIVATIVE_BUFFER_SIZE];
  memset(buffer, 0, DERIVATIVE_BUFFER_SIZE);

}

//--------------------------------------------------------------
void DerivativeBuffer::addValue(float value) {
  position = getCircularIndex(position+1);
  buffer[position] = value;
  lastDerivative = calcDerivative();
}

//--------------------------------------------------------------
float DerivativeBuffer::calcDerivative() {
  float derivative=0;
  float diff;
  unsigned int previousProbe;
  unsigned int probe;
  for (int i=0;i<DERIVATIVE_BUFFER_SIZE;i++) {
    
    probe = getCircularIndex(position+i);
    
    if (buffer[probe] >=DERIVATIVE_MAX_VALUE)
      // If we get a value overload we return the value
      // Why? If the blowOut threshold is 600 and our current zero is 600,
      // since the maximum value from Arduino is 1023 we'd never be able
      // to blow out the candle
      derivative +=DERIVATIVE_MAX_VALUE;
    else {
      // Compare
      previousProbe = getCircularIndex(probe-1);
      diff = buffer[probe] - buffer[previousProbe];
      if (diff>0)
        derivative += diff;
      else if (diff<0)
        derivative = 0;
    }
  }
  return derivative;
}

//--------------------------------------------------------------
int DerivativeBuffer::getCircularIndex(int index) {
  return ( DERIVATIVE_BUFFER_SIZE + index ) % DERIVATIVE_BUFFER_SIZE;
}
