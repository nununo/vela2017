//
//  AnalogInput.h
//  vela2017
//
//  Created by Nuno on 09/04/2017.
//
//

#ifndef ValueInput_h
#define ValueInput_h

#include "BlowIntensity.h"
#include "NameFloatEventArgs.h"
#include "Thresholds.h"
#include "DataInput.h"

class ValueInput : public DataInput {
public:
  ValueInput(string name, ThresholdsSettings thresholdsSettings);
  
  // DataInput
  virtual void update() {}
  virtual BlowIntensity getBlowIntensity() {return thresholds.getBlowIntensity(lastValue);}

  // ITrace
  virtual string getTrace();

  // ThresholdsDataInput
  virtual void setValue(float _value);
  Thresholds* const getThresholds() {return &thresholds;}

  // Event
  static ofEvent<NameFloatEventArgs> newValue;

private:
  void broadcastNewValueEvent();

  Thresholds thresholds;
  float lastValue;
};

#endif /* AnalogInputSettings_h */
