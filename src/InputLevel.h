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

class InputLevel {
public:
  InputLevel( IDataInput *_dataInput );
  int getLevel();
  
private:
  IDataInput *dataInput;
};

#endif /* InputLevel_h */
