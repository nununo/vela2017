#ifndef TRACELAYER_H_INCLUDED
#define TRACELAYER_H_INCLUDED

#include "Layer.h"
#include "ITrace.h"

class TraceLayer : public Layer {
  
public:
  TraceLayer();
  void add(ITrace *trace) {list.push_back(trace);}
  void drawAlgorithm();
  void update();
  string getText() {return text;}
  
private:
  ofTrueTypeFont font;
  string text;
  vector<ITrace*> list;
};

#endif // TRACELAYER_H_INCLUDED
