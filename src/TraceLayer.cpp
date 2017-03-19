#include "TraceLayer.h"

//--------------------------------------------------------------
TraceLayer::TraceLayer() {
	font.load("frabk.ttf",12);
  visible = true;
}

//--------------------------------------------------------------
void TraceLayer::update(string _text) {
  text = _text;
}

//--------------------------------------------------------------
void TraceLayer::drawAlgorithm() {

  float v = 0.05 * (float)ofGetWidth();
  glTranslated(v, v, 0);

  ofSetHexColor(0x00FF00);
	font.drawString(text, 0, 0);
  
  glTranslated(-v, -v, 0);

	// Draw arduino buffer
//	for (int i = 0; i < ARDUINO_BUFFER_SIZE; i++){
//		ofDrawLine(i,25,i,25+(arduino->getThreshold(0)-arduino->getBuffer(i))/2);
//	}
}
