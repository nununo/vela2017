#ifndef CANDLELAYER_H_INCLUDED
#define CANDLELAYER_H_INCLUDED

#include "ofMain.h"
#include "Clip.h"
#include <string>
using namespace std;

#define ALPHA_MAX 255

class Layer {

public:
  Layer(int _intensity, Clip *_clip);
  ~Layer();
  void update();
  void draw();
  int getIntensity() {return intensity;}
  bool isPlaying() {return clip->isPlaying();}
  void outputStatus();
  bool isOpaque() {return clip->isOpaque();};

private:
  Clip *clip;
  int intensity;
};

#endif // CANDLELAYER_H_INCLUDED
