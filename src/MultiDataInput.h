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
  virtual void update();
  virtual float getValue();
  ~MultiDataInput() {dataInputs.clear();}; // XXX This probably leaks

  void add(IDataInput *_dataInput);

private:
  vector<IDataInput*> dataInputs;

};

#endif /* MultiDataInput_h */
