#ifndef TRACELAYER_H_INCLUDED
#define TRACELAYER_H_INCLUDED

#include "ofMain.h"
#include "InputLevel.h"

class TraceLayer {

  public:
    void setup(InputLevel *_inputLevel);
    void update();
    void draw(string text);

  private:
    ofTrueTypeFont font;
    InputLevel *inputLevel;
};

#endif // TRACELAYER_H_INCLUDED
