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
  settings.enableTexture = false;		//default true
  settings.enableLooping = loop;		//default true
  settings.enableAudio = false;		//default true, save resources by disabling


  movie.setup(settings);
}

//--------------------------------------------------------------
void MovieOMXPlayer::draw(float x, float y, float width, float height) {
/*
  if (alpha == ALPHA_MAX)
    ofDisableAlphaBlending();
  else
    ofEnableAlphaBlending();

  //ofSetColor(ofColor::white);

  movie.setAlpha(alpha);
  movie.draw(x, y, width, height);

  ofDisableAlphaBlending();
*/
}

#endif
