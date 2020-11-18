// Slave side
// LED lights here

#include<Wire.h>;
int led = 12;

void setup()
{
  Wire.begin(4);    // begin the library on channel "4"
  					// this number is decided in the master's code
  Wire.onReceive(recvHandler);   // this method is called when slave's
  								 // channel receives data
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
   delay(100); 
}

void recvHandler(int h)
{
  int x = Wire.read();  // read the value sent
  Serial.println(x);
  digitalWrite(led, (x==1)?HIGH:LOW);
}

/* 
*  Slave starts , and wait for data to come from master
*  and handles the events using the appropriate handler
*
*/