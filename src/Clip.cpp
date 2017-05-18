//
//  Clip.cpp
//  vela2017
//
//  Created by Nuno on 18/03/2017.
//
//

#include "Clip.h"
#include "Util.h"
#include <ostream>
#include "MovieFactory.h"

//-----------------------------------------------------------------------
Clip::Clip(GeneralSettings generalSettings, ClipOutputSettings _clipOutputSettings, LevelSettings *_levelSettings, string filename) {

  clipOutputSettings = _clipOutputSettings;
  levelSettings = _levelSettings;
  movie = createMovie(generalSettings, filename);

  pause();

  fadeOutPercentage = timeToPercentage(levelSettings->getFadeOutTime());

  movie->setAlpha(ALPHA_MAX);
}

//-----------------------------------------------------------------------
Clip::~Clip() {
  delete movie;
  movie = NULL;
  levelSettings = NULL;
}

//-----------------------------------------------------------------------
MovieBase* Clip::createMovie(GeneralSettings generalSettings, string filename) {
  ofLogNotice() << "Creating movie " << filename;
  return MovieFactory::create(filename,
                              levelSettings->getLoop(),
                              clipOutputSettings.getColor(),
                              generalSettings.getUseOmxPlayer());
}

//-----------------------------------------------------------------------
float Clip::timeToPercentage(float time) {
  return Util::remap(time, 0, movie->getDuration(), 0, 1);
}

//-----------------------------------------------------------------------
void Clip::update() {

  pause(false);

  movie->update();
  movie->setAlpha(calcAlpha());
}

//-----------------------------------------------------------------------
void Clip::draw() {
  movie->draw(0,
              0,
              ofGetWidth()*clipOutputSettings.getZoomX(),
              ofGetHeight()*clipOutputSettings.getZoomY());
}

//-----------------------------------------------------------------------
int Clip::calcAlpha() {
  if (levelSettings->getLoop())
    return ALPHA_MAX;
  else {
    float alpha = Util::remap(movie->getPosition(), 0.98-fadeOutPercentage, 0.98, 1, 0);
    return (int)(alpha * ALPHA_MAX);
  }
}

//-----------------------------------------------------------------------
bool Clip::getCanRestart() {
  return movie->getPosition() > timeToPercentage(levelSettings->getCannotRestartTime());
}

//-----------------------------------------------------------------------
void Clip::pause(bool value) {
  if (!movie->isPaused() && value) {
    movie->setPaused(true);
    ofLogNotice() << " Clip " << movie->getFilename() << " paused";
  } else if (movie->isPaused() && !value) {
    movie->setPaused(false);
    ofLogNotice() << " Clip " << movie->getFilename() << " unpaused";
  }
}

//-----------------------------------------------------------------------
string Clip::getTrace() {
  stringstream ss;
  
  ss << movie->getTrace() << " Playing: " << isPlaying() << " Alpha: " << getAlpha();
  return ss.str();
}
