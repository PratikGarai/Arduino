#include<Wire.h>
int x =0;
void setup()
{
  Wire.begin(4);
  Wire.onReceive(recvHandler); 
  pinMode(13, OUTPUT);
  pinMode(2, INPUT);
}

void loop()
{
  Wire.beginTransmission(4);
  x = digitalRead(2);
  Wire.write(x);
  Wire.endTransmission();
  delay(100);
}

void recvHandler(int h)
{
  int x = Wire.read();
  Serial.println(x);
  digitalWrite(13, (x==1)?HIGH:LOW);
}