#ifndef TRACELAYER_H_INCLUDED
#define TRACELAYER_H_INCLUDED

#include "ofMain.h"
#include "Layer.h"

class TraceLayer : public Layer {

public:
  TraceLayer();
  void update(string text);
  bool isVisible() {return visible;}
  void setVisible(bool _visible) {visible = _visible;}
  void drawAlgorithm();

private:
  ofTrueTypeFont font;
  string text;
  bool visible;
};

#endif // TRACELAYER_H_INCLUDED
