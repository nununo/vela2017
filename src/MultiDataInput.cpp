//
//  MultiDataInput.cpp
//  vela2017
//
//  Created by Nuno on 17/03/2017.
//
//

#include "MultiDataInput.h"
#include <sstream>

//-----------------------------------------------------------------------
void MultiDataInput::add(IDataInput *dataInput) {
  dataInputs.push_back(dataInput);
};

//-----------------------------------------------------------------------
void MultiDataInput::update() {
  vector<IDataInput*>::iterator it;
    
  for (it = dataInputs.begin(); it != dataInputs.end(); it++)
    (*it)->update();
}

//-----------------------------------------------------------------------
float MultiDataInput::getValue() {
  
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

//-----------------------------------------------------------------------
string MultiDataInput::getTrace() {
  stringstream ss;
  
  ss << "MultiDataInput:\n";

  vector<IDataInput*>::iterator it;

  for (it = dataInputs.begin(); it != dataInputs.end(); it++)
    ss << "  " << (*it)->getTrace();

  return ss.str();
}
