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

//--------------------------------------------------------------
DerivativeBuffer::DerivativeBuffer() {
  position = -1;
  lastDerivative = 0;
  buffer = new float[DERIVATIVE_BUFFER_SIZE];
  memset(buffer, 0, DERIVATIVE_BUFFER_SIZE);

}

//--------------------------------------------------------------
void DerivativeBuffer::addValue(float value) {
  position = ((position + 1) % DERIVATIVE_BUFFER_SIZE);
  buffer[position] = value;
  lastDerivative = calcDerivative();
}

//--------------------------------------------------------------
float DerivativeBuffer::calcDerivative() {
  float derivative=0;
  float diff;
  unsigned int nextProbe;
  unsigned int probe;
  for (probe=0;probe<DERIVATIVE_BUFFER_SIZE;probe++) {
    nextProbe = ((probe + 1) % DERIVATIVE_BUFFER_SIZE);
    diff = buffer[nextProbe] - buffer[probe];
    if (diff>0)
      derivative += diff;
  }
  return derivative;
}
