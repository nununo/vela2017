#ifndef CANDLELEVEL_H_INCLUDED
#define CANDLELEVEL_H_INCLUDED

#include <vector>
#include <string>
#include "ofMain.h"
#include "CandleLayer.h"
using namespace std;

#define FADE_TIME 0.1

class CandleLevel {

  public:
    CandleLevel(int _intensity, string foldername);
    CandleLayer *getNewLayer(bool loop);

    vector<ofVideoPlayer*> movies;
    vector<string> filenames;

  private:
    int intensity;
};

#endif // CANDLELEVEL_H_INCLUDED
