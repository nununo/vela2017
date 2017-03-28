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
  
  setLoop(_loop);

  stop();
  rewind();
}

//-----------------------------------------------------------------------
ofVideoPlayer *Clip::loadMovie(string filename) {
  ofVideoPlayer *newMovie = new ofVideoPlayer();
  newMovie->load(filename);
  newMovie->play();
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
// Convert movie time position to percentage position
  return Util::remap(fadeTime, 0, movie->getDuration(), 0, 1);
}

//-----------------------------------------------------------------------
void Clip::update() {

  float newPosition;
  
  movie->update();
  
  alpha = calcAlpha();
  
  newPosition = movie->getPosition();
  
  if (newPosition>0.98) {
    if (newPosition == lastPosition)
      cout << "newPosition " << newPosition << " = lastPosition " << lastPosition << "\n";
    if (loop) {
      rewind();
      play();
    }
    else
      stop();
  } else
    lastPosition = newPosition;
  }

//-----------------------------------------------------------------------
void Clip::draw() {
  
  if (isPlaying()) {
    int alpha = getAlpha();
    if (alpha == ALPHA_MAX)
    {
      ofDisableAlphaBlending();
      ofSetHexColor(0xFFFFFF);
    } else {
      ofEnableAlphaBlending();
      ofSetColor(255,255,255,alpha);
    }
    movie->draw(ofGetWidth()*clipOutputSettings->getOffsetX(),
                ofGetHeight()*clipOutputSettings->getOffsetY(),
                ofGetWidth()*clipOutputSettings->getZoomX(),
                ofGetHeight()*clipOutputSettings->getZoomY());
    ofDisableAlphaBlending();
  }
}


//-----------------------------------------------------------------------
int Clip::calcAlpha() {
  if (loop)
    return ALPHA_MAX;
  else {
    float alpha = Util::remap(movie->getPosition(), 0, fadePercentage, 0, 1) *
      Util::remap(movie->getPosition(), 0.98-fadePercentage, 0.98, 1, 0);
    return (int)(alpha * ALPHA_MAX);
  }
}
