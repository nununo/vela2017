//
//  MultiInput.cpp
//  vela2017
//
//  Created by Nuno on 17/03/2017.
//
//

#include "MultiInput.h"
#include <sstream>

//-----------------------------------------------------------------------
void MultiInput::add(DataInput *dataInput) {
  if (dataInput)
    dataInputs.push_back(dataInput);
}

//-----------------------------------------------------------------------
void MultiInput::update() {
  std::vector<DataInput*>::iterator it;
    
  for (it = dataInputs.begin(); it != dataInputs.end(); it++)
    (*it)->update();
}

//-----------------------------------------------------------------------
BlowIntensity MultiInput::getBlowIntensity() {
  
  BlowIntensity eachIntensity;
  BlowIntensity maxIntensity = BlowIntensity::IDLE;
  
  std::vector<DataInput*>::iterator it;
  
  for (it = dataInputs.begin(); it != dataInputs.end(); it++) {
    eachIntensity = (*it)->getBlowIntensity();
    
    if (eachIntensity > maxIntensity )
      maxIntensity = eachIntensity;
  }
  
  return maxIntensity;
}

//-----------------------------------------------------------------------
std::string MultiInput::getTrace() {
  std::stringstream ss;
  
  ss << getName() << std::endl;

  std::vector<DataInput*>::iterator it;

  for (it = dataInputs.begin(); it != dataInputs.end(); it++)
    ss << "  " << (*it)->getTrace();

  return ss.str();
}
