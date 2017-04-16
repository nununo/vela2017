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
  if (dataInput)
    dataInputs.push_back(dataInput);
}

//-----------------------------------------------------------------------
void MultiDataInput::update() {
  vector<IDataInput*>::iterator it;
    
  for (it = dataInputs.begin(); it != dataInputs.end(); it++)
    (*it)->update();
}

//-----------------------------------------------------------------------
blowIntensityType MultiDataInput::getBlowIntensity() {
  
  blowIntensityType eachIntensity;
  blowIntensityType maxIntensity = BLOW_INTENSITY_IDLE;
  
  vector<IDataInput*>::iterator it;
  
  for (it = dataInputs.begin(); it != dataInputs.end(); it++) {
    eachIntensity = (*it)->getBlowIntensity();
    
    if (eachIntensity > maxIntensity )
      maxIntensity = eachIntensity;
  }
  
  return maxIntensity;
}

//-----------------------------------------------------------------------
string MultiDataInput::getTrace() {
  stringstream ss;
  
  ss << "MultiDataInput:\n";

  vector<IDataInput*>::iterator it;

  for (it = dataInputs.begin(); it != dataInputs.end(); it++)
    ss << "  " << (*it)->getTrace();

  return ss.str();
}
