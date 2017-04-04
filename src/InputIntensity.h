//
//  InputIntensity.h
//  vela2017
//
//  Created by Nuno on 15/03/2017.
//
//

#ifndef InputIntensity_h
#define InputIntensity_h

#include "IDataInput.h"
#include "ITrace.h"

#define THRESHOLD_1 0
#define THRESHOLD_2 1
#define THRESHOLD_3 2

#define LEVEL_0 0
#define LEVEL_1 1
#define LEVEL_2 2
#define LEVEL_3 3

class InputIntensity: public ITrace {
public:
  InputIntensity( IDataInput *_dataInput, float threshold1, float threshold2, float threshold3);
  int getIntensity() {return lastIntensity;};
  float getValue() {return lastValue;};
  void update();
  
  // ITrace
  virtual string getTrace();

  void offsetThresholds( float diff );
  
private:
  void calcIntensity();
  
  IDataInput *dataInput;
  float lastValue;
  int lastIntensity;
  float threshold[3];

};

#endif /* InputIntensity_h */
