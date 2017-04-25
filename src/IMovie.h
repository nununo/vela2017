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

#define ALPHA_MAX 255

class IMovie {
public:
  virtual string getFilename() = 0;
  virtual bool isFinished() = 0;
  virtual float getPosition() = 0;
  virtual float getDuration() = 0;
  virtual void rewind() = 0;
  virtual void update() = 0;
  virtual void draw(float x, float y, float width, float height) = 0;
  virtual void setPaused(bool pause=true) = 0;
  virtual void setAlpha(int _alpha) {alpha=_alpha;}
  virtual bool isPaused() = 0;
  
protected:
  int getAlpha() {return alpha;}
  
private:
  int alpha;
};

#endif /* IMovie_h */
