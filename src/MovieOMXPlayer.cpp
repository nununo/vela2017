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
MovieOMXPlayer::MovieOMXPlayer(string _filename) {

  filename = ofToDataPath(_filename, true);

  //Somewhat like ofFboSettings we may have a lot of options so this is the current model
  ofxOMXPlayerSettings settings;
  settings.videoPath = filename;
  settings.useHDMIForAudio = true;	//default true
  settings.enableTexture = true;		//default true
  settings.enableLooping = true;		//default true
  settings.enableAudio = false;		//default true, save resources by disabling
  //settings.doFlipTexture = true;		//default false

  movie.setup(settings);
}

//--------------------------------------------------------------
void MovieOMXPlayer::setLoop(bool loop) {
  if (loop)
    movie.enableLooping();
  else
    movie.disableLooping();
}

#endif
