//
//  TraceLayer.h
//  vela2017
//
//  Created by Nuno on 19/03/2017.
//
//

#ifndef TRACELAYER_H_INCLUDED
#define TRACELAYER_H_INCLUDED

#include "Layer.h"
#include "ITrace.h"

class TraceLayer : public Layer {
  
public:
  TraceLayer();
  void add(ITrace *trace) {list.push_back(trace);}
  void update();
  string getText() {return text;}

protected:
  void drawAlgorithm();

private:
  ofTrueTypeFont font;
  string text;
  vector<ITrace*> list;
};

#endif // TRACELAYER_H_INCLUDED
