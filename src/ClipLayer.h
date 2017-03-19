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
  string getFilename() {return clip->getFilename();}
  float getPosition() {return clip->getPosition();}
  bool isVisible() {return clip->isPlaying();}
  float getAlpha() {return clip->getAlpha();}
  bool isOpaque() {return clip->isOpaque();}

private:
  Clip *clip;
  int intensity;
};

#endif // CLIPLAYER_H_INCLUDED
