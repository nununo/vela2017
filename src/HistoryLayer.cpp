//
//  HistoryLayer.cpp
//  vela2017
//
//  Created by Nuno on 19/03/2017.
//
//

#include "HistoryLayer.h"
#include "ofMain.h"

//--------------------------------------------------------------
HistoryLayer::HistoryLayer() {
  visible = true;
  initializeBuffer();
}

//--------------------------------------------------------------
void HistoryLayer::initializeBuffer() {
  for (int i=0; i<BUFFER_SIZE; i++)
    buffer[i]=0;
  bufferCursor = 0;
}

//--------------------------------------------------------------
void HistoryLayer::saveValue(float value) {
  buffer[bufferCursor] = value;
  if (++bufferCursor >= BUFFER_SIZE)
    bufferCursor = 0;
}

//--------------------------------------------------------------
void HistoryLayer::drawAlgorithm() {

  int height = ofGetScreenHeight();

  for (int i = 0; i < BUFFER_SIZE; i++){
    ofDrawLine(i, height, i, height-20-buffer[i]);
  }
}
