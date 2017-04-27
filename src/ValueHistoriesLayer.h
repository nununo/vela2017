//
//  ValueHistoriesLayer.h
//  vela2017
//
//  Created by Nuno on 26/04/2017.
//
//

#ifndef ValueHistoriesLayer_h
#define ValueHistoriesLayer_h

#include "Layer.h"
#include "ValueHistories.h"
#include "NameFloatEventArgs.h"

class ValueHistoriesLayer : public Layer {

public:
  ValueHistoriesLayer(int bufferSize);
  ~ValueHistoriesLayer();

protected:
  void drawAlgorithm();

private:
  void onNewValue(NameFloatEventArgs &e);
  void drawHistory(string name);

  ValueHistories *valueHistories;
};

#endif /* ValueHistoriesLayer_h */
