//
//  Clip.cpp
//  vela2017
//
//  Created by Nuno on 18/03/2017.
//
//

#include "Clip.h"
#include "util.h"

//-----------------------------------------------------------------------
// Why are classes with static data members getting linker errors?
// http://forums.msdn.microsoft.com/en-US/vclanguage/thread/8655a6c5-ba8c-4d66-98e4-f0643268c25c
// http://www.faqs.org/faqs/C++-faq/part4/
float Clip::offsetX = 0;
float Clip::offsetY = 0;
float Clip::zoomX = 1;
float Clip::zoomY = 1;

//-----------------------------------------------------------------------
Clip::Clip(string _filename, ofVideoPlayer *_movie, bool _loop, float fadeTime) {
  filename = _filename;
  movie = _movie;
  fadePercentage = timeToPercentage(fadeTime);

  setLoop(_loop);

  stop();
  rewind();
}

void Clip::setLoop(bool _loop) {
  _loop = loop;
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
void Clip::rewind_and_play() {
  if (loop)
    movie->setLoopState(OF_LOOP_NORMAL);
  else
    movie->setLoopState(OF_LOOP_NONE);
  
  movie->setSpeed(1);
  movie->setPosition(0);
}

//-----------------------------------------------------------------------
void Clip::rewind() {
  
  movie->setPosition(0);
}


//-----------------------------------------------------------------------
void Clip::update() {

  movie->update();
  
  //if (playing && lastPosition > 0 && movie->getPosition()>0.98 && (movie->getPosition() == lastPosition))
  if (movie->getPosition()>0.98) {
    if (loop)
      rewind_and_play();
    else
      stop();
  }
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
    movie->draw(ofGetWidth()*Clip::offsetX,
                ofGetHeight()*Clip::offsetY,
                ofGetWidth()*Clip::zoomX,
                ofGetHeight()*Clip::zoomY);
    ofDisableAlphaBlending();
  }
}


//-----------------------------------------------------------------------
int Clip::getAlpha() {
  if (loop)
    return ALPHA_MAX;
  else {
    float alpha = Util::remap(movie->getPosition(), 0, fadePercentage, 0, 1) *
    Util::remap(movie->getPosition(), 0.98-fadePercentage, 0.98, 1, 0);
    return (int)(alpha * ALPHA_MAX);
  }
}
