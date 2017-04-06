//
//  Clip.cpp
//  vela2017
//
//  Created by Nuno on 18/03/2017.
//
//

#include "Clip.h"
#include "Util.h"

//-----------------------------------------------------------------------
Clip::Clip(ClipOutputSettings *_clipOutputSettings, LevelSettings *_levelSettings, string _filename) {
  
  clipOutputSettings = _clipOutputSettings;
  levelSettings = _levelSettings;
  filename = _filename;

  setupMovie();

  fadeInPercentage = timeToPercentage(levelSettings->getFadeInTime());
  fadeOutPercentage = timeToPercentage(levelSettings->getFadeOutTime());

  alpha = 0;
  }

//-----------------------------------------------------------------------
void Clip::setupMovie() {

  movie = new ofVideoPlayer();
#ifdef TARGET_RASPBERRY_PI
  movie->setPixelFormat(OF_PIXELS_NATIVE);
#endif
  movie->load(filename);
  movie->play();
  pause();

  if (levelSettings->getLoop())
    movie->setLoopState(OF_LOOP_NORMAL);
  else
    movie->setLoopState(OF_LOOP_NONE);
}

//-----------------------------------------------------------------------
float Clip::timeToPercentage(float fadeTime) {
  return Util::remap(fadeTime, 0, movie->getDuration(), 0, 1);
}

//-----------------------------------------------------------------------
void Clip::update() {
  
  pause(false);
  
  movie->update();

  alpha = calcAlpha();
}

//-----------------------------------------------------------------------
void Clip::draw() {
  
  if (getAlpha() == ALPHA_MAX)
  {
    ofDisableAlphaBlending();
    ofSetHexColor(0xFFFFFF);
  } else {
    ofEnableAlphaBlending();
    ofSetColor(255, 255, 255, getAlpha());
  }
  movie->draw(clipOutputSettings->getOffsetX(),
              clipOutputSettings->getOffsetY(),
              ofGetWidth()*clipOutputSettings->getZoomX(),
              ofGetHeight()*clipOutputSettings->getZoomY());
  ofDisableAlphaBlending();
}


//-----------------------------------------------------------------------
int Clip::calcAlpha() {
  if (levelSettings->getLoop())
    return ALPHA_MAX;
  else {
    float alpha =
    Util::remap(movie->getPosition(), 0, fadeInPercentage, 0, 1) *        // Fade in
    Util::remap(movie->getPosition(), 0.98-fadeOutPercentage, 0.98, 1, 0); // Fade out
    return (int)(alpha * ALPHA_MAX);
  }
}

//-----------------------------------------------------------------------
void Clip::rewind() {
  movie->setPosition(0);
  movie->play();
}

//-----------------------------------------------------------------------
void Clip::pause(bool value) {
  if (!movie->isPaused() && value) {
    movie->setPaused(true);
    cout << " Clip " << filename << " paused\n";
  } else if (movie->isPaused() && !value) {
    movie->setPaused(false);
    cout << " Clip " << filename << " unpaused\n";
  }
}
