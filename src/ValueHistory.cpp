//
//  ValueHistory.cpp
//  vela2017
//
//  Created by Nuno on 26/04/2017.
//
//

#include "ValueHistory.h"
#include "HistorySettings.h"

//--------------------------------------------------------------
void ValueHistory::addValue(float value) {
  values.push_back(value);
  
  if (values.size() > HistorySettings::getBufferSize())
    values.pop_front();
}
