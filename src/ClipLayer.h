#ifndef CLIPLAYER_H_INCLUDED
#define CLIPLAYER_H_INCLUDED

#include "ofMain.h"
#include <string>
#include "Clip.h"
#include "Layer.h"
using namespace std;

#define ALPHA_MAX 255

class ClipLayer: public Layer {

public:
  ClipLayer(int _intensity, Clip *_clip);
  virtual ~ClipLayer();
  void update();
  virtual void drawAlgorithm();
  int getIntensity() {return intensity;}
  virtual bool isVisible() {return clip->isPlaying();}
  void outputStatus();

private:
  Clip *clip;
  int intensity;
};

#endif // CLIPLAYER_H_INCLUDED
