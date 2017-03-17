//
//  MultiInput.cpp
//  vela2017
//
//  Created by Nuno on 17/03/2017.
//
//

#include "MultiInput.h"

//-----------------------------------------------------------------------
void MultiInput::add(IDataInput *dataInput) {
  dataInputs.push_back(dataInput);
};

//-----------------------------------------------------------------------
void MultiInput::setup() {
  vector<IDataInput*>::iterator it;
  
  for (it = dataInputs.begin(); it != dataInputs.end(); it++)
    (*it)->setup();
}

//-----------------------------------------------------------------------
void MultiInput::update() {
  vector<IDataInput*>::iterator it;
    
  for (it = dataInputs.begin(); it != dataInputs.end(); it++)
    (*it)->update();
}

//-----------------------------------------------------------------------
float MultiInput::getValue() {
  
  float inputValue;
  float maxValue = 0;
  
  vector<IDataInput*>::iterator it;
  
  for (it = dataInputs.begin(); it != dataInputs.end(); it++) {
    inputValue = (*it)->getValue();
    
    if (inputValue > maxValue )
      maxValue = inputValue;
  }
  
  return maxValue;
};

