#ifndef LEVELCLIPS_H_INCLUDED
#define LEVELCLIPS_H_INCLUDED

#include <vector>
#include <string>
#include "ofMain.h"
#include "Layer.h"
#include "Clip.h"
using namespace std;

#define FADE_TIME 0.1

class LevelClips {

public:
  LevelClips(int _intensity, bool loop, string foldername);
  Layer *getRandomLayer();

  vector<Clip*> clips;

private:
  void loadMovies(bool loop, string foldername);
  int intensity;
};

#endif // LEVELCLIPS_H_INCLUDED
