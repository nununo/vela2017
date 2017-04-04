#ifndef CLIPS_H_INCLUDED
#define CLIPS_H_INCLUDED

#include <vector>
#include <string>
#include "ofMain.h"
#include "Clip.h"
using namespace std;

#define FADE_TIME 0.5

class Clips {

public:
  Clips(ClipOutputSettings *clipOutputSettings, bool loop, string foldername);
  Clip *getRandomClip();

  vector<Clip*> list;

private:
  void loadMovies(ClipOutputSettings *clipOutputSettings, bool loop, string foldername);
};

#endif // CLIPS_H_INCLUDED
