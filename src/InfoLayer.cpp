//
//  InfoLayer.cpp
//  vela2017
//
//  Created by Nuno on 19/03/2017.
//
//

#include "InfoLayer.h"

//--------------------------------------------------------------
InfoLayer::InfoLayer(LayerSettings settings) : Layer(settings) {
	font.load("frabk.ttf",10);
}

//--------------------------------------------------------------
void InfoLayer::update() {
  stringstream ss;

  vector<ITrace*>::iterator it;

  for (it = list.begin(); it != list.end(); it++)
    ss << (*it)->getTrace();

  text = ss.str();
}

//--------------------------------------------------------------
void InfoLayer::drawAlgorithm() {
  
  ofPushStyle();
  
  ofSetColor(ofColor::white);

  font.drawString(text, 0, 0);

  ofPopStyle();
}
