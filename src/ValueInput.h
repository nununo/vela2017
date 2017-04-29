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
#include "ThresholdsDataInput.h"
#include "NameFloatEventArgs.h"

class ValueInput : public ThresholdsDataInput {
public:
  ValueInput(string name, Thresholds _thresholds) : ThresholdsDataInput(name) {
    thresholds=_thresholds;
    lastValue=0;};

  // DataInput
  virtual void update() {}
  virtual BlowIntensity getBlowIntensity() {return thresholds.getBlowIntensity(lastValue);}

  // ITrace
  virtual string getTrace();

  // ThresholdsDataInput
  virtual void setValue(float _value);
  virtual Thresholds* const getThresholds() {return &thresholds;}

  // Event
  static ofEvent<NameFloatEventArgs> newValue;

private:
  void broadcastNewValueEvent();

  Thresholds thresholds;
  float lastValue;
};

#endif /* AnalogInputSettings_h */
