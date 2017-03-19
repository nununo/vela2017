//
//  HistoryLayer.h
//  vela2017
//
//  Created by Nuno on 19/03/2017.
//
//

#ifndef HistoryLayer_h
#define HistoryLayer_h

#include "Layer.h"

#define BUFFER_SIZE 100

class HistoryLayer: public Layer {

public:
  HistoryLayer();
  void saveValue(float value);
  
private:
  virtual void drawAlgorithm();
  void initializeBuffer();
  
  float buffer[BUFFER_SIZE];
  int bufferCursor;
};

#endif /* HistoryLayer_h */
