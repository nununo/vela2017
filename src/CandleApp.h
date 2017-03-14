#pragma once

#include "ofMain.h"
#include "XmlStore.h"
#include "Util.h"
#include "Arduino.h"
#include "TraceLayer.h"
#include "CandleLayer.h"
#include "CandleLevel.h"

class CandleApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		
};
