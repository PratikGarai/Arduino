#include<Servo.h>

Servo servo;
int val = 0;
void setup()
{
  servo.attach(3);
  for(int i=0;i<=90;i++)
  {
    servo.write(i);
    delay(10);
  }
  val = 90;
}

void loop()
{
  int a = analogRead(A0);
  int b = analogRead(A1);
  if(a<b && val>0)
    val--;
  else if (b<a && val<180)
    val++;
  servo.write(val);
  delay(20);
}