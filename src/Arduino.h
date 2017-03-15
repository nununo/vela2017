#ifndef ARDUINO_H_INCLUDED
#define ARDUINO_H_INCLUDED

#include "ofMain.h"

#define ARDUINO_BUFFER_SIZE 500
#define ARDUINO_CALIBRATION_COUNT 20

class Arduino {

  public:
    bool setup(int device, int _threshold1, int _threshold2, int _threshold3, int _threshold4, bool _autocalibrate);
    void update();
    int getLastValue() {return lastValue;}
    int getOffset() {return offset;}
    int getBuffer(int index) {return buffer[index];}
    void setAutocalibrate(bool value) {bAutocalibrate = value;}
    void toggleAutocalibrate() {bAutocalibrate = !bAutocalibrate;}
    void offsetOffset(int diff);
    bool calibrate1();
    bool calibrate2();

  private:
    ofSerial serial;
    int lastValue;
    int offset;
    int maxValue; // limit beyond which values are ignored, to avoid strange values
    int buffer[ARDUINO_BUFFER_SIZE];
    int bufferCursor;
    bool bAutocalibrate;

    void calibrate();
    void setValue(int value);
    //int getIntensity(int value);
};

#endif // ARDUINO_H_INCLUDED
