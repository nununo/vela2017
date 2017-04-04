//
//  LevelSettings.h
//  vela2017
//
//  Created by Nuno on 04/04/2017.
//
//

#ifndef LevelSettings_h
#define LevelSettings_h

#include <string>
using namespace std;

class LevelSettings {
public:
  LevelSettings(string _movieFolder, float _fadeInTime, float _fadeOutTime, float _threshold, bool _loop);
  string getMovieFolder() {return movieFolder;}
  float getFadeInTime() {return fadeInTime;}
  float getFadeOutTime() {return fadeOutTime;}
  float getThreshold() {return threshold;}
  bool getLoop() {return loop;}
  
private:
  string movieFolder;
  float fadeInTime;
  float fadeOutTime;
  float threshold;
  bool loop;
};

#endif /* LevelSettings_h */
