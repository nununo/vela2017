//
//  IMovie.h
//  vela2017
//
//  Created by Nuno on 24/04/2017.
//
//

#ifndef IMovie_h
#define IMovie_h

#include "ofMain.h"
#include "ITrace.h"

#define ALPHA_MAX 255

class MovieBase : public ITrace {
public:
  bool isFinished();
  void rewind();
  void setAlpha(int _alpha) {alpha=_alpha;}
  int getAlpha() {return alpha;}

  virtual string getFilename() = 0;
  virtual float getPosition() = 0;
  virtual float getDuration() = 0;
  virtual void update() = 0;
  virtual void draw(float x, float y, float width, float height) = 0;
  virtual void setPaused(bool pause=true) = 0;
  virtual bool isPaused() = 0;
  virtual bool getLoop() = 0;
  
  // ITrace
  string getTrace();

private:
  virtual void rewindAux() = 0;
  
  int alpha;
  float timeOutMoment = 0;
};

#endif /* IMovie_h */
