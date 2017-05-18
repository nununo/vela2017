//
//  InfoLayer.cpp
//  vela2017
//
//  Created by Nuno on 19/03/2017.
//
//

#include "InfoLayer.h"

//--------------------------------------------------------------
InfoLayer::InfoLayer(GeneralSettings generalSettings,
                     LayerSettings layerSettings) : Layer(generalSettings, layerSettings) {
	font.load("frabk.ttf",10);
}

//--------------------------------------------------------------
void InfoLayer::update() {
  stringstream ss;

  vector<ITrace*>::iterator it;

  for (it = list.begin(); it != list.end(); it++)
    ss << (*it)->getTrace() << endl;

  text = ss.str();
}

//--------------------------------------------------------------
void InfoLayer::drawAlgorithm() {
  
  ofPushStyle();
  ofPushMatrix();
  ofSetColor(ofColor::white);

  ofTranslate(10, 20);
  font.drawString(text, 0, 0);

  ofPopMatrix();
  ofPopStyle();
}
