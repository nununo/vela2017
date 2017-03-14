#ifndef TRACELAYER_H_INCLUDED
#define TRACELAYER_H_INCLUDED

#include "ofMain.h"
#include "Arduino.h"

class TraceLayer {

  public:
    void setup(Arduino *_arduino);
    void update();
    void draw();

  private:
    ofTrueTypeFont font;
    Arduino *arduino;
};

#endif // TRACELAYER_H_INCLUDED
