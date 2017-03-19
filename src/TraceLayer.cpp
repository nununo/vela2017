#include "TraceLayer.h"

//--------------------------------------------------------------
void TraceLayer::setup(InputLevel *_inputLevel) {
	font.load("frabk.ttf",12);
	inputLevel = _inputLevel;
}

//--------------------------------------------------------------
void TraceLayer::draw(string text) {
	
  ofSetHexColor(0x00FF00);
	font.drawString(text, 0, 0);
  
	// Draw arduino buffer
//	for (int i = 0; i < ARDUINO_BUFFER_SIZE; i++){
//		ofDrawLine(i,25,i,25+(arduino->getThreshold(0)-arduino->getBuffer(i))/2);
//	}
}
