//
//  ThresholdsSettings.h
//  vela2017
//
//  Created by Nuno on 12/05/2017.
//
//

#ifndef ThresholdsSettings_h
#define ThresholdsSettings_h

class ThresholdsSettings {
  
public:
  ThresholdsSettings() : ThresholdsSettings(0,0,0,false) {}
  ThresholdsSettings(float _low, float _high, float _blowOut, bool _inverted);
  float getLow() {return low;}
  float getHigh() {return high;}
  float getBlowOut() {return blowOut;}
  bool isInverted() {return inverted;}
  
private:
  float low;
  float high;
  float blowOut;
  bool inverted;
};

#endif /* ThresholdsSettings_h */
