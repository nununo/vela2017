//
//  MultiInput.h
//  vela2017
//
//  Created by Nuno on 17/03/2017.
//
//

#ifndef MultiInput_h
#define MultiInput_h

#include "DataInput.h"
#include <vector>
using namespace std;

class MultiInput: public DataInput {
public:
  MultiInput() : DataInput("multi") {}
  ~MultiInput() {dataInputs.clear();}; // XXX This probably leaks

  // DataInput
  virtual void update();
  virtual blowIntensityType getBlowIntensity();
  
  // ITrace
  virtual string getTrace();
  
  // Own
  void add(DataInput *_dataInput);

private:
  vector<DataInput*> dataInputs;
};

#endif /* MultiInput_h */
