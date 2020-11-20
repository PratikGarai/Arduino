#include<Wire.h>

int s;
void setup()
{
  Wire.begin();
}

void loop()
{
  Wire.beginTransmission(4);
  s = analogRead(A0);        
  Wire.write(s);
  Wire.endTransmission();
  delay(100);
}