//
//  HistorySettings.h
//  vela2017
//
//  Created by Nuno on 29/04/2017.
//
//

#ifndef HistorySettings_h
#define HistorySettings_h

namespace HistorySettingsDefaults {
  static const int BUFFER_SIZE = 200;
  static const int CHART_HEIGHT = 500;
}

class HistorySettings {
public:
  HistorySettings() : HistorySettings(HistorySettingsDefaults::BUFFER_SIZE, HistorySettingsDefaults::CHART_HEIGHT) {}
  HistorySettings(int _bufferSize, int _chartHeight) {
    bufferSize=_bufferSize;
    chartHeight=_chartHeight;
  }
  int getChartHeight() {return chartHeight;}
  static int getBufferSize() {return bufferSize;}
  
private:
  int chartHeight;
  static int bufferSize;
};

#endif /* HistorySettings_h */
