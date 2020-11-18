// Master Side
// Button pressed here 

#include<Wire.h>
int push = 2;
int x = 0;

void setup()
{ 
  Wire.begin();   // begin the library
  pinMode(push, INPUT);
  Serial.begin(9600);
}

void loop()
{
  Wire.beginTransmission(4);    // begin transmission on channel 4
  x = digitalRead(push);
  Wire.write(x);  				// write the data
  Serial.println(x);
  Wire.endTransmission();  		// end the transmission
  delay(500);
}

/*
* Master is responsible for beginning, writing and ending
* transmission.
*
*/