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
Clip::Clip(ClipOutputSettings *_clipOutputSettings, string _filename, bool _loop, float fadeTime) {
  
  filename = _filename;

  movie = loadMovie(filename);
  
  clipOutputSettings = _clipOutputSettings;

  fadePercentage = timeToPercentage(fadeTime);

  alpha = 0;
  freezeCount = 0;
  
  setLoop(_loop);

  stop();
}

//-----------------------------------------------------------------------
ofVideoPlayer *Clip::loadMovie(string filename) {
  ofVideoPlayer *newMovie = new ofVideoPlayer();
  newMovie->load(filename);
  return newMovie;
}

//-----------------------------------------------------------------------
void Clip::setLoop(bool _loop) {
  loop = _loop;
  if (loop)
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

  if (!isPlaying())
    return;
  
  movie->update();

  if (!loop && lastPosition == movie->getPosition())
    if (++freezeCount > FREEZE_FRAMES_MAX) {
      stop();
      freezeCount = 0;
    }
  
  alpha = calcAlpha();
    
  lastPosition = movie->getPosition();
}

//-----------------------------------------------------------------------
void Clip::draw() {
  
  if (!isPlaying())
    return;

  if (getAlpha() == ALPHA_MAX)
  {
    ofDisableAlphaBlending();
    ofSetHexColor(0xFFFFFF);
  } else {
    ofEnableAlphaBlending();
    ofSetColor(255, 255, 255, getAlpha());
  }
  movie->draw(ofGetWidth()*clipOutputSettings->getOffsetX(),
              ofGetHeight()*clipOutputSettings->getOffsetY(),
              ofGetWidth()*clipOutputSettings->getZoomX(),
              ofGetHeight()*clipOutputSettings->getZoomY());
  ofDisableAlphaBlending();
}


//-----------------------------------------------------------------------
int Clip::calcAlpha() {
  if (loop)
    return ALPHA_MAX;
  else {
    float alpha = 
      Util::remap(movie->getPosition(), 0, fadePercentage, 0, 1) *        // Fade in
      Util::remap(movie->getPosition(), 0.98-fadePercentage, 0.98, 1, 0); // Fade out
    return (int)(alpha * ALPHA_MAX);
  }
}
