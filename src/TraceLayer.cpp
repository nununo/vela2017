#include "TraceLayer.h"

//--------------------------------------------------------------
void TraceLayer::setup(Arduino *_arduino) {
	font.loadFont("frabk.ttf",12);
	arduino = _arduino;
}

//--------------------------------------------------------------
void TraceLayer::draw() {
  string text = "Intensity: " + ofToString(arduino->getLastValue()) + " " + ofToString(arduino->getLastIntensity()) + "\n";
  text += "Thresholds: " + ofToString(arduino->getThreshold(0))
      + " " + ofToString(arduino->getThreshold(1)) + " "
      + ofToString(arduino->getThreshold(2)) + "\n";
	ofSetColor(0x00FF00);
	font.drawString(text, 10,10);
	// Draw arduino buffer
	for (int i = 0; i < ARDUINO_BUFFER_SIZE; i++){
		ofLine(i,50,i,50+arduino->getThreshold(0)-arduino->getBuffer(i));
	}}
