#ifndef CLIPLAYER_H_INCLUDED
#define CLIPLAYER_H_INCLUDED

#include "ofMain.h"
#include "Clip.h"
#include <string>
using namespace std;

#define ALPHA_MAX 255

class ClipLayer {

public:
  ClipLayer(int _intensity, Clip *_clip);
  ~ClipLayer();
  void update();
  void draw();
  int getIntensity() {return intensity;}
  bool isPlaying() {return clip->getVisible();}
  void outputStatus();

private:
  Clip *clip;
  int intensity;
};

#endif // CLIPLAYER_H_INCLUDED
