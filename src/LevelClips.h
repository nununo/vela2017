#ifndef LEVELCLIPS_H_INCLUDED
#define LEVELCLIPS_H_INCLUDED

#include <vector>
#include <string>
#include "ofMain.h"
#include "Layer.h"
using namespace std;

#define FADE_TIME 0.1

class LevelClips {

  public:
    LevelClips(int _intensity, string foldername);
    Layer *getNewLayer(bool loop);

    vector<ofVideoPlayer*> movies;
    vector<string> filenames;

  private:
    int intensity;
};

#endif // LEVELCLIPS_H_INCLUDED
