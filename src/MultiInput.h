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
  virtual void setup();
  virtual void update();
  virtual float getValue();
  ~MultiInput() {dataInputs.clear();}; // XXX This probably leaks

  void add(IDataInput *_dataInput);

private:
  vector<IDataInput*> dataInputs;

};

#endif /* MultiInput_h */
