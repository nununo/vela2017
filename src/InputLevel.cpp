//
//  InputLevel.cpp
//  vela2017
//
//  Created by Nuno on 15/03/2017.
//
//

#include "InputLevel.h"

//--------------------------------------------------------------
InputLevel::InputLevel( IDataInput *_dataInput ) {
  dataInput = _dataInput;
};

//--------------------------------------------------------------
int InputLevel::getLevel() {
  
  float value = dataInput->getValue();
  int level;
  
  if (value > 0.80f)
    level = 4;
  else if (value > 0.60f)
    level = 3;
  else if (value > 0.40f)
    level = 2;
  else if (value > 0.20f)
    level = 1;
  else
    level = 0;
  
  return level;
  
};
