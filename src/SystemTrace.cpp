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
  return "System info:\n"
  "  Framerate: " + ofToString(roundf(ofGetFrameRate()*1)/1) + "\n";
 
}
