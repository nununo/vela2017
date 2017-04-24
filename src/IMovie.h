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
  virtual void draw(float x, float y, float width, float height, int alpha) = 0;
  virtual void setPaused(bool pause=true) = 0;
  virtual bool isPaused() = 0;
};

#endif /* IMovie_h */
