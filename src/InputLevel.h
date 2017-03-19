//
//  InputLevel.h
//  vela2017
//
//  Created by Nuno on 15/03/2017.
//
//

#ifndef InputLevel_h
#define InputLevel_h

#include "IDataInput.h"
#include "ITrace.h"

#define THRESHOLD_1 0
#define THRESHOLD_2 1
#define THRESHOLD_3 2

#define LEVEL_0 0
#define LEVEL_1 1
#define LEVEL_2 2
#define LEVEL_3 3

class InputLevel: ITrace {
public:
  InputLevel( IDataInput *_dataInput );
  int getIntensity();
  void update();
  string getTrace();
  void offsetThresholds( float diff );
  
private:
  IDataInput *dataInput;
  float threshold[3];
};

#endif /* InputLevel_h */
