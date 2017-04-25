//
//  NameFloatEventArgs.h
//  vela2017
//
//  Created by Nuno on 25/04/2017.
//
//

#ifndef NameFloatEventArgs_h
#define NameFloatEventArgs_h

#include "ofMain.h"

class NameFloatEventArgs : public ofEventArgs {
  
public:
  NameFloatEventArgs(string _name, float _value) {name=_name; value=_value;}
  string getName() {return name;}
  float getValue() {return value;}
  
private:
  string name;
  float value;
};

#endif /* NameFloatEventArgs_h */
