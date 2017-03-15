#include "Arduino.h"
#include "Util.h"
#include <algorithm>

//--------------------------------------------------------------
bool Arduino::setup(int device, int threshold1, int threshold2, int threshold3, int _maxValue, bool _autocalibrate) {
  offset = 0;
  maxValue = _maxValue;
  bAutocalibrate = _autocalibrate;
  lastValue = 0;
  serial.listDevices();
  return serial.setup(device, 9600);
  bufferCursor = 0;
  for(int i=0; i<ARDUINO_BUFFER_SIZE; i++)
    buffer[i] = threshold1;
}

//--------------------------------------------------------------
void Arduino::update() {

	// we try to read 2 bytes

	//clear our variables
	int nTimesRead  = 0;
	int nBytesRead  = 0;
	int nRead		= 0;  // a temp variable to keep count per read

	//we are going to read a 0 - 1024 number as two bytes
	//we need a buffer to store the two bytes and a second
	//buffer with space for the terminating zero byte
	unsigned char bytesReturned[2];
	unsigned char bytesReadString[3];

	//clear our buffers
	memset(bytesReadString, 0, 3);
	memset(bytesReturned, 0, 2);

	//we read as much as possible so we make sure we get the newest data
	while( (nRead = serial.readBytes( bytesReturned, 2)) > 0){
		nTimesRead++;
		nBytesRead = nRead;
	}

	//if we have got both bytes
	if( nBytesRead == 2){

		//lets update our buffer
		memcpy(bytesReadString, bytesReturned, 2);

		//we need to put the bytes back into an int and then remap it to a float
		int value = ( (unsigned char)bytesReadString[1] << 8 | (unsigned char)bytesReadString[0] );

    setValue(value);
	}
}

//--------------------------------------------------------------
 void Arduino::setValue(int value) {
  if (value > maxValue)
    return;
  lastValue = value;
  // Save value in buffer
  buffer[bufferCursor] = value;
  // Incremente buffer cursor
  if (++bufferCursor == ARDUINO_BUFFER_SIZE) {
    bufferCursor = 0;
    if (bAutocalibrate)
      calibrate();
  }
}

//--------------------------------------------------------------
void Arduino::offsetOffset(int diff) {
  offset += diff;
  cout << "Offsettting offset by " << diff << " to " << offset << endl;
}

//--------------------------------------------------------------
void Arduino::calibrate() {
  cout << "Calibrating...";
  if (!calibrate1())
    calibrate2();
}

//--------------------------------------------------------------
bool Arduino::calibrate1() {
//  int count = 0;
//  for(int i=ARDUINO_BUFFER_SIZE-1; i>=0; i--)
//    if (getIntensity(buffer[i])>0)
//      count++;
//  if (count > ARDUINO_CALIBRATION_COUNT) {
//    offsetOffset(1);
//    cout << " lowering sensibility by 1. movements=" << count << endl;
//  }
}

//--------------------------------------------------------------
bool Arduino::calibrate2() {
  // Sort buffer in ascending order
  sort(buffer, buffer+ARDUINO_BUFFER_SIZE);
  // get max value
  int maxValue = buffer[ARDUINO_BUFFER_SIZE-1];
  // Go from bigger to smaller values but only the biggest value is relevant so when
  // we find a new one we stop counting
  int count = 0;
  for(int i=ARDUINO_BUFFER_SIZE-1; i>=0; i--) {
    // If a new value is found then
    if (buffer[i] != maxValue)
      break;
    count++;
  }

  cout << " max=" << maxValue << " count=" << count;

  if (count > ARDUINO_CALIBRATION_COUNT) {
    // Calculate difference between
    int diffCalibration = maxValue - offset + 1;
    offsetOffset(diffCalibration);
    cout << " adjusting sentibility." << " diff=" << diffCalibration << endl;
  } else {
    cout << " unstable: nothing done." << endl;
  }
}
