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

namespace LevelType {
  const std::string PRELOAD = "preload";
  const std::string THREAD_CHANNEL = "threadChannel";
  const std::string ON_DEMAND = "onDemand";
}

class LevelSettings {
public:
  LevelSettings(std::string levelType, std::string movieFolder, float fadeOutTime, bool loop, float cannotRestartTime);
  std::string getLevelType() {return levelType;}
  std::string getMovieFolder() {return movieFolder;}
  float getFadeOutTime() {return fadeOutTime;}
  bool getLoop() {return loop;}
  float getCannotRestartTime() {return cannotRestartTime;}
  
private:
  std::string levelType;
  std::string movieFolder;
  float fadeOutTime;
  bool loop;
  float cannotRestartTime;
};

#endif /* LevelSettings_h */
