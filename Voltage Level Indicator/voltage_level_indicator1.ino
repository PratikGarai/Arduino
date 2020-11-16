int leds[] = {2,3,4,5,6};
int low=0,high=0,val;

void setup()
{
  for(int i=0;i<5;i++)
  {
    pinMode(leds[i],OUTPUT);
  }
  Serial.begin(9600);
}

void loop()
{
  val = analogRead(0);
  val = map(val, 0, 716, 0, 5);
  Serial.println(val);
  for(int i=0;i<val;i++)
  {
    digitalWrite(leds[i], HIGH);
  }
  for(int i=val;i<5;i++)
  {
    digitalWrite(leds[i], LOW);
  }
}