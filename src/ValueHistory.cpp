//
//  ValueHistory.cpp
//  vela2017
//
//  Created by Nuno on 26/04/2017.
//
//

#include "ValueHistory.h"

int ValueHistory::bufferSize;

//--------------------------------------------------------------
void ValueHistory::addValue(float value) {
  values.push_back(value);
  
  if (values.size() > ValueHistory::bufferSize)
    values.pop_front();
}
