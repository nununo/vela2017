#ifndef CLIPLAYER_H_INCLUDED
#define CLIPLAYER_H_INCLUDED

#include "ofMain.h"
#include <string>
#include "Clip.h"
#include "Layer.h"
#include "ITrace.h"

using namespace std;

class ClipLayer: public Layer, public ITrace {

public:
  ClipLayer(int _intensity, Clip *_clip);
  virtual ~ClipLayer();
  void update();
  virtual void drawAlgorithm();
  int getIntensity() {return intensity;}
  string getFilename() {return clip->getFilename();}
  float getPosition() {return clip->getPosition();}
  float getAlpha() {return clip->getAlpha();}
  bool isOpaque() {return clip->isOpaque();}
  
  // ITrace
  virtual string getTrace();
  
private:
  Clip *clip;
  int intensity;
};

#endif // CLIPLAYER_H_INCLUDED
