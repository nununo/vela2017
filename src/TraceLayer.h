#ifndef TRACELAYER_H_INCLUDED
#define TRACELAYER_H_INCLUDED

#include "Layer.h"

class TraceLayer : public Layer {
  
public:
  TraceLayer();
  void update(string text);
  void drawAlgorithm();
  string getText() {return text;}
  
private:
  ofTrueTypeFont font;
  string text;
  string getSysInfo();
};

#endif // TRACELAYER_H_INCLUDED
