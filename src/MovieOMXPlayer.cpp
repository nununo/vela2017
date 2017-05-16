//
//  MovieOMXPlayer.cpp
//  vela2017
//
//  Created by Nuno on 24/04/2017.
//
//

#ifdef TARGET_RASPBERRY_PI

#include "MovieOMXPlayer.h"

//--------------------------------------------------------------
MovieOMXPlayer::MovieOMXPlayer(string _filename, bool _loop, ofColor color) {

  filename=_filename;
  color = _color;

  //Somewhat like ofFboSettings we may have a lot of options so this is the current model
  ofxOMXPlayerSettings settings;
  settings.videoPath = ofToDataPath(filename, true);
  settings.useHDMIForAudio = true;	//default true
  settings.enableTexture = true;		//default true
  settings.enableLooping = _loop;		//default true
  settings.enableAudio = false;		//default true, save resources by disabling

  movie.setup(settings);
  
  lastPosition = -1;
  finished = false;
}

//--------------------------------------------------------------
void MovieOMXPlayer::calcFinished() {
  if (!getLoop() && !isPaused() && getPosition()>0.95f && (getPosition()==lastPosition || getPosition()>1)) {
    finished = true;
  }
  lastPosition = getPosition();
}

//--------------------------------------------------------------
bool MovieOMXPlayer::getLoop() {
  return movie.getSettings().enableLooping;
}

//--------------------------------------------------------------
void MovieOMXPlayer::update() {
  calcFinished();
}

//--------------------------------------------------------------
void MovieOMXPlayer::draw(float x, float y, float width, float height) {
  
  ofPushStyle();
  
  if (getAlpha() == ALPHA_MAX)
    ofDisableAlphaBlending();
  else
    ofEnableAlphaBlending();

  ofSetColor(color,getAlpha());

  movie.draw(x, y, width, height);

  ofDisableAlphaBlending();
  
  ofPopStyle();
}

#endif
