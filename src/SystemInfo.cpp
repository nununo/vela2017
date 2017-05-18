//
//  SystemInfo.cpp
//  vela2017
//
//  Created by Nuno on 31/03/2017.
//
//

#include "SystemInfo.h"
#include "ofMain.h"

//--------------------------------------------------------------
string SystemInfo::getTrace() {
  stringstream ss;
  
  ss << "System info: "
     << " Framerate: " << roundf(ofGetFrameRate()*1)/1
  << " Resolution: " << generalSettings.getWindowSize().x << "x" << generalSettings.getWindowSize().y;
 
  return ss.str();
}
