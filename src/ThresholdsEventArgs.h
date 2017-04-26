//
//  ThresholdsEventArgs.h
//  vela2017
//
//  Created by Nuno on 26/04/2017.
//
//

#ifndef ThresholdsEventArgs_h
#define ThresholdsEventArgs_h


#include "ofMain.h"
#include "Thresholds.h"

class ThresholdsEventArgs : public ofEventArgs {
  
public:
  ThresholdEventArgs(string _name, Thresholds _thresholds) {name=_name; thresholds=_thresholds;}
  string getName() {return name;}
  Thresholds getThresholds() {return thresholds;}
  
private:
  string name;
  Thresholds thresholds;
};

#endif /* ThresholdsEventArgs_h */
