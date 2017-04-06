//
//  SystemTrace.cpp
//  vela2017
//
//  Created by Nuno on 31/03/2017.
//
//

#include "SystemTrace.h"
#include "ofMain.h"

string SystemTrace::getTrace() {
  stringstream ss;
  
  ss << "System info: "
     << " Framerate: " << roundf(ofGetFrameRate()*1)/1
     << " Resolution: " << ofGetWidth() << "x" << ofGetHeight() << "\n";
 
  return ss.str();
}
