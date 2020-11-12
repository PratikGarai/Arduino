void setup()
{
  analogWrite(6,0);
}

void loop()
{
  analogWrite(6,0);
  delay(1000);
  analogWrite(6,128);
  delay(1000);
  analogWrite(6,255);
  delay(1000);
}