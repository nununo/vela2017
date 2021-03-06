#ifndef CLIPLAYER_H_INCLUDED
#define CLIPLAYER_H_INCLUDED

#include "ofMain.h"
#include "Clip.h"
#include "Layer.h"
#include "ITrace.h"
#include "BlowIntensity.h"

class ClipLayer: public Layer, public ITrace {

public:
  ClipLayer(LayerSettings layerSettings, BlowIntensity _intensity, Clip *_clip);
  virtual ~ClipLayer();
  void update();
  void pause(bool value=true) {clip->pause(value);}
  bool isOpaque() {return clip->isOpaque();}
  BlowIntensity getIntensity() {return intensity;}
  bool getCanBeInterrupted() {return clip->getCanBeInterrupted();}
  
  // ITrace
  virtual string getTrace();

protected:
  virtual void drawAlgorithm();
  
private:
  float getPosition() {return clip->getPosition();}
  float getAlpha() {return clip->getAlpha();}
  std::string getFilename() {return clip->getFilename();}

  Clip *clip;
  BlowIntensity intensity;
};

#endif // CLIPLAYER_H_INCLUDED
