#include "TraceLayer.h"

//--------------------------------------------------------------
TraceLayer::TraceLayer() {
	font.load("frabk.ttf",12);
  visible = true;
}

//--------------------------------------------------------------
string TraceLayer::getSysInfo() {
  return "System info:\n"
          "  Framerate: " + ofToString(ofGetFrameRate()) + "\n";
}

//--------------------------------------------------------------
void TraceLayer::update(string _text) {
  text = getSysInfo() + _text;
}

//--------------------------------------------------------------
void TraceLayer::drawAlgorithm() {

  float v = 0.05 * (float)ofGetWidth();
  glTranslated(v, v, 0);

  ofSetHexColor(0x00FF00);
	font.drawString(text, 0, 0);
  
  glTranslated(-v, -v, 0);

}
