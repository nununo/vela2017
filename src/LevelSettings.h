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

class LevelSettings {
public:
  LevelSettings(std::string movieFolder, float fadeInTime, float fadeOutTime, bool loop, bool canRestart, bool threadedMovieLoad);
  std::string getMovieFolder() {return movieFolder;}
  float getFadeInTime() {return fadeInTime;}
  float getFadeOutTime() {return fadeOutTime;}
  bool getLoop() {return loop;}
  bool getCanRestart() {return canRestart;}
  bool isThreadedMovieLoad() {return threadedMovieLoad;}
  
private:
  std::string movieFolder;
  float fadeInTime;
  float fadeOutTime;
  bool loop;
  bool canRestart;
  bool threadedMovieLoad;
};

#endif /* LevelSettings_h */
