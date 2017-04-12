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
  LevelSettings(string _movieFolder, float _fadeInTime, float _fadeOutTime, bool _loop, bool _canRestart);
  string getMovieFolder() {return movieFolder;}
  float getFadeInTime() {return fadeInTime;}
  float getFadeOutTime() {return fadeOutTime;}
  bool getLoop() {return loop;}
  bool getCanRestart() {return canRestart;}
  
private:
  string movieFolder;
  float fadeInTime;
  float fadeOutTime;
  bool loop;
  bool canRestart;
};

#endif /* LevelSettings_h */
