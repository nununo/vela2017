//
//  ThresholdsDataInput.h
//  vela2017
//
//  Created by Nuno on 27/04/2017.
//
//

#ifndef ThresholdsDataInput_h
#define ThresholdsDataInput_h

#include "DataInput.h"
#include "Thresholds.h"

class ThresholdsDataInput : public DataInput {
public:
  ThresholdsDataInput(const std::string name) : DataInput(name) {}
  virtual Thresholds* const getThresholds() = 0;
  virtual void setValue(float value) = 0;
};

#endif /* ThresholdsDataInput_h */
