//
//  MultiDataInput.h
//  vela2017
//
//  Created by Nuno on 17/03/2017.
//
//

#ifndef MultiDataInput_h
#define MultiDataInput_h

#include "IDataInput.h"
#include <vector>
using namespace std;

class MultiDataInput: public IDataInput {
public:
  ~MultiDataInput() {dataInputs.clear();}; // XXX This probably leaks

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

#endif /* MultiDataInput_h */
