#include<Servo.h>
Servo servo;

void setup()
{
  servo.attach(3);
}

void loop()
{
  for(int i=0;i<180;i++)
  {
    servo.write(i);
    delay(50);
  }
  for(int i=180;i>=0;i--)
  {
    servo.write(i);
    delay(50);
  }
}