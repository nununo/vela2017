//
//  AnalogInput.h
//  vela2017
//
//  Created by Nuno on 09/04/2017.
//
//

#ifndef ValueInput_h
#define ValueInput_h

#include "Constants.h"
#include "ThresholdsDataInput.h"
#include "NameFloatEventArgs.h"

class ValueInput : public ThresholdsDataInput {
public:
  ValueInput(string name,
             Thresholds _thresholds,
             bool _inverted) : ThresholdsDataInput(name) {
    thresholds=_thresholds;
    inverted=_inverted;
    lastValue=0;};

  // DataInput
  virtual void update() {}
  virtual blowIntensityType getBlowIntensity();

  // ITrace
  virtual string getTrace();

  // ThresholdsDataInput
  virtual void setValue(float _value);
  virtual Thresholds* const getThresholds() {return &thresholds;}

  // Event
  static ofEvent<NameFloatEventArgs> newValue;

private:
  Thresholds thresholds;
  float lastValue;
  bool inverted;
  
  void broadcastNewValueEvent();
  
};

#endif /* AnalogInputSettings_h */
