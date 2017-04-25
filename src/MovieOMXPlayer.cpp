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
MovieOMXPlayer::MovieOMXPlayer(string _filename, bool loop) {

  filename = ofToDataPath(_filename, true);

  //Somewhat like ofFboSettings we may have a lot of options so this is the current model
  ofxOMXPlayerSettings settings;
  settings.videoPath = filename;
  settings.useHDMIForAudio = true;	//default true
  settings.enableTexture = true;		//default true
  settings.enableLooping = loop;		//default true
  settings.enableAudio = false;		//default true, save resources by disabling

  movie.setup(settings);
  
  lastPosition = -1;
  finished = false;
}

//--------------------------------------------------------------
void MovieOMXPlayer::update() {
  if (getPosition() == lastPosition) {
    finished = true;
  }
  lastPosition = getPosition();
}

//--------------------------------------------------------------
void MovieOMXPlayer::draw(float x, float y, float width, float height) {

  if (finished)
    return;
  
  ofPushStyle();
  
  if (getAlpha() == ALPHA_MAX)
    ofDisableAlphaBlending();
  else
    ofEnableAlphaBlending();

  ofSetColor(255,255,255,getAlpha());

  movie.draw(x, y, width, height);

  ofDisableAlphaBlending();
  
  ofPopStyle();
}

#endif
