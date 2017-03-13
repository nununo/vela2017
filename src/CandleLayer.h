#ifndef CANDLELAYER_H_INCLUDED
#define CANDLELAYER_H_INCLUDED

#include "ofMain.h"
#include <string>
using namespace std;

#define ALPHA_MAX 255

class CandleLayer {

  public:
    CandleLayer(int _intensity, string _filename, ofVideoPlayer *_movie, float fadeTime, bool _loop);
    ~CandleLayer();
    void update();
    void draw();
    bool isOpaque() {return movie->getPosition() > fadePercentage;}
    int getIntensity() {return intensity;}
    bool isPlaying() {return playing;}
    void outputStatus();

    static void configure(float _offsetX, float _offsetY, float _zoomX, float _zoomY) {offsetX = _offsetX; offsetY = _offsetY; zoomX = _zoomX; zoomY = _zoomY;}

  private:
    string filename;
    ofVideoPlayer *movie;
    float fadePercentage;
    bool loop;
    int intensity;
    bool playing;
    float lastPosition;

    static float offsetX;
    static float offsetY;
    static float zoomX;
    static float zoomY;

    int getAlpha();
};

#endif // CANDLELAYER_H_INCLUDED
