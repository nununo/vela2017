//
//  MultiInput.h
//  vela2017
//
//  Created by Nuno on 17/03/2017.
//
//

#ifndef MultiInput_h
#define MultiInput_h

#include "IDataInput.h"
#include <vector>
using namespace std;

class MultiInput: public IDataInput {
public:
  ~MultiInput() {dataInputs.clear();}; // XXX This probably leaks

  // IDataInput
  virtual void update();
  virtual blowIntensityType getBlowIntensity();
  
  // ITrace
  virtual string getTrace();
  
  // Own
  void add(IDataInput *_dataInput);

private:
  vector<IDataInput*> dataInputs;
};

#endif /* MultiInput_h */
