#include "CandleLayer.h"
#include "Util.h"

//-----------------------------------------------------------------------
// Why are classes with static data members getting linker errors?
// http://forums.msdn.microsoft.com/en-US/vclanguage/thread/8655a6c5-ba8c-4d66-98e4-f0643268c25c
// http://www.faqs.org/faqs/C++-faq/part4/
float CandleLayer::offsetX = 0;
float CandleLayer::offsetY = 0;
float CandleLayer::zoomX = 1;
float CandleLayer::zoomY = 1;

//-----------------------------------------------------------------------
CandleLayer::CandleLayer(int _intensity, string _filename, ofVideoPlayer *_movie, float fadeTime, bool _loop) {
  filename = _filename;
  movie = _movie;
  loop = _loop;
  intensity = _intensity;
  // initialize variables
  lastPosition = 0;
  playing = true;
  // Rewind
  if (loop)
    movie->setLoopState(OF_LOOP_NORMAL);
  else
    movie->setLoopState(OF_LOOP_NONE);
  movie->setSpeed(1);
  movie->setPosition(0);
  // Calculate fade percentage for current movie
  fadePercentage = Util::remap(fadeTime, 0, movie->getDuration(), 0, 1);
  // Output
  cout << "Created layer for " << filename << endl;
}

//-----------------------------------------------------------------------
CandleLayer::~CandleLayer() {
  cout << "Destroyed layer for " << filename << endl;
}

//-----------------------------------------------------------------------
void CandleLayer::update() {
    movie->idleMovie();
    if (playing && lastPosition > 0 && movie->getPosition()>0.98 && (movie->getPosition() == lastPosition)) {
      if (loop)
        movie->setPosition(0);
      else
        playing = false;
      cout << "Layer " << filename << " finished." << endl;
    }
    lastPosition = movie->getPosition();
}

//-----------------------------------------------------------------------
void CandleLayer::draw() {
  if (playing) {
    int alpha = getAlpha();
    if (alpha == ALPHA_MAX)
    {
      ofDisableAlphaBlending();
      ofSetColor(0xFFFFFF);
    } else {
      ofEnableAlphaBlending();
      ofSetColor(255,255,255,alpha);
    }
    movie->draw(ofGetWidth()*CandleLayer::offsetX,
                ofGetHeight()*CandleLayer::offsetY,
                ofGetWidth()*CandleLayer::zoomX,
                ofGetHeight()*CandleLayer::zoomY);
    ofDisableAlphaBlending();
  }
}


//-----------------------------------------------------------------------
int CandleLayer::getAlpha() {
  if (loop)
    return ALPHA_MAX;
  else {
    float alpha = Util::remap(movie->getPosition(), 0, fadePercentage, 0, 1) *
      Util::remap(movie->getPosition(), 0.98-fadePercentage, 0.98, 1, 0);
    return (int)(alpha * ALPHA_MAX);
  }
}

//-----------------------------------------------------------------------
void CandleLayer::outputStatus() {
  cout << "layer " << filename << " intensity=" << intensity << " pos=" << movie->getPosition() << " playing=" << isPlaying() << endl;
}
