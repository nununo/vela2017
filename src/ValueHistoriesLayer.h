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
#include "ThresholdsEventArgs.h"
#include "HistorySettings.h"

class ValueHistoriesLayer : public Layer {

public:
  ValueHistoriesLayer(LayerSettings layerSettings, HistorySettings historySettings);
  ~ValueHistoriesLayer();

protected:
  void drawAlgorithm();

private:
  void drawHistory(string name, ValueHistory* history);
  ofVec2f getThresholdsMinMax(const ValueHistory* history);
  ofVec2f getValuesMinMax(const ValueHistory* history);
  ofVec2f getMinMax(ofVec2f valuesMinMax, ofVec2f thresholdsMinMax);
  float mapHeight(ofVec2f minMax, float value);
  void drawLine(ofVec2f minMax, ValueHistory *history, float value);

  HistorySettings historySettings;
  Thresholds thresholds;
  ValueHistories *valueHistories;
  ofTrueTypeFont font;
};

#endif /* ValueHistoriesLayer_h */
