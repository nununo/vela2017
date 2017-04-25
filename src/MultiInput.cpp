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
  vector<DataInput*>::iterator it;
    
  for (it = dataInputs.begin(); it != dataInputs.end(); it++)
    (*it)->update();
}

//-----------------------------------------------------------------------
blowIntensityType MultiInput::getBlowIntensity() {
  
  blowIntensityType eachIntensity;
  blowIntensityType maxIntensity = BLOW_INTENSITY_IDLE;
  
  vector<DataInput*>::iterator it;
  
  for (it = dataInputs.begin(); it != dataInputs.end(); it++) {
    eachIntensity = (*it)->getBlowIntensity();
    
    if (eachIntensity > maxIntensity )
      maxIntensity = eachIntensity;
  }
  
  return maxIntensity;
}

//-----------------------------------------------------------------------
string MultiInput::getTrace() {
  stringstream ss;
  
  ss << getName() << endl;

  vector<DataInput*>::iterator it;

  for (it = dataInputs.begin(); it != dataInputs.end(); it++)
    ss << "  " << (*it)->getTrace();

  return ss.str();
}
