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
  void pause(bool value=true) {clip->pause(value);}
  virtual void drawAlgorithm();
  bool isOpaque() {return clip->isOpaque();}
  int getIntensity() {return intensity;}
  bool getCanRestart() {return clip->getCanRestart();}
  
  // ITrace
  virtual string getTrace();
  
private:
  float getPosition() {return clip->getPosition();}
  float getAlpha() {return clip->getAlpha();}
  string getFilename() {return clip->getFilename();}

  Clip *clip;
  int intensity;
};

#endif // CLIPLAYER_H_INCLUDED
