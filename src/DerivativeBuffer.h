//
//  DerivativeBuffer.h
//  vela2017
//
//  Created by Nuno on 17/05/2017.
//
//

#ifndef DerivativeBuffer_h
#define DerivativeBuffer_h

class DerivativeBuffer {
public:
  DerivativeBuffer();
  void addValue(float value);
  float getDerivative() {return lastDerivative;}
  float getLastValue() {return buffer[position];}

private:
  float calcDerivative();
  int getCircularIndex(int index);
  
  float *buffer;
  int position;
  float lastDerivative;
};

#endif /* DerivativeBuffer_h */
