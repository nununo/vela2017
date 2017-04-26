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
#include "DataInput.h"
#include "NameFloatEventArgs.h"
#include "Thresholds.h"

class ValueInput : public DataInput {
public:
  ValueInput(string name,
             Thresholds thresholds,
             bool inverted);

  // DataInput
  virtual void update() {}
  virtual blowIntensityType getBlowIntensity();

  // ITrace
  virtual string getTrace();

  void setValue(int _value);
  Thresholds* getThresholds() {return &thresholds;}

  // Event
  static ofEvent<NameFloatEventArgs> newValue;

private:
  Thresholds thresholds;
  float lastValue;
  bool inverted;
  
  void broadcastNewValueEvent();
  
};

#endif /* AnalogInputSettings_h */
