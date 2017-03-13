#ifndef _VELA_APP
#define _VELA_APP

#define OF_ADDON_USING_OFXDIRLIST

#include <vector>
#include <string>
#include "ofMain.h"
#include "ofAddons.h"
#include "CandleLevel.h"
#include "CandleLayer.h"
#include "Arduino.h"
#include "XmlStore.h"
#include "TraceLayer.h"
using namespace std;

#define XML_FILENAME "vela.xml"

class CandleApp : public ofSimpleApp{

	public:
    enum InputType { InputArduino, InputMouse };

		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);

  private:
    void addLayer() {addLayer(arduino.getLastIntensity());}
    void addLayer(int intensity);
    void outputLayerStatus();
    void checkTrigger();
    void setTrace(bool value) {bTrace = value;}
    void setFullscreen(bool value);
    void setAutoFlickerMinPeriod(int value) {autoFlickerMinPeriod = value;}
    void toggleTrace() {setTrace(!bTrace);}
    void toggleFullscreen() {setFullscreen(!bFullscreen);}
    void autoFlicker();

    Arduino arduino;
    vector<CandleLevel*> levels;
    vector<CandleLayer*> layers;
    CandleLayer *baseLayer;
    XmlStore xmlStore;
    TraceLayer traceLayer;
    int previousIntensity;
    bool bFullscreen;
    bool bTrace;
    InputType inputType;
    int autoFlickerMinPeriod;
    int autoFlickerLastTime;
};

#endif

