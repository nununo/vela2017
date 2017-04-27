//
//  ValueHistoryLayer.h
//  vela2017
//
//  Created by Nuno on 26/04/2017.
//
//

#ifndef ValueHistoryLayer_h
#define ValueHistoryLayer_h

#include "Layer.h"
#include "ValueHistories.h"

class ValueHistoryLayer : public Layer {
public:
  ValueHistoryLayer(ValueHistory *_valueHistory) {valueHistory=_valueHistory;}

protected:
  void drawAlgorithm();

private:
  ValueHistory *valueHistory;
  
};

#endif /* ValueHistoryLayer_h */
