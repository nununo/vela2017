#include "TraceLayer.h"
#include <sstream>

//--------------------------------------------------------------
TraceLayer::TraceLayer() {
	font.load("frabk.ttf",10);
  visible = true;
}

//--------------------------------------------------------------
void TraceLayer::update() {
  stringstream ss;
  
  vector<ITrace*>::iterator it;
  
  for (it = list.begin(); it != list.end(); it++)
    ss << (*it)->getTrace();

  text = ss.str();
}

//--------------------------------------------------------------
void TraceLayer::drawAlgorithm() {
  
  float v = 0.05 * (float)ofGetWidth();
  glTranslatef(v, v, 0);

  ofSetHexColor(0x00FF00);
  font.drawString(text, 0, 0);
  
  glTranslatef(-v, -v, 0);

}
