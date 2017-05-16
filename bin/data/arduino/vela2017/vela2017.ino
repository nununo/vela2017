int lastValue;
int count;

//--------------------------------------------
void setup(){
  Serial.begin(9600);  
  lastValue = 0;
  count = 0;
  analogReference(INTERNAL);
}

//--------------------------------------------
void loop(){
  int value;
  
  value = runningAverage(analogRead(A0));

  if (count > 100) {
    sendValue(value);
    count = 0;
      //Serial.flush();
  }

  //wait a little bit so we don't send too much data
  delay(1);

  count++;
}

//--------------------------------------------
long runningAverage(int M) {
  #define LM_SIZE 16
  static int LM[LM_SIZE];
  static byte index = 0;
  static long sum = 0;
  static byte count = 0;

  sum -= LM[index];
  LM[index] = M;
  sum += LM[index];
  index++;
  index = index % LM_SIZE;
  if (count < LM_SIZE) count++;

  return sum / count;
}

//--------------------------------------------
void sendValue(int value) {
  
  //we split the 0 - 1023 number into two bytes so we are sending a message of a known length
  unsigned char byte1;
  unsigned char byte2;
  
  //gnarly code to turn the int into two bytes
  byte1 = value &0xFF;
  byte2 = (value >> 8) &0xFF;

  Serial.print(' ');
  Serial.write(byte1);
  Serial.write(byte2);
}
