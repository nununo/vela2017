#ifndef CLIPLAYER_H_INCLUDED
#define CLIPLAYER_H_INCLUDED

#include "ofMain.h"
#include "Clip.h"
#include "Layer.h"
#include "ITrace.h"
#include "BlowIntensity.h"

class ClipLayer: public Layer, public ITrace {

public:
  ClipLayer(GeneralSettings generalSettings, LayerSettings layerSettings, BlowIntensity intensity, Clip *clip);
  virtual ~ClipLayer();
  void update();
  void pause(bool value=true) {clip->pause(value);}
  bool isOpaque() {return clip->isOpaque();}
  BlowIntensity getIntensity() {return intensity;}
  bool getCanRestart() {return clip->getCanRestart();}
  
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
