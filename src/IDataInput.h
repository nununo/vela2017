//
//  IDataInput.h
//  vela2017
//
//  Created by Nuno on 14/03/2017.
//
//

#ifndef IDataInput_h
#define IDataInput_h

class IDataInput {
  //virtual ~IDataInput() {}
  virtual void setup() = 0;
  virtual float getValue() = 0;
};

#endif /* IDataInput_h */
